
#include <iostream>
#include "vector.hpp"

template <class T>
vector<T>::vector()
	: m_capacity(0)
	, m_size(0)
	, m_vector(nullptr)
{
	std::cout << "Default ctor\n";
}

template <class T>
vector<T>::vector(const int size, const T &item)
	: m_capacity(size)
	, m_size(size)
	, m_vector(new T[m_capacity])
{
	std::cout << "Param ctor\n";

	for(int i = 0; i < m_capacity; ++i)
	{
		m_vector[i] = item;
	}
}

template <class T>
vector<T>::vector(const vector<T>& src)
{
	std::cout << "Copy ctor\n";

	m_capacity = src.m_size;
	m_size = src.m_size;
	m_vector = new T[m_capacity];
	for(int i = 0; i < src.m_size; ++i)
	{
		m_vector[i] = src.m_vector[i];
	}
}

template <class T>
vector<T>::vector(vector<T> &&src)
{
	std::cout << "Move ctor\n";

	m_capacity = src.m_capacity;
	m_size = src.m_size;
	m_vector = src.m_vector;
	src.m_vector = nullptr;
	src.m_capacity = 0;
	src.m_size = 0;
}

template <class T>
vector<T>::~vector()
{
	std::cout << "Dtor\n";
	if(m_vector)
	{
		delete[] m_vector;
	}
}


template <class T>
vector<T>& vector<T>::operator=(const vector<T> &src)
{
	std::cout << "Copy assignment\n";

	if(this == &src)
	{
		return *this;
	}

	m_capacity = src.m_size;
	m_size = src.m_size;
	delete m_vector;
	m_vector = new T[src.m_size];
	for(int i = 0; i < src.m_size; ++i)
	{
		m_vector[i] = src.m_vector[i];
	}

	return *this;
}

template <class T>
vector<T>& vector<T>::operator=(vector<T> &&src)
{
	std::cout << "Move assignment\n";
	
	if(this == &src)
	{
		return *this;
	}

	m_capacity = src.m_capacity;
	m_size = src.m_size;
	m_vector = src.m_vector;
	src.m_vector = nullptr;
	src.m_capacity = 0;
	src.m_size = 0;

	return *this;
	
}

template <class T>
void vector<T>::push(const T &item)
{
	if(m_size == m_capacity)
	{
		if(m_capacity == 0)
		{
			m_resize(1);
		}
		else
		{
			m_resize(m_capacity * 2);
		}
	}
	m_vector[m_size++] = item;	
}

template <class T>
void vector<T>::pop()
{
	m_size--;	
}

template <class T>
T& vector<T>::front()
{
	return m_vector[0];
}

template <class T>
T& vector<T>::back()
{
	return m_vector[m_size - 1];
}

template <class T>
bool vector<T>::empty() const
{
	return m_size == 0;
}

template <class T>
int vector<T>::size() const
{
	return m_size;
}

template <class T>
int vector<T>::capacity() const
{
	return m_capacity;
}

template <class T>
T& vector<T>::operator[](const int index)
{
	return m_vector[index];
}

template <class T>
void vector<T>::m_resize(const int newCapacity)
{
	T *newVector = new T[newCapacity];	
	for(int i = 0; i < m_size; ++i)
	{
		newVector[i] = m_vector[i];
	}

	delete[] m_vector;
	m_vector = newVector;
	m_capacity = newCapacity;
}


