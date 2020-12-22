#pragma once
#include "Set.h"

template <class T>
class Ring : public Set<T>
{
public:
	virtual ~Ring();
	Ring();
	Ring(const T&);
	Ring(const Ring<T>&);
	Ring<T>& operator=(const Ring<T>&);
	Ring<T>& operator+=(const Ring<T>&);
	Ring<T> operator+(const Ring<T>&) const;
	Ring<T>& operator-=(const Ring<T>&);
	Ring<T> operator-(const Ring<T>&) const;
	Ring<T>& operator*=(const Ring<T>&);
	Ring<T> operator*(const Ring<T>&) const;
	template<class P>
	friend std::ostream& operator<<(std::ostream&, const Ring<P>&);
	template<class P>
	friend std::istream& operator>>(std::istream&, Ring<P>&);
	virtual void show();
};

#include "Ring.inl"
