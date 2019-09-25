#pragma once
#include <iostream>
#include <stdexcept>

class Array
{
public:
// Typedefs
	typedef double	value_type;
	typedef unsigned int	UINT;
	typedef value_type*	iterator;
	typedef const value_type*	const_iterator;
// Constructors & Destructor
	Array(UINT, value_type = 0.0) throw(std::bad_alloc);
	Array(const value_type*, const value_type*)
		throw(std::bad_alloc, std::invalid_argument);
	Array(const Array&) throw(std::bad_alloc);
	~Array(void) throw();
	Array& operator=(const Array&);
// Operatos
	value_type& operator[](UINT) throw(std::range_error);
	const value_type& operator[](UINT) const throw(std::range_error);
// Methods
	UINT size(void) const;
// Iterators
	iterator begin(void);
	iterator end(void);
	iterator begin(void) const;
	iterator end(void) const;
	const_iterator cbegin(void);
	const_iterator cend(void);
	const_iterator cbegin(void) const;
	const_iterator cend(void) const;
// Friends
	friend std::ostream& operator<<(std::ostream&, const Array&);
	friend std::istream& operator>>(std::istream&, Array&);
private:
	UINT size_array;
	value_type *data;
	void Swap(Array&);
};