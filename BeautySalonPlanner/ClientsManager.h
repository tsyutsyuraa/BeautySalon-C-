#pragma once
#include "Client.h"
#include "CoutHelper.h"

class ClientsManager
{
private:
	Client* clients_arr;
	int size;
	CoutHelper* helper;

	void ShowHeader();
	void ShowFooter();
	bool CheckIndexIsCorrect(int index);
public:
	ClientsManager(Client* new_clients_arr, int new_size, CoutHelper* new_helper);
	
	void SortByName();
	void SortBySurname();
	void SortByAge();
	void SortByPhone();
	
	void ShowAllClients();

	void AddClient(Client* new_client);
	
	void ShowClientsWithName(string name);
	void ShowClientsWithSurname(string surname);
	void ShowClientsWithAge(int age);
	void ShowClientsWithPhone(int phone);
	
	void EditClientNameByIndex(int index, string new_name);
	void EditClientSurnameByIndex(int index, string new_surname);
	void EditClientAgeByIndex(int index, int new_age);
	void EditClientPhoneByIndex(int index, int new_phone);
	
	void DeleteClientDataByIndex(int index);
};