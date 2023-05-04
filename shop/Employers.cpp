#include "Employee.h"
#include<iostream>
#include<string>
#include<fstream>
#include <regex>
#include "ShopService.h"
#include<array>
using namespace std;

void Employee::set_ID()
{
	ID = IDs;
}

void Employee::GenIDs()
{
	IDs++;
}

int Employee::IDs = 0;
void Employee::SetIDs(int ID)
{
	IDs = ID;
}
Employee::Employee(int _ID, string _last_name,  string _first_name, string _middle_name,
	int _age, int _department, int _position, bool _status) :ID{_ID},
	Human(_last_name, _first_name, _middle_name, _age), department{_department},
	position{ _position }, status{_status}
{

	if (_ID == 0)
	{
		int tmp_id = getIDs(ShopService::configPath["IDs"]);
		GenIDs();
		if (tmp_id != 0 && tmp_id == IDs)
		{
			IDs = tmp_id;
		}
		ID = IDs;
	}
	else
	{
		SetIDs(ID);
	}
	setIDs(ShopService::configPath["IDs"]);
} //Конструктор создания сотрудника

void Employee::setPosition(int _position) //Смена должности в рамках одного отдела
{
	position = _position;
}

void Employee::setPosition(int _position, int _department) // Смена должности с переводом в другой отдел
{
	position = _position;
	department = _department;
}

void Employee::sayYourName(string orgName) // Представиться
{
	std::cout << "Добрый день! ";
	Human::sayYourName(orgName);
	std::cout << "Рад видеть Вас в \""<<orgName<<"\"\n";
}

void Employee::setIDs(string path)
{
	string text;
	fstream in(ShopService::configPath["IDs"]);
	while (!in.eof())
	{
		string line;
		getline(in, line);
		text += line + "\n";
	}
	in.close();
	fstream out(ShopService::configPath["IDs"], ios::out);
	regex regEx("(LastEmployerID)\\s[0-9]+");
	text = regex_replace(text, regEx, "LastEmployerID " + to_string(Employee::IDs));
	if (text == "")
		text = "LastEmployerID " + to_string(Employee::IDs);
	out << text.substr(0, text.size() - 1);
	out.close();
}

int Employee::getIDs(string path)
{
	int result = 0;
	string text;
	fstream file("LastID.txt");
	while (!file.eof())
	{
		string line;
		getline(file, line);
		text += line + "\n";
	}
	regex regEx("(LastEmployerID)\\s([0-9]+)");
	vector<string> m_vecFields{ sregex_token_iterator(text.begin(), text.end(), regEx, 2), sregex_token_iterator() };
	if(m_vecFields.size() == 0 || m_vecFields[0]!="")
	result = strtol(m_vecFields[0].data(), NULL, 10);
	file.close();
	return result;
}


