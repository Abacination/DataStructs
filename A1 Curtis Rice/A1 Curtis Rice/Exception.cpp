#include "Exception.h"


Exception::Exception():m_msg(nullptr)
{
}

Exception::Exception(char * msg):m_msg(nullptr)
{
	if (msg != nullptr)
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy_s(m_msg, strlen(msg) + 1, msg);	
	}
}

Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}

Exception::Exception(const Exception & copy):m_msg(nullptr)
{
	if (copy.m_msg != nullptr)
	{
		m_msg = new char[strlen(copy.m_msg) + 1];
		strcpy_s(m_msg, strlen(copy.m_msg) + 1, copy.m_msg);
	}
}

Exception & Exception::operator=(const Exception & rhs)
{
	if(this != &rhs)
		setMessage(rhs.m_msg);
	return *this;
}

const char * Exception::getMessage() const
{
	return m_msg;
}

void Exception::setMessage(const char * msg)
{
	delete[] m_msg;
	if(msg != nullptr)
	{
		m_msg = new char[strlen(msg) + 1];
		strcpy_s(m_msg, strlen(msg) + 1, msg);
	}
	else
		m_msg = nullptr;
}

std::ostream & operator<<(std::ostream & stream, const Exception & except)
{
	if (except.m_msg != nullptr)
		return stream << except.m_msg;
	else
		return stream;
}