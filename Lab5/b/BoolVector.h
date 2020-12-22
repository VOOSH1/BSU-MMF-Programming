#include "Vector.h"

class BoolVector : public Vector
{
public:
	~BoolVector();
	BoolVector();
	BoolVector(int*, const int);
	BoolVector(const BoolVector&);
	BoolVector& operator =(const BoolVector&);
	BoolVector operator &(const BoolVector&) const;
	BoolVector& operator &=(const BoolVector&);
	BoolVector operator |(const BoolVector&) const;
	BoolVector& operator |=(const BoolVector&);
	BoolVector operator ^(const BoolVector&) const;
	BoolVector& operator ^=(const BoolVector&);
	BoolVector operator ~() const;
	int getCountOf1() const;
	int getPosOfLeft1() const;
	friend std::ostream& operator <<(std::ostream&, const BoolVector&);
	friend std::istream& operator >>(std::istream&, BoolVector&);
};