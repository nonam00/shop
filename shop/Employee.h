#pragma once
#include "Human.h"
#include<array>


class Employee:Human
{
	
	int position;
	int department;
	bool status;
	int ID;
	static int IDs;
	void set_ID();
	void static GenIDs();

public:
	static void SetIDs(int _ID);
	friend class ShopService;
	Employee(int _ID, string _last_name,  string _first_name
		,  string _middle_name, int _age, int _department,
		int position, bool _status);
	void setPosition(int _position);
	void setPosition(int _position, int _department);
	void sayYourName(string name) override;
	void setIDs(string path);
	int getIDs(string path);
	//string fName() {return  }
};

