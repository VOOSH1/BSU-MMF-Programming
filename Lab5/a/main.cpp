#include <iostream>
#include <clocale>
#include "Ring.h"
#include "Field.h"
#include "Polynomial.h"
#include "ModularArithmetic.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Кольцо целых чисел" << endl << endl;
	Ring<int> r1, r2;
	cout << "Введите первое число: ";
	cin >> r1;
	cout << "Введите второе число: ";
	cin >> r2;
	cout << r1 << " + " << r2 << " = " << (r1 + r2) << endl;
	cout << r1 << " - " << r2 << " = " << (r1 - r2) << endl;
	cout << r1 << " * " << r2 << " = " << (r1 * r2) << endl;
	cout << endl;
	cout << "Кольцо многочленов" << endl << endl;
	Ring<Polynomial> r11, r22;
	cout << "Введите число n, равное максимальной степени первого многочлена + 1" << endl;
	cout << "А затем введите коэффиценты первого многочлена в порядке возрастания степеней" << endl;
	cin >> r11;
	cout << "Введите число n, равное максимальной степени второго многочлена + 1" << endl;
	cout << "А затем введите коэффиценты второго многочлена в порядке возрастания степеней" << endl;
	cin >> r22;
	cout << r11 << " + " << r22 << " = " << (r11 + r22) << endl;
	cout << r11 << " - " << r22 << " = " << (r11 - r22) << endl;
	cout << r22 << " * " << r22 << " = " << (r11 * r22) << endl;
	cout << endl;
	cout << "Кольцо системы классов целых чисел, сравнимых по модулю" << endl << endl;
	int mod;
	cout << "Введите модуль: ";
	cin >> mod;
	if (mod < 1)
		mod = 1;
	Ring<ModularArithmetic> r111, r222;
	r111.data.setModule(mod);
	r222.data.setModule(mod);
	cout << "Введите первый элемент: ";
	cin >> r111;
	cout << "Введите второй элемень: ";
	cin >> r222;
	cout << r111 << " + " << r222 << " = " << (r111 + r222) << endl;
	cout << r111 << " - " << r222 << " = " << (r111 - r222) << endl;
	cout << r111 << " * " << r222 << " = " << (r111 * r222) << endl;
	cout << endl;
	cout << "Поле рациональны чисел" << endl << endl;
	Field <double> f1, f2;
	cout << "Введите первое число: ";
	cin >> f1;
	cout << "Введите второе число: ";
	cin >> f2;
	cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
	cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
	cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
	cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;
	cout << endl;
	system("pause");
	return 0;
}