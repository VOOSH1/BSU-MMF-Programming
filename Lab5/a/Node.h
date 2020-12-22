class Node
{
private:
	double data;
	Node* next;
public:
	~Node();
	Node();
	Node(const Node&);
	double& getData();
	Node* getNext() const;
	void setData(const double&);
	void setNext(Node*);
	Node& operator =(const Node&);
};