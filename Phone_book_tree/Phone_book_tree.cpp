#include <iostream>
#include <map>
#include<string>
#include<fstream>

#include <sstream>
using namespace std;

void readFile(map <string, int>& listAbonent);
void addAbonent(map <string, int>& listAbonent);
void delAbonent(map <string, int>& listAbonent);
void findAbonFam(map <string, int>& listAbonent);
void findAbonPhone(map <string, int>& listAbonent);
void printAll(map <string, int>& listAbonent);
void printRange(map <string, int>& listAbonent);
void writeFile(map <string, int>& listAbonent, string file);
void saveAs(map <string, int>& listAbonent);
void doWork(map<string, int> &listAbonent);

string file="file.txt";


int main()
{
	setlocale(0, "");
	map <string, int> listAbonent; //сюда будут записываться абоненты из файла

	readFile(listAbonent); //прочитать данные из файла, записать в listAbonent
	
	cout << ">>> Добро пожаловать <<<\n";
	cout << ">> количество повторов? <<\n";

	int replay;
	cin >> replay;

	for (int i = 0; i < replay; i++)
	{
		doWork(listAbonent);
	}
	writeFile(listAbonent, file);

	return 0;
}

void doWork(map<string, int>& listAbonent)
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
		addAbonent(listAbonent);
		break;
	case 2:
		delAbonent(listAbonent);
		break;
	case 3:
		findAbonFam(listAbonent);
		break;
	case 4:
		findAbonPhone(listAbonent);
		break;
	case 5:
		printAll(listAbonent);
		break;
	case 6:
		printRange(listAbonent);
		break;
	default:
		cout << "Неверный ввод\n";
		break;
	}
}

void readFile(map <string, int>& listAbonent) {
	auto stream = fstream(file, ios_base::in);
	if (stream.is_open())
	{
		auto delimetr = ';';
		string line;
		while (getline(stream, line))
		{
			stringstream streamLine(line);
			string name;
			string tmpNumber;
			int numberPhone;
			getline(streamLine, name, delimetr);
			getline(streamLine, tmpNumber, delimetr);
			numberPhone = stoi(tmpNumber);

			listAbonent.insert(make_pair(name, numberPhone));
		}
	}
	stream.close();
}

void addAbonent(map <string, int>& listAbonent)
{
	string name;
	int numberPhone;
	cout << "Введите имя: ";
	getline(cin,name);
	getline(cin, name);
	cout << "Введите номер телефона: ";
	cin >> numberPhone;
	listAbonent.insert(make_pair(name, numberPhone));
}

void  delAbonent(map <string, int>& listAbonent)
{
	string name;
	cout << "Введите имя удаляемого абонента: ";
	getline(cin, name);
	getline(cin, name);
	auto it = listAbonent.find(name);

	if (it == listAbonent.end())
		cout << "Абонент не найден";
	else
	{
		cout << name << " удален";
		listAbonent.erase(it);
	}
}

void findAbonFam(map <string, int>& listAbonent) {
	string name;
	cout << "Введите имя для поиска: ";
	getline(cin, name);
	getline(cin, name);
	auto it = listAbonent.find(name);
	if (it != listAbonent.end()) 
	{
		cout << it->first << ":" << it->second << endl;
		map <string, int> listAbonentSave;
		listAbonentSave.insert(make_pair(it->first, it->second));
		saveAs(listAbonentSave);

	}
	else
		cout << "Абонент не найден";
	
}

void findAbonPhone(map <string, int>& listAbonent) {
	map <int, string> listAbonentNew;
	for (auto item = listAbonent.begin(); item != listAbonent.end(); item++)
	{
		listAbonentNew.insert(make_pair(item->second, item->first));
	}
	int phone;
	cout << "Введите номер телефона для поиска: ";
	cin >> phone;
	auto it = listAbonentNew.find(phone);
	if (it != listAbonentNew.end())
	{
		cout << it->second << " : " << it->first << endl;

		map <string, int> listAbonentSave;
		listAbonentSave.insert(make_pair(it->second, it->first));

		saveAs(listAbonentSave);
	}
	else
		cout << "Абонент не найден";
}

void printAll(map <string, int>& listAbonent)
{
	for (auto item = listAbonent.begin(); item != listAbonent.end(); item++)
	{
		cout << item->first << " : " << item->second << endl;
	}
}

void printRange(map <string, int>& listAbonent)
{
	cout << "Введите начало диапазона: ";
	string name;
	getline(cin, name);
	getline(cin, name);

	cout << "Введите конец диапазона: ";
	string nameEnd;
	getline(cin, nameEnd);

	map <string, int> listAbonentSave;

	for (auto item = listAbonent.find(name); item != ++listAbonent.find(nameEnd); item++)
	{
		cout << item->first << " : " << item->second << endl;

		listAbonentSave.insert(make_pair(item->first, item->second));
	}
	saveAs(listAbonentSave);
}

void writeFile(map <string, int>& listAbonent,string file)
{
	auto stream = fstream(file, ios_base::out);
	if (stream.is_open()) {
		for (auto item = listAbonent.begin(); item != listAbonent.end(); item++)
		{
			stream << item->first << ";" << item->second << endl;
		}
	}
	stream.close();
}

void saveAs(map <string, int>& listAbonent)
{
	cout << "Сохранить найденные данные в новый файл ? \n y - Да n - Нет\n";
	char save;
	
	cin >> save;
	if (save == 'y')
	{
		writeFile(listAbonent, "find.txt");
		cout << "Данные сохранены в файле find.txt\n";
	}
}


