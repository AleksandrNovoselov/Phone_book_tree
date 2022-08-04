#include <iostream>
#include<string>
#include<fstream>
#include "Tree.h"
using namespace std;

void doWork(Tree& listAbonent);
string file = "file.txt";

int main()
{
	setlocale(0, "");
	Tree listAbonent;
	listAbonent.readFile(file);
	
	cout << ">>> Добро пожаловать <<<\n";
	cout << ">> количество повторов? <<\n";

	int replay;
	cin >> replay;

	for (int i = 0; i < replay; i++)
	{
		doWork(listAbonent);

	}
	listAbonent.writeFile(file);

	return 0;
}

void doWork(Tree& listAbonent)
{
	int choice;
	cout << "> Что будем делать? <\n"
		<< "1 – добавить абонента\n"
		<< "2 – удалить абонента\n"
		<< "3 – поиск абонента по фамилии\n"
		<< "4 – поиск абонента по номеру телефона\n"
		<< "5 – показать всех\n"
		<< "6 – показать в диапазоне\n";
		

	cin >> choice;
	switch (choice)
	{
	case 1:
		listAbonent.addAbonent();
		break;
	case 2:
		listAbonent.delAbonent();
		break;
	case 3:
		listAbonent.findAbonFam();
		break;
	case 4:
		listAbonent.findAbonPhone();
		break;
	case 5:
		listAbonent.printAll();
		break;
	case 6:
		listAbonent.printRange();
		break;
	default:
		cout << "Неверный ввод\n";
		break;
	}
}




