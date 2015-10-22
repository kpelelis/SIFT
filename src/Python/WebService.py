from PIL import Image
import time
import mmap

PIPE_DIR  = "../SharedData/"
PIPE_NAME = "main_pipe"

def open_and_write_pipe(ImageFile):	
	fd = open(PIPE_DIR + PIPE_NAME, "r+b")
	fd.truncate()
	im = Image.open(ImageFile)
	pixels = im.load()
	print >> fd, im.size[0],im.size[1]
	for i in range(im.size[0]):
		for j in range(im.size[1]):
				r,g,b = pixels[i,j]
				print >> fd, r,g,b
				
open_and_write_pipe("../SharedData/7.jpg")

