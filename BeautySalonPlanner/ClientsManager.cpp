#include "ClientsManager.h"
#include <iostream>;
#include<iomanip>
using namespace std;

void ClientsManager::ShowHeader()
{
	helper->Header(5, 25, 25, 5, 25, "ID", "Name", "Surname", "Age", "Phone");
}

void ClientsManager::ShowFooter()
{
	helper->Footer(5, 25, 25, 5, 25);

}

bool ClientsManager::CheckIndexIsCorrect(int index)
{
	if (index < 0 || index > size)
	{
		cout << "[ERROR] wrong index" << endl;
		return false;
	}
	return true;
}

ClientsManager::ClientsManager(Client* new_clients_arr, int new_size, CoutHelper* new_helper)
{
	clients_arr = new_clients_arr;
	size = new_size;
	helper = new_helper;
}

//Сортировка массивов методом выбора
void ClientsManager::SortByName()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (clients_arr[currentIndex].GetName() < clients_arr[smallestIndex].GetName())
			{
				smallestIndex = currentIndex;
			}
		}
		Client tmp = clients_arr[startIndex];
		clients_arr[startIndex] = clients_arr[smallestIndex];
		clients_arr[smallestIndex] = tmp;
		//swap(clients_arr[startIndex], clients_arr[smallestIndex]);
	}
}
void ClientsManager::SortBySurname()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (clients_arr[currentIndex].GetSurname() < clients_arr[smallestIndex].GetSurname())
			{
				smallestIndex = currentIndex;
			}
		}
		Client tmp = clients_arr[startIndex];
		clients_arr[startIndex] = clients_arr[smallestIndex];
		clients_arr[smallestIndex] = tmp;
		//swap(clients_arr[startIndex], clients_arr[smallestIndex]);
	}
}
void ClientsManager::SortByAge()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (clients_arr[currentIndex].GetAge() < clients_arr[smallestIndex].GetAge())
			{
				smallestIndex = currentIndex;
			}
		}
		Client tmp = clients_arr[startIndex];
		clients_arr[startIndex] = clients_arr[smallestIndex];
		clients_arr[smallestIndex] = tmp;
		//swap(clients_arr[startIndex], clients_arr[smallestIndex]);
	}
}
void ClientsManager::SortByPhone()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (clients_arr[currentIndex].GetPhoneNumber() < clients_arr[smallestIndex].GetPhoneNumber())
			{
				smallestIndex = currentIndex;
			}
		}
		Client tmp = clients_arr[startIndex];
		clients_arr[startIndex] = clients_arr[smallestIndex];
		clients_arr[smallestIndex] = tmp;
		//swap(clients_arr[startIndex], clients_arr[smallestIndex]);
	}
}

void ClientsManager::ShowAllClients()
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		clients_arr[i].ShowClient(i);
	}
	ShowFooter();
}

void ClientsManager::AddClient(Client* new_client)
{
	size++;
	Client* temp = new Client[size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = clients_arr[i];
	}
	temp[size-1] = *new_client;
	delete[]clients_arr;
	clients_arr = temp;
}

void ClientsManager::ShowClientsWithName(string name)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		string clientName = clients_arr[i].GetName();
		if (clientName == name)
		{
			clients_arr[i].ShowClient(i);
		}
	}
	ShowFooter();
}
void ClientsManager::ShowClientsWithSurname(string surname)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		if (clients_arr[i].GetSurname() == surname)
		{
			clients_arr[i].ShowClient(i);
		}
	}
	ShowFooter();
}
void ClientsManager::ShowClientsWithAge(int age)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		if (clients_arr[i].GetAge() == age)
		{
			clients_arr[i].ShowClient(i);
		}
	}
	ShowFooter();
}
void ClientsManager::ShowClientsWithPhone(int phone)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		if (clients_arr[i].GetPhoneNumber() == phone)
		{
			clients_arr[i].ShowClient(i);
		}
	}
	ShowFooter();
}

void ClientsManager::EditClientNameByIndex(int index, string new_name)
{
	if (CheckIndexIsCorrect(index))
	{
		clients_arr[index].SetName(new_name);
		cout << "[DONE] client with ID" << index << " changed name to - " << new_name <<endl;
		
		ShowHeader();
		clients_arr[index].ShowClient(index);
		ShowFooter();
	}
}
void ClientsManager::EditClientSurnameByIndex(int index, string new_surname)
{
	if (CheckIndexIsCorrect(index))
	{
		clients_arr[index].SetSurname(new_surname);
		cout << "[DONE] client with ID" << index << " changed surname to - " << new_surname << endl;

		ShowHeader();
		clients_arr[index].ShowClient(index);
		ShowFooter();
	}
}
void ClientsManager::EditClientAgeByIndex(int index, int new_age)
{
	if (CheckIndexIsCorrect(index))
	{
		clients_arr[index].SetAge(new_age);
		cout << "[DONE] client with ID" << index << " changed age to - " << new_age << endl;

		ShowHeader();
		clients_arr[index].ShowClient(index);
		ShowFooter();
	}
}
void ClientsManager::EditClientPhoneByIndex(int index, int new_phone)
{
	if (CheckIndexIsCorrect(index))
	{
		clients_arr[index].SetPhoneNumber(new_phone);
		cout << "[DONE] client with ID" << index << " changed phone number to - " << new_phone << endl;

		ShowHeader();
		clients_arr[index].ShowClient(index);
		ShowFooter();
	}
}

void ClientsManager::DeleteClientDataByIndex(int index)
{
	size--;
	Client* temp = new Client[size];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			temp[i] = clients_arr[i];
		}
		else
		{
			temp[i] = clients_arr[i+1];
		}
	}
	delete[]clients_arr;
	clients_arr = temp;
}