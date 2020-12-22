#include <iostream>
#include <clocale>
#include "BoolVector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	BoolVector vec1, vec2;
	int n;
	do
	{
		cout << "Введите размерность пространства: ";
		cin >> n;
		if (n <= 0)
		{
			cout << "Ошибка! Введите положительное число" << endl;
			continue;
		}
		break;
	} while (true);
	vec1.setN(n);
	vec2.setN(n);
	cout << "Введите первый булевый вектор: ";
	cin >> vec1;
	cout << "Введите второй булевый вектор: ";
	cin >> vec2;
	cout << endl << endl;
	cout << "Первый булевый вектор: " << vec1 << endl;
	cout << "Второй булевый вектор: " << vec2 << endl;
	cout << endl << endl;
	cout << "Оперция & : " << (vec1 & vec2) << endl;
	cout << "Оперция | : " << (vec1 | vec2) << endl;
	cout << "Оперция ^ : " << (vec1 ^ vec2) << endl;
	cout << "Оперция ~ для первого вектора : " << ~vec1 << endl;
	cout << "Оперция ~ для второго вектора : " << ~vec2 << endl;
	cout << "Количетсво координат, принимающих значение 1, в первом векторе: " << vec1.getCountOf1() << endl;
	cout << "Количетсво координат, принимающих значение 1, во втором векторе: " << vec2.getCountOf1() << endl;
	cout << "Индекс самой левой единицы в первом векторе: " << vec1.getPosOfLeft1() << endl;
	cout << "Индекс самой левой единицы во втором векторе: " << vec2.getPosOfLeft1() << endl;
	vec1 = vec2;
	cout << "Новое значение первого вектора: " << vec1 << endl;
	system("pause");
	return 0;
}