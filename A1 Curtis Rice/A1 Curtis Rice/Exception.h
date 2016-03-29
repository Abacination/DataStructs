#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>

class Exception
{
	friend std::ostream & operator<<(std::ostream & stream, const Exception & except);

public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();

	Exception & operator=(const Exception & rhs);
	const char * getMessage() const;
	void setMessage(const char * msg);

private:
	char * m_msg;
};

#endif

