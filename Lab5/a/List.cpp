#include "List.h"

void List::deleteList(Node* node)
{
	if (node->getNext() != nullptr)
	{
		deleteList(node->getNext());
	}
	delete node;
}

Node* List::find(const int index) const
{
	Node* tmp = head;
	int i = 0;
	while (i < index)
	{
		tmp = tmp->getNext();
		i++;
	}
	return tmp;
}

List::~List()
{
	if (head != nullptr)
	{
		deleteList(head);
	}
}

List::List()
{
	head = nullptr;
	n = 0;
}

List::List(const List& list)
{
	n = list.n;
	Node* tmp{ list.head };
	Node* now{ nullptr };
	Node* start{ nullptr };
	while (tmp != nullptr)
	{
		if (now == nullptr)
		{
			now = new Node;
		}
		now->setData(tmp->getData());
		if (tmp->getNext() != nullptr)
		{
			now->setNext(new Node);
		}
		else
		{
			now->setNext(nullptr);
		}
		if (start == nullptr)
		{
			start = now;
		}
		tmp = tmp->getNext();
		if (now->getNext() != nullptr)
		{
			now = now->getNext();
		}
	}
	head = start;
}

List& List::operator=(const List& list)
{
	if (this == &list)
	{
		return *this;
	}
	if (head != nullptr)
	{
		deleteList(head);
	}
	n = list.n;
	Node* tmp{ list.head };
	Node* now{ nullptr };
	Node* start{ nullptr };
	while (tmp != nullptr)
	{
		if (now == nullptr)
		{
			now = new Node;
		}
		now->setData(tmp->getData());
		if (tmp->getNext() != nullptr)
		{
			now->setNext(new Node);
		}
		else
		{
			now->setNext(nullptr);
		}
		if (start == nullptr)
		{
			start = now;
		}
		tmp = tmp->getNext();
		if (now->getNext() != nullptr)
		{
			now = now->getNext();
		}
	}
	head = start;
	return *this;
}

bool List::isEmpty() const
{
	return (n == 0);
}

int List::getSize() const
{
	return n;
}

void List::insert(const double& data, int index)
{
	if ((index < 0) || (index > n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return;
	}
	Node* newNode = new Node;
	newNode->setData(data);
	if (index == 0)
	{
		newNode->setNext(head);
		head = newNode;
	}
	else
	{
		Node* tmp = find(index - 1);
		newNode->setNext(tmp->getNext());
		tmp->setNext(newNode);
	}
	n++;
}

void List::remove(const int index)
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return;
	}
	Node* tmp;
	if (index == 0)
	{
		tmp = head->getNext();
		delete head;
		head = tmp;
	}
	else
	{
		Node* prev = find(index - 1);
		tmp = prev->getNext();
		prev->setNext(tmp->getNext());
		delete tmp;
	}
	n--;
}

double List::retrieve(const int index) const
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return 0;
	}
	return find(index)->getData();
}

double& List::operator[](const int index)
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return *(new double);
	}
	return find(index)->getData();
}

const double& List::operator[](const int index) const
{
	if ((index < 0) || (index >= n))
	{
		std::cout << "Ошибка! Некорректное значение индекса" << std::endl;
		return *(new double);
	}
	return find(index)->getData();
}

std::istream& operator>>(std::istream& sstream, List& list)
{
	int n;
	sstream >> n;
	if (n < 0)
	{
		std::cout << "Ошибка! Некорректное значение, объекту оставлено прежнее значение" << std::endl;
		return sstream;
	}
	if (list.head != nullptr)
	{
		list.deleteList(list.head);
	}
	list.n = 0;
	list.head = nullptr;
	Node* now = nullptr;
	double tmp;
	for (int i = 0; i < n; i++)
	{
		sstream >> tmp;
		if (i == 0)
		{
			now = new Node;
			now->setData(tmp);
			list.head = now;
			list.n++;
			continue;
		}
		now->setNext(new Node);
		now = now->getNext();
		now->setData(tmp);
		list.n++;
	}
	return sstream;
}

std::ostream& operator<<(std::ostream& sstream, const List& list)
{
	Node* now = list.head;
	while (now != nullptr)
	{
		sstream << now->getData() << " ";
		now = now->getNext();
	}
	return sstream;
}