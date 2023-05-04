#pragma once
#include <string>
using namespace std;

// Этап третий
class Item // Класс деталей
{
	string name;
	float price;
	float quantity;
	int ID;
	int status;
	static int IDs;
public:
	friend class Shop;
	Item(string _name, float _price, float _quantity, int _ID, int _status);
	void add_quantity(float _value);
	void delete_quantity(int _value);
	string Name();
	float& Quantity(); 
	int getItemIDs(string path);
	void setItemIDs(string path);
	float& Price();
	static int GetIDs();
	static void GenIDs();
	void ToString();

};

