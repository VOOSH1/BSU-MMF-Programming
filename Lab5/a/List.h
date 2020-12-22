#include "Node.h"
#include <iostream>

class List
{
private:
	Node* head;
	int n;
	void deleteList(Node*);
	Node* find(const int) const;
public:
	~List();
	List();
	List(const List&);
	List& operator =(const List&);
	bool isEmpty() const;
	int getSize() const;
	void insert(const double&, int);
	void remove(const int);
	double retrieve(const int) const;
	double& operator[](const int);
	const double& operator[](const int) const;
	friend std::istream& operator >>(std::istream&, List&);
	friend std::ostream& operator <<(std::ostream&, const List&);
};