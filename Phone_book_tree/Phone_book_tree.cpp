#include <iostream>
#include <map>
#include<string>
#include<fstream>
#include <vector>
#include <sstream>
using namespace std;

//struct Node
//{
//	int data{ 0 };
//	Node* left{ nullptr }, * right{ nullptr };
//	Node(int data) :data{ data } {}
//
//};
//
//Node* CreateNode(int data)
//{
//	return new Node(data);
//}
//
//class Tree
//{
//	Node* _root{ nullptr };
//public:
//	void Add(int data)
//	{
//		Node* current = _root;
//		Node* prevNode = nullptr;
//		if (_root == nullptr)
//		{
//			_root = CreateNode(data);
//			return;
//		}
//		while (current != nullptr)
//		{
//			prevNode = current;
//
//			if (data > current->data)
//				current = current->right;
//			else
//				current = current->left;
//		}
//		if (data > prevNode->data)
//			prevNode->right = CreateNode(data);
//		else
//			prevNode->left = CreateNode(data);
//	}
//	void Print()
//	{
//		Print(_root);
//	}
//	void Print(Node* node)
//	{
//		if (node == nullptr)return;
//
//		Print(node->right);
//		cout << node->data << endl;
//		Print(node->left);
//
//	}
//};
string file{"file.txt"};

struct Abonent {
	string name;
	int numberPhone;
};

Abonent CreatureAbonent(string name, int numPhone)
{
	return Abonent{ name, numPhone };
}

void createAbonents(std::vector<Abonent>& abonents)
{
	string name;
	string tmpNumber;
	int numberPhone;
	while (true)
	{
		cout << "Enter name:\n";
		getline(cin, name);

		if (name.length() == 0)
			break;

		cout << "Enter number phone:\n";
		getline(cin, tmpNumber);

		numberPhone = stoi(tmpNumber);

		auto abonent = CreatureAbonent(name, numberPhone);
		abonents.push_back(abonent);
	}

}


void readFile()
{
	auto stream = fstream(file, ios_base::in | ios_base::app);
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
			cout << "name: " << name;

			getline(streamLine, tmpNumber, delimetr);
			numberPhone = stoi(tmpNumber);
			cout << ", phone" << numberPhone;
		}
	}
	stream.close();
}

void writeFile()
{
	auto stream = fstream(file, ios_base::out);

	if (stream.is_open())
	{
		string line;
		while (true)
		{
			cout << "Enter:\n";
			getline(cin, line);

			if (line.length() == 0)
				break;
			//line.append("\n");   вариан добавления пустой строки
			stream << line << endl;
		}
	}
	stream.close();
}

int main()
{
	setlocale(0, "");

	//map<string, int> list;
	//cout << "Введите количество элементов";
	//int count = 0;
	//cin >> count;
	//for(int i=0; i<count;i++)
	//{
	//	createAbonents()
	//}


	//list.insert(pair<int, int>(1, 10));
	//list.insert(make_pair(2, 5));

	//for (auto item = list.begin(); item != list.end(); item++)
	//{
	//	cout << item->first << ":" << item->second << endl;
	//}

	//inn (read) out(write) app(add)
	
	readFile();

	


	//readFile();
	vector <Abonent> abonentList;
	auto stream = fstream(file, ios_base::out);

	createAbonents(abonentList);

	if (stream.is_open())
	{
		for (auto& abonent : abonentList)//for-each
		{
			stream << abonent.name << " ; " << abonent.numberPhone << endl;
		}
	}

	stream.close();

	writeFile();

	return 0;
}
