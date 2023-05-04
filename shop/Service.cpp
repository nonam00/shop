#include "Service.h"

Service::Service()
{
	ourWorks = vector<Work>();
	repairItems = vector<Item>();
}

void Service::EnterClient(string clientName)
{
	Entrance tmp(clientName);
	//Логика работы с клиентом.
	entrances.push_back(tmp);
}

void Service::addWork()
{
}

void Service::deleteWork()
{
}
