#pragma once
#include"Shop.h"
#include"Client.h"
#include"Service.h"
#include"Employee.h"
#include <map>
using namespace std;
enum typeVisit
{
	toBuy = 0,
	toRepair = 1
};
class ShopService
{
	Shop shop;
	Service service;
	string nameOrganization;
	vector<Employee> employers;
	vector<Client> clients;

public:
	ShopService(string _nameOrganistation);
	static map<string, string> configPath;
	void setup_goods();
	void delete_goods();
	void addWork();
	void deleteWork();
	void create_employees(string path_file);
	void getlastIDEmployees(string path_file);
	void visit_client(int type_of_visit, string clientName);
	string getName() { return nameOrganization; }
	void addNewEmployee(string _lName,
		string _fName, string _mName, int _age
		, int _departament, int _position, bool _status = true);
	void addNewEmployee();
	void delete_employees();
	friend string* getPathConfig(ShopService obj);
	void get_out_employees();
	void saveEmployees();
	void saveEmployeesIDs();
	int getEmployeesIDs();
	~ShopService();
};

