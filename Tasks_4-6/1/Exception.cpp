#include "Exception.h"

Exception::~Exception()
{
}

Exception::Exception(const std::string& newMsg) : msg( newMsg )
{
}

const char* Exception::what() const
{
	return msg.c_str();
}