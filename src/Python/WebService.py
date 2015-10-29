from PIL import Image
#import time
import os

PIPE_DIR  = "src/SharedData/"
PIPE_NAME = "main_pipe"

def open_and_write_pipe(ImageFile):	
	fd = open(os.path.join(PIPE_DIR, PIPE_NAME), "w+b")
	im = Image.open(os.path.join(PIPE_DIR, ImageFile))
	fd.truncate()
	pixels = im.load()
	print >> fd, im.size[0],im.size[1]
	for j in range(im.size[1]):
		for i in range(im.size[0]):
			r,g,b = pixels[i,j]
			print >> fd, r,g,b

def read_and_output(File):
	with open(os.path.join(PIPE_DIR, File), "rb") as f:
		lines = f.readlines()
		dimens = lines[0].split()
		width = int(dimens[0])
		height = int(dimens[1])
		img = Image.new( 'RGB', (width,height), "black") # create a new black image
		pixels = img.load() # create the pixel map
		for i in range (0, len(lines) - 1):
			colors = lines[i + 1].split()
			r = int(colors[0])
			g = int(colors[1])
			b = int(colors[2])
			pixels[i % width, i / width] = (r,g,b)
					
		img.save(PIPE_DIR + "out.png")

# open_and_write_pipe("cballs.png")
read_and_output("new_img")
