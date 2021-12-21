#include <random>
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;
int f(int low, int high)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(low, high);

	return dis(gen);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	ofstream file;
	file.open("C:\\Users\\Lyx\\Desktop\\Проекты\\random\\log.txt", ios::app);
	SYSTEMTIME st;
	GetLocalTime(&st);// инициализ времени
	file << "The program was launched in " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
	int a,z;
	cout << "Введите max значение: " << endl;
	//проверка на ввод числа
		cin >> a;
		if (cin.get() != (int)'\n'|| a<0) {
			cout << "error" << endl;
			file << "The user entered an incorrect value " << endl;
			return 0;
		}
	file << "User entered value: " << a << endl;
	cout << "Случайные числа: " << endl;
	_getch();
	vector <int> v(a);
	file << "The program brought: ";
	for (int i = 0; i < a; i++) {
		v[i] = i + 1;
	}
	for (int i = 0; i < v.size(); i) {
		z = f(1, v.size());
		cout << v[z - 1] << endl;
		file << v[z - 1] << ", ";
		v.erase(v.begin() + z - 1);
		_getch();
	}
	GetLocalTime(&st);
	file << endl << "The program ended in: " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << endl;
}
