#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

template <typename T>
class Array
{
public:

	Array();
	Array(int length, int start_index = 0);
	Array(const Array<T> & copy);
	~Array();
	Array<T> & operator=(const Array<T> & rhs);
	T & operator[](int index);
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength() const;
	void setLength(int length);

private:
	T * m_array;
	int m_length;
	int m_start_index;

};

template <typename T>
Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0)
{
}

template <typename T>
Array<T>::Array(int length, int start_index = 0) : m_array(nullptr), m_length(length), m_start_index(start_index)
{
	if (m_length < 0)
		throw Exception("Cannot Create Array Smaller Than Size 0");
	else if (m_length != 0)
		m_array = new T[m_length];
}

template <typename T>
Array<T>::Array(const Array<T> & copy) : m_length(copy.m_length), m_array(nullptr), m_start_index(copy.m_start_index)
{
	if (m_length != 0)
	{
		m_array = new T[m_length];
		for (int i(0); i < m_length; ++i)
			m_array[i] = copy.m_array[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
	if (this != &rhs)
	{
		m_length = rhs.m_length;
		m_start_index = rhs.m_start_index;
		delete[] m_array;
		if (m_length != 0)
		{
			m_array = new T[m_length];
			for (int i(0); i < m_length; ++i)
				m_array[i] = rhs.m_array[i];
		}
		else
			m_array = nullptr;
		
	}
	return *this;
}

template <typename T>
T & Array<T>::operator[](int index)
{
	if (m_length == 0)
		throw Exception("Cannot Access Empty Array");
	if (index < m_start_index)
		throw Exception("Cannot Access Index Smaller Than The Lower Bounds.");
	if (index > m_start_index + m_length - 1)
		throw Exception("Cannot Access Index Larger Than The Upper Bounds.");
	return m_array[index - m_start_index];
}

template <typename T>
int Array<T>::getStartIndex() const
{
	return m_start_index;
}

template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
int Array<T>::getLength() const
{
	return m_length;
}

template <typename T>
void Array<T>::setLength(int length)
{
	if (length < 0)
		throw Exception("Cannot Create Array Smaller Than Size 0");
	if (length != 0)
	{
		T * temp = new T[length];
		for (int i(0); i < m_length && i < length; ++i)
			temp[i] = m_array[i];
		delete[] m_array;
		m_array = temp;
	}
	if (length == 0 && m_length != 0)
	{
		delete[] m_array;
		m_array = nullptr;
	}
	m_length = length;
}

#endif