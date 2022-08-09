#pragma once
#include <map>
#include<string>
using namespace std;

class Tree
{
	map <string, int> _listAbonent;
public:
	Tree(){}
	void readFile(string file);
	void addAbonent();
	void delAbonent();
	void findAbonFam();
	void findAbonPhone();
	void printAll();
	void printRange();
	void writeFile(string file);
	static void writeFile(map<string, int>& listAbonentSave, string file);
	void saveAs(map<string, int>& listAbonentSave);
};

