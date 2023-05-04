#include "ShopService.h"
#include<iostream>
#include<fstream>
#include<string>
#include"windows.h"
#include"Employee.h"
#include <regex>
#include <map>
#include <conio.h>
#include"Strings.h"


void ShopService::create_employees(string path_file)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string line;
	char* fName = new char[20];
	char * mName = new char[20];
	char * lName = new char[20];
	int age;
	int position;
	int department;
	int status;
	int ID;

	fstream file(path_file, std::ios_base::in);
	while (!file.eof())
	{
		getline(file, line);
		if (line == "")
			continue;
		sscanf_s(line.data(), "%d %s %s %s %d %d %d %d",&ID, lName, 10, fName,
			10, mName, 20, &age, &position, &department, &status);
		employers.push_back(Employee(ID, lName, fName, mName, age, position, department, (bool)status));	
	}
	file.close();
}

void ShopService::getlastIDEmployees(string path_file)
{
	fstream file(path_file, ios_base::in);
	string line;
	char name[20];
	int ID;
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, line);
			auto tmp = line.find("LastEmployerID");
			if (line.find("LastEmployerID") == 0)
			{
				sscanf_s(line.data(), "%s %d", name, 20, &ID);
				Employee::IDs = ID;
			}
		}
	}
}
std::map<string, string> ShopService::configPath{ {"Employers", "Employers.txt"},{"Goods", "Goods.txt"},{"IDs", "LastID.txt"} };
ShopService::ShopService(string _nameOrganization)
{
	shop = Shop();
	service = Service();
	nameOrganization = _nameOrganization;
}

void ShopService::visit_client(int type_of_visit, string clientName)
{
	if (type_of_visit)
	{
		service.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName(nameOrganization);
		}
	}
	else
	{
		shop.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName(nameOrganization);
		}
	}
}

void ShopService::addNewEmployee(string _lName, string _fName, string _mName,
	int _age, int _departament, int _position, bool _status)
{
	employers.push_back(Employee(0, _lName,
		_fName, _mName, _age, _departament
		, _position, _status));
	Employee emp = employers.at(employers.size() - 1);
	printf("%s %s %s добавлен\n", emp.lName().data(), emp.fName().data(), emp.mName().data());
}

void ShopService::addNewEmployee()
{
	char* lName = new char[50];
	char* fName = new char[50];
	char* mName = new char[50];

	int age = 0;
	int department;
	int position;
	bool status = 1;
	char correct = 'n';
	cout << endl;
	do 
	{
		cout << "Введите ФИО сотрудника через пробел и возраст:\t";
		scanf_s("%s %s %s %d", lName,50, fName, 50, mName, 50, &age);
		printf("Введено %s %s %s %d, все верно?\t", lName, fName, mName, age);
		correct = (char)_getch();
		cin.clear();
	} while (correct != 'y');
	cout << "\nВыбирите должность из списка, указав ID c экрана:\t";
	int count = 0;
	cout << endl;
	for (int i = 0; i< DepartmentsString.size() ;i++)
	{
		printf("%d %s\n", count++, DepartmentsString[i].data());
	}
	cin >> department;
	count = 0;
	for (int i = 0; i< PositionString.size(); i++)
	{
		printf("%d %s\n", count++, PositionString[i].data());
	}
	cin >> position;
	addNewEmployee(lName, fName, mName, age, department, position, status);
	delete[]lName;
	delete[]fName;
	delete[]mName;
}

void ShopService::delete_employees()
{
}

void ShopService::get_out_employees()
{
}

void ShopService::saveEmployees()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file("Employers.txt", ios_base::out);
	char* tmp = new char[100];
	for (auto emp : employers)
	{
		sprintf_s(tmp,100,"%d %s %s %s %d %d %d %d\n"
			, emp.ID, emp.lName().data(), emp.fName().data(), emp.mName().data(), emp.Age(), emp.department, emp.position, emp.status);
		file << tmp;
	}
	file.close();
}

void ShopService::saveEmployeesIDs()
{
	string text;
	fstream in (ShopService::configPath["IDs"]);
	while (!in.eof())
	{
		string line;
		getline(in, line);
		text += line + "\n";
	}
	in.close();
	fstream out (ShopService::configPath["IDs"], ios::out);
	regex regEx("(LastEmployerID)\\s[0-9]+");
	text = regex_replace(text, regEx, "LastEmployerID "+ to_string(Employee::IDs));
	if (text == "")
		text = "LastEmployerID " + to_string(Employee::IDs);
	out << text;
	out.close();
}

int ShopService::getEmployeesIDs()
{
	return 0;
}


ShopService::~ShopService()
{
	saveEmployees();
	shop.saveGoods(configPath["Goods"]);
}

string* getPathConfig(ShopService obj)
{
	return nullptr;
}


void ShopService::setup_goods()
{
	shop.setup_goods();
}

void ShopService::delete_goods()
{
	shop.delete_goods();
}

void ShopService::addWork()
{
}

void ShopService::deleteWork()
{
}
