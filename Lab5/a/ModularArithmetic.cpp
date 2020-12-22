#include "ModularArithmetic.h"

ModularArithmetic::~ModularArithmetic()
{
}

ModularArithmetic::ModularArithmetic()
{
	this->number = 0;
	this->module = 1;
}

ModularArithmetic::ModularArithmetic(const ModularArithmetic& ma)
{
	this->number = ma.number;
	this->module = ma.module;
}

void ModularArithmetic::setModule(int mod)
{
	this->module = mod;
}

ModularArithmetic& ModularArithmetic::operator=(const ModularArithmetic& ma)
{
	if (this == &ma)
		return *this;
	this->number = ma.number;
	this->module = ma.module;
	return *this;
}

ModularArithmetic ModularArithmetic::operator+(const ModularArithmetic& ma) const
{
	ModularArithmetic ans(*this);
	ans.number = this->number + ma.number;
	ans.number %= this->module;
	return ans;
}

ModularArithmetic& ModularArithmetic::operator+=(const ModularArithmetic& ma)
{
	*this = *this + ma;
	return *this;
}

ModularArithmetic ModularArithmetic::operator-(const ModularArithmetic& ma) const
{
	ModularArithmetic ans(*this);
	if (this->number >= ma.number)
	{
		ans.number = this->number - ma.number;
		ans.number %= this->module;
	}
	return ans;
}

ModularArithmetic& ModularArithmetic::operator-=(const ModularArithmetic& ma)
{
	*this = *this - ma;
	return *this;
}

ModularArithmetic ModularArithmetic::operator*(const ModularArithmetic& ma) const
{
	ModularArithmetic ans(*this);
	ans.number = this->number * ma.number;
	ans.number %= this->module;
	return ans;
}

ModularArithmetic& ModularArithmetic::operator*=(const ModularArithmetic& ma)
{
	*this = *this * ma;
	return *this;
}

std::ostream& operator<<(std::ostream& sstream, const ModularArithmetic& ma)
{
	sstream << ma.number;
	return sstream;
}

std::istream& operator>>(std::istream& sstream, ModularArithmetic& ma)
{
	sstream >> ma.number;
	ma.number = std::abs(ma.number);
	return sstream;
}
