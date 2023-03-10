#include <iostream>
#include <fstream>
#include "windows.h"
#include <string>  
using namespace std;
int SizeofFile();
void create();
void show();
void change();
void ch();
void add();
void insolve();
void delt();
int LengthOfName(int);
struct inf {
	char name[50];
	int group;
	int birth;
	int est[4];
	double fest;
} arr[100];
int index = 0;
ofstream file;
ifstream file1;
int main()
{
	setlocale(LC_ALL, "ru");
	bool again = false;
	Sleep(1000);
	do {
		int choose;
		cout << "1.Создать/Открыть файл.\n2.Просмотр.\n3.Коррекция.\n4.Решение индивидуального задания.\n5.Удалить файл.\n6.Завершить программу" << endl;
		cin >> choose;
		while (choose < 1 || choose>6) {
			cout << "\nТакой операции не существует!Повторите ввод!\n";
			Sleep(500);
			system("cls");
			cout << "1.Создать/Открыть файл.\n2.Просмотр.\n3.Коррекция.\n4.Решение индивидуального задания.\n5.Удалить файл.\n6.Завершить программу" << endl;
			cin >> choose;
		}
		switch (choose)
		{
		case 1:
			create();
			break;
		case 2:
			show();
			break;
		case 3:
			change();
			break;
		case 4:
			insolve();

			break;
		case 5:
			delt();
			break;


		case 6:
			again = true;
			break;
		}
	} while (again == false);
	file.close();
	file1.close();
	return 0;
}
void delt() {
	file.close();
	remove("text.txt");
	cout << "Файл успешно удален\n";

	Sleep(1000);
	system("cls");
}
void insolve() {
	if (!file.is_open()) {
		cout << "СНАЧАЛА СОЗДАЙТЕ или ОТКРОЙТЕ ФАЙЛ!\n";
		Sleep(1000);
		system("cls");
		return;
	}
	if (SizeofFile() == 0) {
		cout << "Файл пустой!" << endl;
		file1.close();
		Sleep(500);
		system("cls");
		return;
	}
	system("cls");
	file1.open("text.txt");
	int i = 0, in = 0, size = 0;
	while (!file1.eof()) {
		file1 >> arr[i].name;
		size = LengthOfName(i) + 1;
		if (size == 1) {
			break;
		}
		arr[i].name[size - 1] = ' ';
		for (int j = 0; j < 4; j++) {
			file1 >> arr[i].name[size];
			size++;
		}
		file1 >> arr[i].birth;
		file1 >> arr[i].group;
		for (int j = 0; j < 4; j++) {
			file1 >> arr[i].est[j];
		}
		file1 >> arr[i].fest;
		i++;
	}
	int newi = 0;
	index = i;
	cout << "Список студентов,имеющих оценки по математике и информатике 4 и выше:" << endl;
	while (newi != i) {
		if (arr[newi].est[1] >= 4 && arr[newi].est[2] >= 4) {
			cout << arr[newi].name << " ";
			cout << arr[newi].birth << " ";
			cout << arr[newi].group;
			cout << "\tОценки по предметам: ";
			for (int j = 0; j < 4; j++) {
				cout << arr[newi].est[j] << " ";
			}
			cout << "\tСредний балл: ";
			cout << arr[newi].fest << endl;
		}
		newi++;
	}
	file1.close();
	cout << endl << endl;
	cout << "0.Назад" << endl;
	cin >> in;
	system("cls");
}
void change() {
	int choice = -1;
	do {
		if (!file.is_open()) {
			cout << "СНАЧАЛА СОЗДАЙТЕ или ОТКРОЙТЕ ФАЙЛ!\n";
			Sleep(1000);
			system("cls");
			return;
		}
		system("cls");
		cout << "1.Изменить.\n2.Добавить.\n3.Назад." << endl;
		cin >> choice;
		while (choice < 1 || choice>3) {
			cout << "\nТакой операции не существует!Повторите ввод!\n";
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
			ch();
			break;
		case 2:
			add();
			break;
		case 3:
			Sleep(500);
			system("cls");
			return;
			break;
		}
	} while (choice != 3);
}
void ch() {
	if (!file.is_open()) {
		cout << "СНАЧАЛА СОЗДАЙТЕ или ОТКРОЙТЕ ФАЙЛ!\n";

		Sleep(1000);
		system("cls");
		return;
	}
	if (SizeofFile() == 0) {
		cout << "Файл пустой!" << endl;
		file1.close();
		Sleep(500);
		system("cls");
		return;
	}
	system("cls");
	file1.open("text.txt");
	int i = 0, in = 0, size = 0;
	while (!file1.eof()) {
		file1 >> arr[i].name;
		size = LengthOfName(i) + 1;
		if (size == 1) {
			break;
		}
		arr[i].name[size - 1] = ' ';
		for (int j = 0; j < 4; j++) {
			file1 >> arr[i].name[size];
			size++;
		}
		file1 >> arr[i].birth;
		file1 >> arr[i].group;
		for (int j = 0; j < 4; j++) {
			file1 >> arr[i].est[j];
		}
		file1 >> arr[i].fest;
		i++;
	}
	int newi = 0;
	index = i;
	while (newi != i) {
		cout << newi << ".";
		cout << arr[newi].name << " ";
		cout << arr[newi].birth << " ";
		cout << arr[newi].group;
		cout << "\tОценки по предметам: ";
		for (int j = 0; j < 4; j++) {
			cout << arr[newi].est[j] << " ";
		}
		cout << "\tСредний балл: ";
		cout << arr[newi].fest << endl;
		newi++;
	}
	file1.close();
	file.close();
	remove("text.txt");
	file.open("text.txt", fstream::app);
	char  str[10];
	int est = 0, ind = 0;
	string vvod;
	cout << "Введите номер строки,которую нужно изменить:";
	cin >> ind;
	arr[ind].fest = 0;
	cout << "Введите фамилию и инициалы:" << endl;
	gets_s(str);
	gets_s(arr[ind].name);
	cout << "Введите год рождения:" << endl;
	cin >> arr[ind].birth;
	cout << "Введите номер группы:" << endl;
	cin >> arr[ind].group;
	cout << "Введите оценки по физике, математике, информатике, химии: " << endl;
	for (int i = 0; i < 4; i++) {
		cin >> vvod;
		while ((vvod < "0" && vvod>"10") || (vvod >= "A" && vvod <= "Z" || vvod >= "a" && vvod <= "z")) {
			cout << "Введите число!" << endl;
			cin >> vvod;
		}
		est = stoi(vvod);
		arr[ind].est[i] = est;
		arr[ind].fest += arr[ind].est[i] / 4.0;
	}
	for (int i = 0; i < index; i++) {
		file << arr[i].name << " ";
		file << arr[i].birth << " ";
		file << arr[i].group << "\t";
		for (int j = 0; j < 4; j++) {
			file << arr[i].est[j] << " ";

		}
		file << "\t";
		file << arr[i].fest << endl;
	}
	file.close();
	file.open("text.txt", fstream::app);
}
void add() {
	system("cls");
	arr[index].fest = 0;
	char  str[10];
	int est = 0;
	string vvod;
	cout << "Введите фамилию и инициалы:" << endl;
	gets_s(str);
	gets_s(arr[index].name);
	cout << "Введите год рождения:" << endl;
	cin >> arr[index].birth;
	cout << "Введите номер группы:" << endl;
	cin >> arr[index].group;
	cout << "Введите оценки по физике, математике, информатике, химии соответственно: " << endl;
	for (int i = 0; i < 4; i++) {
		cin >> vvod;
		while ((vvod < "0" && vvod>"10") || (vvod >= "A" && vvod <= "Z" || vvod >= "a" && vvod <= "z")) {
			cout << "Введите число!" << endl;
			cin >> vvod;
		}
		est = stoi(vvod);
		arr[index].est[i] = est;
		arr[index].fest += arr[index].est[i] / 4.0;
	}

	file << arr[index].name << " ";
	file << arr[index].birth << " ";
	file << arr[index].group << "\t";
	for (int i = 0; i < 4; i++) {
		file << arr[index].est[i] << " ";

	}
	file << "\t";
	file << arr[index].fest << endl;
	file.close();
	file.open("text.txt", fstream::app);
	index++;
	return;
}
void show() {
	if (!file.is_open()) {
		cout << "СНАЧАЛА СОЗДАЙТЕ или ОТКРОЙТЕ ФАЙЛ!\n";

		Sleep(1000);
		system("cls");
		return;
	}
	if (SizeofFile() == 0) {
		cout << "Файл пустой!" << endl;
		file1.close();
		Sleep(500);
		system("cls");
		return;
	}
	system("cls");
	file1.open("text.txt");
	int i = 0, in = 0, size = 0;
	while (!file1.eof()) {
		file1 >> arr[i].name;
		size = LengthOfName(i) + 1;
		if (size == 1) {
			break;
		}
		arr[i].name[size - 1] = ' ';
		for (int j = 0; j < 4; j++) {
			file1 >> arr[i].name[size];
			size++;
		}
		arr[i].name[size] = '\0';
		file1 >> arr[i].birth;
		file1 >> arr[i].group;
		for (int j = 0; j < 4; j++) {
			file1 >> arr[i].est[j];
		}
		file1 >> arr[i].fest;
		i++;
	}
	int newi = 0;
	index = i;
	while (newi != i) {
		cout << arr[newi].name << " ";
		cout << arr[newi].birth << " ";
		cout << arr[newi].group;
		cout << "\tОценки по предметам: ";
		for (int j = 0; j < 4; j++) {
			cout << arr[newi].est[j] << " ";
		}
		cout << "\tСредний балл: ";
		cout << arr[newi].fest << endl;
		newi++;
	}
	file1.close();
	cout << endl << endl;
	cout << "0.Назад" << endl;
	cin >> in;
	system("cls");
}
void create() {
	file.open("text.txt", fstream::app);
	if (!file.is_open()) {
		cout << "Ошибка!\n";

	}
	else {
		cout << "Файл успешно создан/открыт." << endl;
	}
	Sleep(500);
	system("cls");
}
int SizeofFile() {
	file1.open("text.txt");
	file1.seekg(0, std::ios::end);
	int size = file1.tellg();
	file1.close();
	return size;
}
int LengthOfName(int ind) {
	int length = 0;
	length = strlen(arr[ind].name);
	return length;
}