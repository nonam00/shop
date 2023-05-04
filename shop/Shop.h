#pragma once
#include"Items.h"
#include <string>
#include<vector>
#include"Entrances.h"
using namespace std;

//������ ���� - ��������� ����� �������
class Shop
{
	vector<Item>goods; //������ �������, ���������� ������� ����� Item 
	vector<Entrance> entrances; //������ ���������
	vector<Item>deleted_goods; //������ �������, ���������� ������� ����� Item 
public:
	Shop();
	void setup_goods(string name, float price, float quantity, int ID = 0, int status = 1); //������� ��� ������ �������� ����� �������� ���� ��������� ������ � ������
	void setup_goods(string file_path); //������� ��� ������������������ �������� ������� ����� ����
	void setup_goods(Item item);//������� ��� ������ �������� ����� �������� ���� ���������
	void get_item(float quantity, string item_name); // � ����������
	void get_summary();  // � ����������
	void EnterClient(string clientName); // ������� ������ �������
	void saveGoods(string file_path);
	void setup_goods();
	void list_goods();
	void delete_goods();

};

