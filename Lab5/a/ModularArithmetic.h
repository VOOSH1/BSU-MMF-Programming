#include "iostream"

class ModularArithmetic
{
private:
	int number;
	int module;
public:
	~ModularArithmetic();
	ModularArithmetic();
	ModularArithmetic(const ModularArithmetic&);
	void setModule(int);
	ModularArithmetic& operator=(const ModularArithmetic&);
	ModularArithmetic operator+(const ModularArithmetic&) const;
	ModularArithmetic& operator+=(const ModularArithmetic&);
	ModularArithmetic operator-(const ModularArithmetic&) const;
	ModularArithmetic& operator-=(const ModularArithmetic&);
	ModularArithmetic operator*(const ModularArithmetic&) const;
	ModularArithmetic& operator*=(const ModularArithmetic&);
	friend std::ostream& operator<<(std::ostream&, const ModularArithmetic&);
	friend std::istream& operator>>(std::istream&, ModularArithmetic&);
};

