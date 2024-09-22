#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
	T*      _array;
	size_t  _size;

public:
	Array();

	Array(unsigned int n);

	Array(const Array& other);

	Array& operator=(const Array& other);

	~Array();

	T& operator[](size_t index);

	const T& operator[](size_t index) const;

	size_t size() const;

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Index out of bounds";
		}
	};
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	// '()' after new T[n] ensure value-initialization of elements
}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] _array;
		_size = other._size;
		if (_size > 0)
		{
			_array = new T[_size];
			for (size_t i = 0; i < _size; ++i)
			{
				_array[i] = other._array[i];
			}
		}
		else
		{
			_array = NULL;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
size_t Array<T>::size() const
{
	return _size;
}

#endif
