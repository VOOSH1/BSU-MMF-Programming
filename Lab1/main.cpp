#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    string name;
    string manuf;
    int price;
    int term;
    int quant;
public:
    ~Product();
    Product();
    Product(string, string, int, int, int);
    void set(string, string, int, int, int);
    string get_name();
    void print();
    int get_price();
    int get_term();
};

Product::~Product()
{

}
Product::Product() : name{ "" }, manuf{ "" }, price{ 0 }, term{ 0 }, quant{ 0 }
{

}

Product::Product(string name1, string manuf1, int price1, int term1, int quant1)
{
    name = name1;
    manuf = manuf1;
    price = price1;
    term = term1;
    quant = quant1;
}

void Product::set(string name1, string manuf1, int price1, int term1, int quant1)
{
    name = name1;
    manuf = manuf1;
    price = price1;
    term = term1;
    quant = quant1;
}
string Product::get_name()
{
    return name;
}
void Product::print()
{
    cout << "Имя - " << name << ", производство - " << manuf << ", цена - " << price << ", срок хранения " << term << ", количество - " << quant;
}
int Product::get_price()
{
    return price;
}
int Product::get_term()
{
    return term;
}

int main()
{
    ifstream fin("input.txt");
    setlocale(LC_ALL, "rus");
    int n;
    fin >> n;
    string name;
    string manuf;
    int price;
    int time;
    int quant;
    Product* pr = new Product[n];
    for (int i = 0; i < n; i++)
    {
        fin >> name;
        fin >> manuf;
        fin >> price;
        fin >> time;
        fin >> quant;
        pr[i].set(name, manuf, price, time, quant);
    }
    string new_name;
    int new_price;
    int new_term;
    int a;
    bool flag = true;
    while (flag)
    {
        cout << "Нажмите 1, для вывода списка товаров для заданного наименования" << endl;
        cout << "Нажмите 2, для вывода списка товаров для заданного наименования, цена которых не превышает указанной" << endl;
        cout << "Нажмите 3, для вывода списка товаров срок хранения которых больше заданного" << endl;
        cout << "Нажмите любую другую клавишу, для выхода из программы" << endl;
        cin >> a;
        switch (a)
        {
            case 1:
                cout << "Список товаров для заданного наименования: " << endl;
                cout << "Введите наименование: ";
                cin >> new_name;
                for (int i = 0; i < n; i++)
                {
                    if (pr[i].get_name() == new_name)
                    {
                        pr[i].print();
                        cout << endl;
                    }
                }
                break;
            case 2:
                cout << "Список товаров для заданного наименования, цена которых не превышает указанной: " << endl;
                cout << "Введите наименование: ";
                cin >> new_name;
                cout << "Введите цену: ";
                cin >> new_price;
                for (int i = 0; i < n; i++)
                {
                    if (pr[i].get_name() == new_name && pr[i].get_price() <= new_price)
                    {
                        pr[i].print();
                        cout << endl;
                    }
                }
                break;
            case 3:
                cout << "Список товаров срок хранения которых больше заданного: " << endl;
                cout << "Введите срок хранения: ";
                cin >> new_term;
                for (int i = 0; i < n; i++)
                {
                    if (pr[i].get_term() > new_term)
                    {
                        pr[i].print();
                        cout << endl;
                    }
                }
                break;
            default:
                flag = false;
                break;
        }
    }
    delete[] pr;
    system("pause");
    return 0;
}