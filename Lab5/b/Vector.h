#include <iostream>

class Vector
{
protected:
	int n;
	int* coords;
public:
	~Vector();
	Vector();
	Vector(int*, const int);
	Vector(const Vector&);
	void setN(const int);
	int getN() const;
	int* getCoords() const;
	Vector& operator =(const Vector&);
	int operator [](const int) const;
	friend std::ostream& operator <<(std::ostream&, const Vector&);
	friend std::istream& operator >>(std::istream&, Vector&);
};