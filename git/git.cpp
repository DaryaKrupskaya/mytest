#include <iostream>
#include <fstream>


typedef  union telefony
{
	char fio[16];
	char tel[9];
} FT;
int num;
using namespace std;

void Outpt()
{
	system("chcp 1251");
	ifstream otf("d:/adel/c++/Tel.DAT");
	cout << "\nФамилия    Телефон\n";
	while (!otf.eof())
	{
		FT buf = { ' ' };
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.fio << "\t    ";
		otf.read((char *)&buf, sizeof(buf));
		cout << buf.tel << endl;
	}
	cout << endl;
}
void Inpt()
{
	system("chcp 1251");
	ofstream itf;
	itf.open("d:/adel/c++/Tel.DAT", ios_base::app);
	FT buf = { ' ' };
	for (int p = 0; p < num; p++)
	{
		cout << "Фамилия: ";	cin >> buf.fio;
		itf.write((char *)&buf, sizeof(buf));
		cout << "Телефон: ";
		cin >> buf.tel;
		itf.write((char *)&buf, sizeof(buf));
	}
}
void Poisk()
{
	ifstream otf("d:/adel/c++/Tel.DAT");
	int i = 0; char fam[16];
	FT buf = { ' ' };
	cout << "Введите фамилию: "; cin >> fam;
	while (!otf.eof())
	{
		otf.read((char *)&buf, sizeof(buf));
		if (strcmp(fam, buf.fio) == 0)  //сравнение 
		{
			cout << "\nФамилия    Телефон\n";
			cout << buf.fio << "\t    ";
			otf.read((char *)&buf, sizeof(buf));
			cout << buf.tel << endl;
			i = 1; break;
		}
	}
	if (i == 0)
		cout << "Ничего не найдено\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");  int c;
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по фамилии\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> c;
		switch (c)
		{
		case 1: cout << "Введите количество  ";
			cin >> num;
			Inpt();  break;
		case 2: Outpt(); break;
		case 3: Poisk(); break;
		case 0: exit(0);  break;
		}
	} while (c != 0);
}
