#include<iostream>
#include"ShopService.h"
#include"windows.h"
#include"SQL.h"
#include <conio.h>




using namespace std;

enum Activity
{
	������������� = 1,
	������������,
	��������������,
	�������������,
	����������������������,
	���������������������,
	����������������,
	���������������,
	����� = 0

};
string ActivityString[] = {
	"�����",
	"�������� �����",
	"������� �����",
	"�������� ������",
	"������� ������",
	"������� ������� ��������",
	"������� ������� �������",
	"������� ���������",
	"������� ���������"
	};
string to_string(Activity e) {
	return ActivityString[(int)e];
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ShopService myJob("Dream");
	myJob.create_employees(ShopService::configPath["Employers"]);
	int count;
	int choice = -1;
	bool flag = false;
	while (!flag)
	{
		count = 0;
		printf("�������� ��������:\n");
		for (auto item : ActivityString)
		{
			printf("%d. %s\n", count, item.data());
			count++;
		}
		do
		choice = _getch() - '0';
		while (choice < 0);
		printf("������� %s\n", ActivityString[choice].data());
		switch (choice)
		{
		case 1:	
			myJob.setup_goods();
			break;
		case 2:
			myJob.delete_goods();
			break;
		case 3:
			myJob.addWork();
			break;
		case 4:
			myJob.deleteWork();
			break;
		case 5:
			myJob.visit_client(0,"");
			break;
		case 6:
			myJob.visit_client(1,"");
			break;
		case 7:
			myJob.addNewEmployee();
			break;
		case 8:
			myJob.get_out_employees();
			break;
		default:;
			flag = true;
			break;

		}
	}
//	myJob.setup_goods("�������",10,5);
//	myJob.addNewEmployer("������","����", "��������", 30, 1,2,1);
	//SQL sql;
	return 0;
}