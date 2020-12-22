#include <iostream>
#include <fstream>
#include <cmath>
#include <clocale>
#include <string>

using namespace std;

template <class T>
class Node
{
private:
	T data;
	Node<T>* next;
public:
	~Node();
	Node();
	Node(const Node<T>&);
	T getData() const;
	Node<T>* getNext() const;
	void setData(const T);
	void setNext(Node<T>*);
	Node<T>& operator =(const Node<T>&);
};

template<class T>
class List
{
private:
	Node<T>* head;
	int n;
	void deleteList(Node<T>*);
	Node<T>* find(const int) const;
public:
	~List();
	List();
	List(const List&);
	List<T>& operator =(const List<T>&);
	bool isEmpty() const;
	int getSize() const;
	void insert(const int, const T);
	void remove(const int);
	T retrieve(const int) const;
	void sort();
	void print() const;
};

template <class T>
void solve(string file)
{
	List<T> list1, list2, list3;
	ifstream fin(file);
	int n;
	T tmp;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> tmp;
		list1.insert(i, tmp);
	}
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> tmp;
		list2.insert(i, tmp);
	}
	list1.sort();
	list2.sort();
	cout << "Первый список, отсортированный по невозрастанию:" << endl;
	list1.print();
	cout << "Второй список, отсортированный по невозрастанию:" << endl;
	list2.print();
	int index1 = 0, index2 = 0, index3 = 0;
	while ((index1 < list1.getSize()) || (index2 < list2.getSize()))
	{
		if ((index1 < list1.getSize()) && (index2 < list2.getSize()))
		{
			if (list1.retrieve(index1) > list2.retrieve(index2))
			{
				list3.insert(index3, list1.retrieve(index1));
				index3++;
				index1++;
			}
			else
			{
				list3.insert(index3, list2.retrieve(index2));
				index3++;
				index2++;
			}
		}
		else
		{
			if (index1 < list1.getSize())
			{
				list3.insert(index3, list1.retrieve(index1));
				index3++;
				index1++;
			}
			else
			{
				list3.insert(index3, list2.retrieve(index2));
				index3++;
				index2++;
			}
		}
	}
	cout << "Итоговый список:" << endl;
	list3.print();
	fin.close();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int k;
	cout << "1 - int" << endl;
	cout << "2 - double" << endl;
	cout << "3 - char" << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin >> k;
		if ((k <= 0) || (k > 3))
		{
			cout << "Ошибка! Некорректное значение" << endl;
			continue;
		}
		break;
	} while (true);
	cout << endl;
	switch (k)
	{
	case 1:
		solve<int>("input_int.txt");
		break;
	case 2:
		solve<double>("input_double.txt");
		break;
	case 3:
		solve<char>("input_char.txt");
		break;
	}
	system("pause");
	return 0;
}

template <class T>
Node<T>::~Node()
{}

template <class T>
Node<T>::Node()
{
	data = NULL;
	next = nullptr;
}

template <class T>
Node<T>::Node(const Node<T>& node)
{
	data = node.data;
	next = node.next;
}

template <class T>
T Node<T>::getData() const
{
	return data;
}

template <class T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template <class T>
void Node<T>::setData(const T newData)
{
	data = newData;
}

template <class T>
void Node<T>::setNext(Node<T>* newNext)
{
	next = newNext;
}

template <class T>
Node<T>& Node<T>::operator =(const Node<T>& node)
{
	if (this == &node)
		return *this;
	data = node.data;
	next = node.next;
	return *this;
}

template<class T>
void List<T>::deleteList(Node<T>* node)
{
	if (node->getNext() != nullptr)
	{
		deleteList(node->getNext());
	}
	delete node;
}

template<class T>
Node<T>* List<T>::find(const int index) const
{
	Node<T>* tmp = head;
	int i = 0;
	while (i < index)
	{
		tmp = tmp->getNext();
		i++;
	}
	return tmp;
}

template<class T>
List<T>::~List()
{
	if (head != nullptr)
	{
		deleteList(head);
	}
}

template<class T>
List<T>::List()
{
	head = nullptr;
	n = 0;
}

template<class T>
List<T>::List(const List& list)
{
	n = list.n;
	Node<T>* tmp{ list.head };
	Node<T>* now{ nullptr };
	Node<T>* start{ nullptr };
	while (tmp != nullptr)
	{
		if (now == nullptr)
		{
			now = new Node<T>;
		}
		now->setData(tmp->getData());
		if (tmp->getNext() != nullptr)
		{
			now->setNext(new Node<T>);
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

template<class T>
List<T>& List<T>::operator=(const List<T>& list)
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
	Node<T>* tmp{ list.head };
	Node<T>* now{ nullptr };
	Node<T>* start{ nullptr };
	while (tmp != nullptr)
	{
		if (now == nullptr)
		{
			now = new Node<T>;
		}
		now->setData(tmp->getData());
		if (tmp->getNext() != nullptr)
		{
			now->setNext(new Node<T>);
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

template<class T>
bool List<T>::isEmpty() const
{
	return (n == 0);
}

template<class T>
int List<T>::getSize() const
{
	return n;
}

template<class T>
void List<T>::insert(const int index, const T data)
{
	if ((index < 0) || (index > n))
	{
		cout << "Ошибка! Некорректное значение индекса" << endl;
		return;
	}
	Node<T>* newNode = new Node<T>;
	newNode->setData(data);
	if (index == 0)
	{
		newNode->setNext(head);
		head = newNode;
	}
	else
	{
		Node<T>* tmp = find(index - 1);
		newNode->setNext(tmp->getNext());
		tmp->setNext(newNode);
	}
	n++;
}

template<class T>
void List<T>::remove(const int index)
{
	if ((index < 0) || (index >= n))
	{
		cout << "Ошибка! Некорректное значение индекса" << endl;
		return;
	}
	Node<T>* tmp;
	if (index == 0)
	{
		tmp = head->getNext();
		delete head;
		head = tmp;
	}
	else
	{
		Node<T>* prev = find(index - 1);
		tmp = prev->getNext();
		prev->setNext(tmp->getNext());
		delete tmp;
	}
	n--;
}

template<class T>
T List<T>::retrieve(const int index) const
{
	if ((index < 0) || (index >= n))
	{
		cout << "Ошибка! Некорректное значение индекса" << endl;
		return NULL;
	}
	return find(index)->getData();
}

template<class T>
void List<T>::sort()
{
	bool flag;
	Node<T>* now;
	for (int i = 0; i < (n - 1); i++)
	{
		flag = false;
		now = head;
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (now->getData() < now->getNext()->getData())
			{
				T tmp = now->getData();
				now->setData(now->getNext()->getData());
				now->getNext()->setData(tmp);
				flag = true;
			}
			now = now->getNext();
		}
		if (flag == false)
		{
			break;
		}
	}
}

template<class T>
void List<T>::print() const
{
	Node<T>* now = head;
	while (now != nullptr)
	{
		cout << now->getData() << " ";
		now = now->getNext();
	}
	cout << endl;
}