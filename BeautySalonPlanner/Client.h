#pragma once
using namespace std;
#include <string>

class Client
{
private:
	string name;
	string surname;
	int age;
	int phone_number;
public:
	Client();
	Client(string new_name, string new_surname, int new_age, int new_phone_number);

	string GetName();
	void SetName(string name);

	string GetSurname();
	void SetSurname(string new_surname);

	int GetAge();
	void SetAge(int age);

	int GetPhoneNumber();
	void SetPhoneNumber(int new_phone_number);

	void ShowClient(int index);
};