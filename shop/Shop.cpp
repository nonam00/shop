#include <iostream>
#include "Shop.h"
#include "Items.h"
#include "Entrances.h"
#include <fstream>
#include <string>
#include "ShopService.h"
#include "windows.h"
#include<thread>


Shop::Shop()
{
	goods = vector<Item>();
	setup_goods(ShopService::configPath["Goods"]); // ��� �������� ������� ������ Shop ��������� ������ ������� ��� �������
}

void Shop::setup_goods(string name, float price, float quantity, int ID, int status) // ����������� ������� ��� ���������� ����� ������� ������
{
	bool flag = false;
	for (auto& good : goods)
	{
		if (good.Name() == name && good.Price() == price)
		{
			if (good.status == 1)
			{
				good.add_quantity(quantity);
			}
			else
			{
				good.status = 1;
			}
			flag = true;
			break;
		}	
	}
	if (!flag)
		goods.push_back(Item(name, price, quantity, ID, status));
		
}

void Shop::setup_goods(string file_path)
{
	fstream file (file_path, std::ios_base::in); //��������� ���� � ������ ������
	char* name = new char[50];//������� ������ char ��� �������� ���������� ������
	float price; // ���������� ��� ���������� �� ������������� ������
	float quantity; // ���������� ��� ������������� ������. ������, ��� ������ ����� ���������� ��������
	int ID; // ������������� ������
	int status;
	string line; // ���������� ��� �������� ��������� ������
	while (!file.eof())  // ���� ��� ������ ����� �� ��� �����
	{
		getline(file, line); // ��������� ������ �� ����� file � ��������� � ���������� line
		if (line == "")
			continue;
		sscanf_s(line.data(),"%d %s %f %f %d", &ID, name, 20, &price, &quantity, &status); // ������ ����� �� ����� ������
		setup_goods(name, price, quantity, ID, status);
		/*bool flag = false;
		for (auto& good : goods)
		{
			if (good.Name() == name and good.Price() == price)
			{
				good.add_quantity(quantity);
				flag = false;
				break;
			}
		}

		if (!flag)
			goods.push_back(Item(name, price, quantity));*/
		// ���������� �������� ����� ���������� ������� ����� ����, ��� ���������� ��������� ���� �� �������� ����������
	}
	file.close(); // ��������� ���� ����� ������
	delete[]name;
}

void Shop::setup_goods(Item item)
{
}

void Shop::get_item(float quantity, string item_name)
{
}

void Shop::get_summary()
{
	for (auto good : goods)
	{
		cout << "Name: " << good.Name() 
			<< ", price: " << good.Price() << " , quantity: " 
			<< good.Quantity()<<"\n";
	}
}

void Shop::EnterClient(string clientName)
{
	
	Entrance tmp(clientName);
	//������ ������ � ��������.
	entrances.push_back(tmp);
}

void Shop::saveGoods(string file_path)
{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		fstream file(file_path, ios_base::out);
		char* tmp = new char[100];
		for (auto item: goods)
		{
			sprintf_s(tmp, 100, "%d %s %.2f %.2f %d\n"
				, item.ID, item.name.data(), item.price, item.quantity, item.status);
			file << tmp;
		}
		file.close();
}

void Shop::setup_goods()
{
	cout << "������� ������ �������?(�/�)\n";
	int result;
	char choice = getchar();
	result = getchar();
	switch (choice)
	{
	case '�':
		cout << "������ ���������:\n";
		list_goods();
		break;
	default:
		cout << "������ �����\n";
	}
	cout << "����������?(�/�)";
	choice = getchar();
	result = getchar();
	switch (choice)
	{
	case '�':
		cout << "����������\n";
		list_goods();
		break;
	default:
		cout << "������\n";
		this_thread::sleep_for(chrono::seconds(5));
		system("cls");
		return;
	}
	string name;
	float price;
	float quantity;
	cout <<"������� ������������ ������: ";
	cin.ignore();
	getline(cin, name,'\n');
	printf("������� ����: ");
	scanf_s("%f",&price);
	printf("������� ����������: ");
	scanf_s("%f", &quantity);
	setup_goods(name, price, quantity);
}

void Shop::list_goods()
{
	cout << "ID\t������������\t����\t����������\n";
	for (auto item : goods)
		if(item.status == 1)
		item.ToString();
}

void Shop::delete_goods()
{
	list_goods();
	int choice;
	cout << "������� ID ������:";
	scanf_s("%d", &choice);
	for (auto &item : goods)
	{
		if (item.ID == choice)
		{
			item.status = 0;
		}
	}
}
