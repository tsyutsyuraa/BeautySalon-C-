#include "Client.h"
#include <iostream>
#include<iomanip>
using namespace std;

Client::Client()
{
}

Client::Client(string new_name, string new_surname, int new_age, int new_phone_number)
{
	name = new_name;
	surname = new_surname;
	age = new_age;
	phone_number = new_phone_number;
}

string Client::GetName()
{
	return name;
}

void Client::SetName(string new_name)
{
	name = new_name;
}

string Client::GetSurname()
{
	return surname;
}

void Client::SetSurname(string new_surname)
{
	surname = new_surname;
}

int Client::GetAge()
{
	return age;
}

void Client::SetAge(int new_age)
{
	age = new_age;
}

int Client::GetPhoneNumber()
{
	return phone_number;
}

void Client::SetPhoneNumber(int new_phone_number)
{
	phone_number = new_phone_number;
}

void Client::ShowClient(int index)
{
	cout << left
		<< char(186) << setw(4) << index
		<< char(186) << setw(24) << name
		<< char(186) << setw(24) << surname
		<< char(186) << setw(4) << age
		<< char(186) << setw(24) << phone_number << char(186) << endl;
}