#include <iostream>
using namespace std;

int main() {
	setlocale(0," ");
M1:
	cout << "\n" << "\n" << "(для полного завершения программы нажмите 4)" << "\n" << "Введите номер задания : ";
	int numberOfTask;
	cin >> numberOfTask;
	while (numberOfTask) {
		switch (numberOfTask)
		{
		case 1:
			int a;
			cout << "Введите тип данных, где:\n 1 - int\n 2 - short int\n 3 - long int\n 4 - float\n 5 - double\n 6 - long double\n 7 - char\n 8 - bool" << endl;
			cout << "Для выбора другого задания нажмите 9" << endl;
			cin >> a;
			while (a) {
				switch (a)
				{
				case 1: cout << "int занимает " << sizeof(int) << " байта" << endl; break;
				case 2: cout << "short int занимает " << sizeof(short int) << " байта" << endl; break;
				case 3: cout << "long int занимает " << sizeof(long long int) << " байт" << endl; break;
				case 4: cout << "float занимает " << sizeof(float) << " байта" << endl; break;
				case 5: cout << "double занимает " << sizeof(double) << " байт" << endl; break;
				case 6: cout << "long double занимает " << sizeof(long double) << " байт" << endl; break;
				case 7: cout << "char занимает " << sizeof(char) << " байт" << endl; break;
				case 8: cout << "bool занимает " << sizeof(bool) << " байт" << endl; break;
				case 9: cout << "Программа завершила свою работу" << endl; goto M1;
				default: cout << "Введено неверное значение" << endl; break;
				}
				cin >> a;

			};
			break;
		case 2:
			cout << "Введите число от -2 147 483 648 до 2 147 483 647: ";
			int value1,cnt1,bitShiftInt;
			cin >> value1;
			cout << "Введите на сколько байтов влево хотите сдвинуть: ";
			cin >> bitShiftInt;
			unsigned int order,mask;
			order = sizeof(value1) * 8;
			mask = 1 << order - 1 - bitShiftInt;
			cnt1 = 0;
			for (int i = 1; i <= order; i++)
			{
				if (i % order - 1 == 0) {
					if ((value1 & mask) == 0) {
						cout << "\x1b[33m0\x1b[0m";
					}
					else {
						cout << "\x1b[33m1\x1b[0m";
					}
					putchar(' ');
				}
				else {
					if (((mask & value1) == 0) && (cnt1 == 0)) {
						putchar(value1 & mask ? '1' : '0');
					}
					else {
						cnt1 += 1;
						if ((mask & value1) == 0) {
							cout << "\x1b[31m0\x1b[0m";
						}
						else {
							cout << "\x1b[31m1\x1b[0m";
						}
					}
				}
				value1 <<= 1;
				if (i % 8 == 0)
				{
					putchar(' ');
				}
			};
			goto M1;
			break;
		case 3:
			cout << "Введите число, отделив целую часть от дробной точкой: ";
			union {
				float value2;
				int valueInt;
			};
			cin >> value2;
			int bitShiftF,cnt2;
			cout << "Введите на сколько байтов влево хотите сдвинуть: ";
			cin >> bitShiftF;
			unsigned int orderSecond, mask2;
			orderSecond = sizeof(value2) * 8;
			mask2 = 1 << orderSecond - 1 - bitShiftF;
			cnt2 = 0;
			for (int i = 1; i <= orderSecond; i++)
			{
				if (i % orderSecond - 1 == 0) {
					if ((valueInt & mask2) == 0) {
						cout << "\x1b[33m0\x1b[0m";
					}
					else {
						cout << "\x1b[33m1\x1b[0m";
					}
					putchar(' ');
				}
				else {
					putchar(mask2 & valueInt ? '1' : '0');
				}
				valueInt <<= 1;
				if (i == 9) {
					putchar(' ');
				}
				if (i > 9) {
					if (i % 8 == 0) {
						putchar(' ');
					}
					else if (i % 16 == 0) {
						putchar(' ');
					}
				}
			}
			goto M1;
			break;
		case 4:
			cout << "Программа завершена!";
			return 0;
		default:
			cout << "Вы ввели неверный номер задания, попробуйте ещё раз";
			goto M1;
		}
	}
}