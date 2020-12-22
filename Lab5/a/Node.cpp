#include "Node.h"

Node::~Node()
{}

Node::Node()
{
	data = 0;
	next = nullptr;
}

Node::Node(const Node& node)
{
	data = node.data;
	next = node.next;
}

double& Node::getData()
{
	return data;
}

Node* Node::getNext() const
{
	return next;
}

void Node::setData(const double& newData)
{
	data = newData;
}

void Node::setNext(Node* newNext)
{
	next = newNext;
}

Node& Node::operator =(const Node& node)
{
	if (this == &node)
		return *this;
	data = node.data;
	next = node.next;
	return *this;
}