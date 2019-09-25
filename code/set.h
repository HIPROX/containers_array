#pragma once
#include "array.h"
#include <iostream>
#include <algorithm>

class Set
{
public:
// Typedefs
	typedef unsigned int UINT;
	typedef Array::value_type		value_type;
	typedef Array::iterator			iterator;
	typedef Array::const_iterator	const_iterator;
// Constructors & Destructor
	Set(UINT size) throw(std::bad_alloc);
	Set(const_iterator, const_iterator)
		throw(std::bad_alloc, std::invalid_argument);
	Set(const Set&) throw(std::bad_alloc);
	~Set(void) throw();
// Operators
	value_type& operator[](UINT) throw(std::range_error);
	Set& operator=(const Set&);
	friend std::istream& operator>>(std::istream&, Set&);
	friend std::ostream& operator<<(std::ostream&, const Set&);
// Methods
	void insert(const value_type&);
	UINT capacity(void) const;
	UINT size(void) const;
	void erase(const value_type &item);
	bool isContain(const value_type&) const;
	bool isContain(const Set&);
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
	friend Set association(const Set&, const Set&);
	friend Set intersection(const Set&, const Set&);
	friend Set difference(const Set&, const Set&);
private:
	Array data;
	UINT count_elements;
	void sort(void); // sort elements of set
};