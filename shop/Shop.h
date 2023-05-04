#pragma once
#include"Items.h"
#include <string>
#include<vector>
#include"Entrances.h"
using namespace std;

//Первый этап - формируем класс Магазин
class Shop
{
	vector<Item>goods; //Список товаров, необходимо создать класс Item 
	vector<Entrance> entrances; //Список посещений
	vector<Item>deleted_goods; //Список товаров, необходимо создать класс Item 
public:
	Shop();
	void setup_goods(string name, float price, float quantity, int ID = 0, int status = 1); //Функция для ручной загрузки через передачу всех атрибутов товара в фунцию
	void setup_goods(string file_path); //Функция для автоматизированной загрузки товаров через файл
	void setup_goods(Item item);//Функция для ручной загрузки через передачу всех атрибутов
	void get_item(float quantity, string item_name); // В разработке
	void get_summary();  // В разработке
	void EnterClient(string clientName); // Функция приема клиента
	void saveGoods(string file_path);
	void setup_goods();
	void list_goods();
	void delete_goods();

};

