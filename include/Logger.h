#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

class Logger
{
public:
	static Logger * Instance();

	void LOG_MESSAGE(const std::string& msg);
	void LOG_WARNING(const std::string& warn);
	void LOG_ERROR(const std::string& err);
protected:
	Logger() { };
private:
	static Logger * p_instance;
};

#endif