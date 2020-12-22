#pragma once
#include <iostream>

template<class T>
class Set
{
public:
	T data;
	virtual ~Set();
	Set();
	Set(const T&);
	Set(const Set<T>&);
	Set<T>& operator=(const Set<T>&);
	template<class P>
	friend std::ostream& operator<<(std::ostream&, const Set<P>&);
	template<class P>
	friend std::istream& operator>>(std::istream&, Set<P>&);
	virtual void show() = 0;
};

#include "Set.inl"