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
	setup_goods(ShopService::configPath["Goods"]); // При создании объекта класса Shop принимаем список товаров для продажи
}

void Shop::setup_goods(string name, float price, float quantity, int ID, int status) // примитивная функция для добавления одной позиции товара
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
	fstream file (file_path, std::ios_base::in); //Открываем файл в режиме чтения
	char* name = new char[50];//Создаем массив char для хранения символьных данных
	float price; // Переменная для сохранения не целочисленных данных
	float quantity; // Переменная для целочисленных данных. Исходи, что товары будут продааться поштучно
	int ID; // Идентификатор товара
	int status;
	string line; // Переменная для хранения считанной строки
	while (!file.eof())  // Цикл для чтения файла до его конца
	{
		getline(file, line); // считываем строку из файла file и заисываем в переменную line
		if (line == "")
			continue;
		sscanf_s(line.data(),"%d %s %f %f %d", &ID, name, 20, &price, &quantity, &status); // Парсим сроку по типам данных
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
		// Используем алгоритм более примитивой функции после того, как распарсили текстовый файл до простоых аргументов
	}
	file.close(); // Закрываем файл после чтения
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
	//Логика работы с клиентом.
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
	cout << "Вывести список товаров?(д/н)\n";
	int result;
	char choice = getchar();
	result = getchar();
	switch (choice)
	{
	case 'д':
		cout << "Список продуктов:\n";
		list_goods();
		break;
	default:
		cout << "Слепой выбор\n";
	}
	cout << "Продолжить?(д/н)";
	choice = getchar();
	result = getchar();
	switch (choice)
	{
	case 'д':
		cout << "Продолжаем\n";
		list_goods();
		break;
	default:
		cout << "Отмена\n";
		this_thread::sleep_for(chrono::seconds(5));
		system("cls");
		return;
	}
	string name;
	float price;
	float quantity;
	cout <<"Введите наименование товара: ";
	cin.ignore();
	getline(cin, name,'\n');
	printf("Введите цену: ");
	scanf_s("%f",&price);
	printf("Введите количество: ");
	scanf_s("%f", &quantity);
	setup_goods(name, price, quantity);
}

void Shop::list_goods()
{
	cout << "ID\tНаименование\tЦена\tКоличество\n";
	for (auto item : goods)
		if(item.status == 1)
		item.ToString();
}

void Shop::delete_goods()
{
	list_goods();
	int choice;
	cout << "Введите ID товара:";
	scanf_s("%d", &choice);
	for (auto &item : goods)
	{
		if (item.ID == choice)
		{
			item.status = 0;
		}
	}
}
