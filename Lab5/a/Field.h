#pragma once
#include "Ring.h"
template <class T>
class Field : public Ring<T>
{
public:
	virtual ~Field();
	Field();
	Field(const T&);
	Field(const Field<T>&);
	Field<T>& operator=(const Field<T>&);
	Field<T>& operator+=(const Field<T>&);
	Field<T> operator+(const Field<T>&) const;
	Field<T>& operator-=(const Field<T>&);
	Field<T> operator-(const Field<T>&) const;
	Field<T>& operator*=(const Field<T>&);
	Field<T> operator*(const Field<T>&) const;
	Field<T>& operator/=(const Field<T>&);
	Field<T> operator/(const Field<T>&) const;
	template<class P>
	friend std::ostream& operator<<(std::ostream&, const Field<P>&);
	template<class P>
	friend std::istream& operator>>(std::istream&, Field<P>&);
	virtual void show();
};

#include "Field.inl"