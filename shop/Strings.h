
#include <string>
#include<array>
using namespace std;

enum Departments
{
	Management,
	Sellers,
	Repairmen,
	Common


}; // ������������ �������� �������
array<string, 4>DepartmentsString
{
	"������� ����������",
	"����� ������",
	"����� ���������� ������������",
	"����� �����"
};
enum Positions
{
	Director,
	DirectorAssistent,
	Ingineer,
	SeniorIngineer,
	Sellman,
	SeniorSellman,
	Accountant,
	Administrator
};// ������������ ����������
array<string, 8>PositionString
{
	"��������",
	"����������� ���������",
	"�������",
	"������� �������",
	"�������� �� ��������",
	"������� �������� �� ��������",
	"������ ��������",
	"�������������"
};