#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
template <typename T>
class Array
{
	template <typename T>
	friend std::ostream& operator<< (std::ostream&, const Array<T>&);
	template <typename T>
	friend std::istream& operator>> (std::istream&, Array<T>&);

public:
	explicit Array(int arraySize = 10)
		: size(arraySize > 0 ? arraySize :
			throw std::invalid_argument("Array size must be greater than 0")),
		ptr(new T[size])
	{}
	Array(const Array& arrayToCopy)
		: size(arrayToCopy.size),
		ptr(new int[size])
	{
		for (size_t i = 0; i < size; ++i)
			ptr[i] = arrayToCopy.ptr[i];
	}
	~Array()
	{
		delete[] ptr;
	}

	size_t getSize() const
	{
		return size;
	}

	const Array& operator=(const Array& right)
	{
		if (&right != this)
		{
			if (size != right.size)
			{
				delete[] ptr;
				size = right.size;
				ptr = new int[size];
			}

			for (size_t i = 0; i < size; ++i)
				ptr[i] = right.ptr[i];
		}

		return *this;
	}

	bool operator==(const Array& right) const
	{
		if (size != right.size)
			return false;

		for (size_t i = 0; i < size; ++i)
			if (ptr[i] != right.ptr[i])
				return false;

		return true;
	}


	bool operator!=(const Array& right) const
	{
		return !(*this == right);
	}

	T& operator[](int subscript)
	{
		if (subscript < 0 || subscript >= size)
			throw std::out_of_range("Subscript out of range");

		return ptr[subscript];
	}

	T operator[](int subscript) const
	{
		if (subscript < 0 || subscript >= size)
			throw std::out_of_range("Subscript out of range");

		return ptr[subscript];
	}
private:
	size_t size;
	T* ptr;
};

#endif