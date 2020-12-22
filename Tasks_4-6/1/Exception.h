#pragma once
#include <string>

class Exception : public std::exception
{
private:
	std::string msg;
public:
	~Exception();

	Exception(const std::string&);

	virtual const char* what() const;
};