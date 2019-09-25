#include "set.h"

void Set::sort(void)
{
	std::sort(this->begin(), this->end());
}

Set::Set(UINT size) throw(std::bad_alloc)
	: data{ Array{size} }, count_elements{} {};

Set::Set(const_iterator begin, const_iterator end)
	throw(std::bad_alloc, std::invalid_argument)
	: data{ Array{begin, end} }, count_elements{} {};

Set::Set(const Set &other)
	throw(std::bad_alloc)
	: data{ other.data }, count_elements{ other.count_elements } {};

Set::~Set(void) throw() = default;

Set::value_type& Set::operator[](Set::UINT index)
	throw(std::range_error)
{
	if (index >= this->count_elements)
	{
		throw std::out_of_range("Index out of range!");
	}
	else
	{
		return this->data[index];
	}
}

Set& Set::operator=(const Set &other)
{
	if (this != &other)
	{
		this->data.operator=(other.data);
		this->count_elements = other.count_elements;
	}
	return *this;
}

std::istream& operator>>(std::istream &is, Set &rhs)
{
	operator>>(is, rhs.data);
	Set::iterator ref = std::unique(rhs.begin(), rhs.end());
	rhs.count_elements = static_cast<Set::UINT>(rhs.end() - ref + 1);
	std::for_each(ref, rhs.end(), [](Set::value_type &item) { item = 0.0; });
	rhs.sort();
	return is;
}

std::ostream& operator << (std::ostream &os, const Set &rhs)
{
	for (Set::UINT i{}; i < rhs.count_elements; ++i)
	{
		os << rhs.data[i] << " ";
	}
	return os;
}

Set::iterator Set::begin(void)
{
	return this->data.begin();
}

Set::iterator Set::end(void)
{
	return this->data.begin() + this->count_elements;
}

Set::iterator Set::begin(void) const
{
	return this->data.begin();
}

Set::iterator Set::end(void) const
{
	return this->data.begin() + this->count_elements;
}

Set::const_iterator Set::cbegin(void)
{
	return this->data.begin();
}

Set::const_iterator Set::cend(void)
{
	return this->data.begin() + this->count_elements;
}

Set::const_iterator Set::cbegin(void) const
{
	return this->data.begin();
}

Set::const_iterator Set::cend(void) const
{
	return this->data.begin() + this->count_elements;
}

void Set::insert(const Set::value_type &item)
{
	if (this->count_elements < this->data.size())
	{
		if (std::find(this->cbegin(), this->cend(), item) == this->cend())
		{
			*this->end() = item;
			++count_elements;
		}
		this->sort();
	}
}

void Set::erase(const Set::value_type &item)
{
	if (this->count_elements > 0)
	{
		Set::iterator res = std::find(this->begin(), this->end(), item);
		if (res != this->end())
		{
			std::swap(*res, *(this->end() - 1));
			--count_elements;
			this->sort();
		}
	}
}

bool Set::isContain(const Set::value_type &item) const
{
	return this->cend() != std::find(this->cbegin(), this->cend(), item);
}

bool Set::isContain(const Set &other)
{
	return this->cend() != std::find_first_of(this->cbegin(), this->cend(),
		other.begin(), other.end());
}

Set::UINT Set::capacity(void) const
{
	return this->data.size();
}

Set::UINT Set::size(void) const
{
	return this->count_elements;
}

Set association(const Set &lhs, const Set &rhs)
{
	Set res{ lhs.count_elements + rhs.count_elements };
	for (Set::UINT i{}; i < lhs.count_elements; ++i)
	{
		res.insert(lhs.data[i]);
	}
	for (Set::UINT i{}; i < rhs.count_elements; ++i)
	{
		res.insert(rhs.data[i]);
	}
	return res;
}

Set intersection(const Set &lhs, const Set &rhs)
{
	Set res{ lhs.count_elements + rhs.count_elements };
	for (Set::UINT i{}; i < lhs.count_elements; ++i)
	{
		for (Set::UINT j{}; j < rhs.count_elements; ++j)
		{
			if (lhs.data[i] == rhs.data[j])
			{
				res.insert(lhs.data[i]);
				break;
			}
		}
	}
	return res;
}

Set difference(const Set &lhs, const Set &rhs)
{
	Set res{ lhs.count_elements + rhs.count_elements };
	for (Set::UINT i{}; i < lhs.count_elements; ++i)
	{
		if (!rhs.isContain(lhs.data[i]))
		{
			res.insert(lhs.data[i]);
		}
	}
	return res;
}