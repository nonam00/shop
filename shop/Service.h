#pragma once
#include<vector>
#include"Items.h"
#include"Works.h"
#include"Entrances.h"

// Второй этап. Создание класса Сервис для продажи ремонтных работ и деталей
class Service
{
	vector<Entrance> entrances; //Списко посещеий клиента
	vector<Item> repairItems; // Список деталей
	vector<Work> ourWorks; // Список работ
public:
	Service();// Конструктор по умолчанию
	void EnterClient(string clientName);
	void addWork();
	void deleteWork();

};

