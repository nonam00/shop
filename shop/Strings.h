
#include <string>
#include<array>
using namespace std;

enum Departments
{
	Management,
	Sellers,
	Repairmen,
	Common


}; // Перечисление названия отделов
array<string, 4>DepartmentsString
{
	"Аппарат управления",
	"Отдел продаж",
	"Отдел сервисного обслуживания",
	"Общий отдел"
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
};// Перечисление должностей
array<string, 8>PositionString
{
	"Директор",
	"Заместитель директора",
	"Инжинер",
	"Ведуший инжинер",
	"Менеджер по продажам",
	"Старший менеджер по продажам",
	"Клиент менеджер",
	"Администратор"
};