#include "Vector.h"
#include <iostream>

Vector::~Vector()
{
	if (this->coords)
	{
		delete[] this->coords;
		this->coords = nullptr;
	}
}

Vector::Vector()
{
	this->n = 0;
	this->coords = nullptr;
}

Vector::Vector(int* coords, const int n)
{
	this->n = n;
	this->coords = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] = coords[i];
	}
}

Vector::Vector(const Vector& vec)
{
	this->n = vec.n;
	this->coords = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] = vec.coords[i];
	}
}

void Vector::setN(const int n)
{
	if (this->coords)
	{
		delete[] this->coords;
		this->coords = nullptr;
	}
	this->n = n;
	this->coords = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] = 0;
	}
}

int Vector::getN() const
{
	return this->n;
}

int* Vector::getCoords() const
{
	return this->coords;
}

Vector& Vector::operator=(const Vector& vec)
{
	if (this == &vec)
	{
		return *this;
	}
	if (this->coords)
	{
		delete[] this->coords;
		this->coords = nullptr;
	}
	this->n = vec.n;
	this->coords = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] = vec.coords[i];
	}
	return *this;
}

int Vector::operator[](const int index) const
{
	if ((index >= 0) && (index < n))
	{
		return this->coords[index];
	}
	std::cout << "Ошибка! Некорректный индекс" << std::endl;
	return 0;
}

std::ostream& operator<<(std::ostream& sstream, const Vector& vec)
{
	sstream << "(";
	for (int i = 0; i < vec.n; i++)
	{
		sstream << vec.coords[i];
		if (i < (vec.n - 1))
		{
			sstream << ", ";
		}
	}
	sstream << ")";
	return sstream;
}

std::istream& operator>>(std::istream& sstream, Vector& vec)
{
	for (int i = 0; i < vec.n; i++)
	{
		sstream >> vec.coords[i];
	}
	return sstream;
}