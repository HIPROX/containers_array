#include "array.h"


Array::Array(UINT size, value_type k)
	throw(std::bad_alloc)
{
	this->size_array = size;
	this->data = new value_type[size_array];
	for (UINT i{}; i < this->size_array; ++i)
	{
		data[i] = k;
	}
}

Array::Array(const value_type *begin, const value_type *end)
	throw(std::bad_alloc, std::invalid_argument)
{
	if (begin < end)
	{
		this->size_array = static_cast<Array::UINT>(end - begin);
		this->data = new value_type[this->size_array];
		for (UINT i{}; i < this->size_array; ++i)
		{
			data[i] = *begin++;
		}
	}
	else
	{
		throw std::invalid_argument("Array::invalid_argument");
	}
}

Array::Array(const Array &other)
	throw(std::bad_alloc)
{
	this->size_array = other.size_array;
	this->data = new value_type[this->size_array];
	for (UINT i{}; i < this->size_array; ++i)
	{
		this->data[i] = other.data[i];
	}
}

Array::~Array(void) throw()
{
	delete[] this->data;
	this->data = nullptr;
}

void Array::Swap(Array &other)
{
	std::swap(this->data, other.data);
	std::swap(this->size_array, other.size_array);
}

Array& Array::operator=(const Array &rhs)
{
	Array temp{ rhs };
	this->Swap(temp);
	return *this;
}

Array::value_type& Array::operator[](UINT index)
	throw(std::range_error)
{
	if (index >= this->size_array)
	{
		throw std::out_of_range("Index out of range!");
	}
	else
	{
		return this->data[index];
	}
}

const Array::value_type& Array::operator[](UINT index)
const throw(std::range_error)
{
	if (index >= this->size_array)
	{
		throw std::out_of_range("Index out of range!");
	}
	else
	{
		return this->data[index];
	}
}

std::ostream& operator<<(std::ostream& os, const Array &rhs)
{
	for (Array::UINT i{}; i < rhs.size_array; ++i)
	{
		os << rhs.data[i] << " ";
	}
	return os;
}

std::istream& operator >> (std::istream& is, Array &rhs)
{
	for (Array::UINT i{}; i < rhs.size_array; ++i)
	{
		is >> rhs.data[i];
	}
	return is;
}

Array::UINT Array::size(void) const
{
	return this->size_array;
}

Array::iterator Array::begin(void)
{
	return this->data;
}

Array::iterator Array::end(void)
{
	return this->data + this->size_array;
}

Array::iterator Array::begin(void) const
{
	return this->data;
}

Array::iterator Array::end(void) const
{
	return this->data + this->size_array;
}

Array::const_iterator Array::cbegin(void)
{
	return this->data;
}

Array::const_iterator Array::cend(void)
{
	return this->data + this->size_array;
}

Array::const_iterator Array::cbegin(void) const
{
	return this->data;
}

Array::const_iterator Array::cend(void) const
{
	return this->data + this->size_array;
}