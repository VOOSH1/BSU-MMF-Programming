#include <iostream>
#include <fstream>
#include <cmath>
#include <clocale>
#include <string>

using namespace std;

class Node
{
private:
    double data;
    Node* next;
public:
    ~Node();
    Node();
    Node(const Node&);
    double getData() const;
    Node* getNext() const;
    void setData(const double);
    void setNext(Node*);
    Node& operator =(const Node&);
};

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
    void insert(const int, const double);
    void remove(const int);
    double retrieve(const int) const;
    void sort();
    void print() const;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    List list1, list2, list3;
    ifstream fin("input.txt");
    int n;
    double tmp;
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
    system("pause");
    return 0;
}

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

double Node::getData() const
{
    return data;
}

Node* Node::getNext() const
{
    return next;
}

void Node::setData(const double newData)
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

void List::insert(const int index, const double data)
{
    if ((index < 0) || (index > n))
    {
        cout << "Ошибка! Некорректное значение индекса" << endl;
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
        cout << "Ошибка! Некорректное значение индекса" << endl;
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
        cout << "Ошибка! Некорректное значение индекса" << endl;
        return 0;
    }
    return find(index)->getData();
}

void List::sort()
{
    bool flag;
    Node* now;
    for (int i = 0; i < (n - 1); i++)
    {
        flag = false;
        now = head;
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (now->getData() < now->getNext()->getData())
            {
                double tmp = now->getData();
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

void List::print() const
{
    Node* now = head;
    while (now != nullptr)
    {
        cout << now->getData() << " ";
        now = now->getNext();
    }
    cout << endl;
}