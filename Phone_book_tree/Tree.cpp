#include "Tree.h"

void Tree::readFile(string file)
{
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

			_listAbonent.insert(make_pair(name, numberPhone));
		}
	}
	stream.close();
}

void Tree::addAbonent()
{
	string name;
	int numberPhone;
	cout << "Введите имя: ";
	getline(cin, name);
	getline(cin, name);
	cout << "Введите номер телефона: ";
	cin >> numberPhone;
	_listAbonent.insert(make_pair(name, numberPhone));
}

void Tree::delAbonent()
{
	string name;
	cout << "Введите имя удаляемого абонента: ";
	getline(cin, name);
	getline(cin, name);
	auto it = _listAbonent.find(name);

	if (it == _listAbonent.end())
		cout << "Абонент не найден\n";
	else
	{
		cout << name << " удален\n";
		_listAbonent.erase(it);
	}
}

void Tree::findAbonFam()
{
	string name;
	cout << "Введите имя для поиска: ";
	getline(cin, name);
	getline(cin, name);
	auto it = _listAbonent.find(name);
	if (it != _listAbonent.end())
	{
		cout << it->first << ":" << it->second << endl;
		map<string, int> listAbonentSave;
		listAbonentSave.insert(make_pair(it->first, it->second));
		saveAs(listAbonentSave);
	}
	else
		cout << "Абонент не найден\n";
}

void Tree::findAbonPhone()
{
	map <int, string> listAbonentNew;
	for (auto item = _listAbonent.begin(); item != _listAbonent.end(); item++)
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
		cout << "Абонент не найден\n";
}

void Tree::printAll()
{
	for (auto item = _listAbonent.begin(); item != _listAbonent.end(); item++)
	{
		cout << item->first << " : " << item->second << endl;
	}
}

void Tree::printRange()
{
	cout << "Введите начало диапазона: ";
	string name;
	getline(cin, name);
	getline(cin, name);

	cout << "Введите конец диапазона: ";
	string nameEnd;
	getline(cin, nameEnd);

	map <string, int> listAbonentSave;

	for (auto item = _listAbonent.find(name); item != ++_listAbonent.find(nameEnd); item++)
	{
		cout << item->first << " : " << item->second << endl;

		listAbonentSave.insert(make_pair(item->first, item->second));
	}
	saveAs(listAbonentSave);
}

void Tree::writeFile(string file)
{
	auto stream = fstream(file, ios_base::out);
	if (stream.is_open()) {
		for (auto item = _listAbonent.begin(); item != _listAbonent.end(); item++)
		{
			stream << item->first << ";" << item->second << endl;
		}
	}
	stream.close();
}
void Tree::writeFile(map<string, int>& listAbonentSave, string file)
{
	auto stream = fstream(file, ios_base::out);
	if (stream.is_open()) {
		for (auto item = listAbonentSave.begin(); item != listAbonentSave.end(); item++)
		{
			stream << item->first << ";" << item->second << endl;
		}
	}
	stream.close();
}

void Tree::saveAs(map<string, int>& listAbonentSave)
{
	cout << "Сохранить найденные данные в новый файл ? \n y - Да n - Нет\n";
	char save;

	cin >> save;
	if (save == 'y')
	{
		writeFile(listAbonentSave, "find.txt");
		cout << "Данные сохранены в файле find.txt\n";
	}
}
