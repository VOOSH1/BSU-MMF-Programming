#include "BoolVector.h"

BoolVector::~BoolVector()
{
}

BoolVector::BoolVector() : Vector()
{
}

BoolVector::BoolVector(int* coords, const int n)
{
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if ((coords[i] < 0) || (coords[i] > 1))
		{
			flag = false;
			break;
		}
	}
	if (flag == true)
	{
		this->n = n;
		this->coords = new int[this->n];
		for (int i = 0; i < this->n; i++)
		{
			this->coords[i] = coords[i];
		}
	}
	else
	{
		std::cout << "Ошибка! Передан некорректный массив, создан пустой вектор" << std::endl;
		this->n = 0;
		this->coords = nullptr;
	}
}

BoolVector::BoolVector(const BoolVector& vec) : Vector(vec)
{
}

BoolVector& BoolVector::operator=(const BoolVector& vec)
{
	Vector::operator=(vec);
	return *this;
}

BoolVector BoolVector::operator&(const BoolVector& vec) const
{
	BoolVector tmp(*this);
	for (int i = 0; i < tmp.n; i++)
	{
		tmp.coords[i] &= vec.coords[i];
	}
	return tmp;
}

BoolVector& BoolVector::operator&=(const BoolVector& vec)
{
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] &= vec.coords[i];
	}
	return *this;
}

BoolVector BoolVector::operator|(const BoolVector& vec) const
{
	BoolVector tmp(*this);
	for (int i = 0; i < tmp.n; i++)
	{
		tmp.coords[i] |= vec.coords[i];
	}
	return tmp;
}

BoolVector& BoolVector::operator|=(const BoolVector& vec)
{
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] |= vec.coords[i];
	}
	return *this;
}

BoolVector BoolVector::operator^(const BoolVector& vec) const
{
	BoolVector tmp(*this);
	for (int i = 0; i < tmp.n; i++)
	{
		tmp.coords[i] ^= vec.coords[i];
	}
	return tmp;
}

BoolVector& BoolVector::operator^=(const BoolVector& vec)
{
	for (int i = 0; i < this->n; i++)
	{
		this->coords[i] ^= vec.coords[i];
	}
	return *this;
}

BoolVector BoolVector::operator~() const
{
	BoolVector tmp(*this);
	for (int i = 0; i < tmp.n; i++)
	{
		if (this->coords[i] == 0)
		{
			tmp.coords[i] = 1;
		}
		else
		{
			tmp.coords[i] = 0;
		}
	}
	return tmp;
}

int BoolVector::getCountOf1() const
{
	int ans = 0;
	for (int i = 0; i < this->n; i++)
	{
		if (this->coords[i] == 1)
		{
			ans++;
		}
	}
	return ans;
}

int BoolVector::getPosOfLeft1() const
{
	int pos = -1;
	for (int i = 0; i < this->n; i++)
	{
		if (this->coords[i] == 1)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

std::ostream& operator<<(std::ostream& sstream, const BoolVector& vec)
{
	sstream << (Vector&)vec;
	return sstream;
}

std::istream& operator>>(std::istream& sstream, BoolVector& vec)
{
	int* tmp = new int[vec.n];
	bool flag = true;
	for (int i = 0; i < vec.n; i++)
	{
		sstream >> tmp[i];
		if ((tmp[i] < 0) || (tmp[i] > 1))
		{
			flag = false;
		}
	}
	if (flag == true)
	{
		for (int i = 0; i < vec.n; i++)
		{
			vec.coords[i] = tmp[i];
		}
	}
	else
	{
		std::cout << "Ошибка! Введены некорректные данные, оставлено прежнее значение" << std::endl;
	}
	if (tmp != nullptr)
	{
		delete[] tmp;
	}
	return sstream;
}