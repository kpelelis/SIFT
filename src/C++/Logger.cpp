#include "Logger.h"
#include <iostream>
Logger * Logger::p_instance = 0;

Logger * Logger::Instance()
{
	if(p_instance == 0)
	{
		p_instance = new Logger();
	}
	return p_instance;
}

void Logger::LOG_MESSAGE(const std::string& msg)
{
	std::cout << msg << '\n';
}

void Logger::LOG_WARNING(const std::string& warn) 
{ 
	LOG_MESSAGE("[WARNING!] " + warn); 
}

void Logger::LOG_ERROR(const std::string& err)
{ 
	LOG_MESSAGE("[ERROR!] " + err); 	
}
