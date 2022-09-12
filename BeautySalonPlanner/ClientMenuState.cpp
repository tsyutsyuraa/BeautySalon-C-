#include "ClientMenuState.h"
#include "ClientsManager.h"

ClientMenuState::ClientMenuState()
{
	const int arr_size = 5;
	Client* clients_arr = new Client[arr_size]
	{
		Client("Nadia", "Popkina", 25, 685704996),
		Client("Katia", "Petrovich", 30, 683746529),
		Client("Elena", "Krot", 18, 773829384),
		Client("Vasilina", "Tsyutsyura", 28, 685394872),
		Client("Vika", "Zaichuk", 22, 674839284)
	};
	CoutHelper* helper = new CoutHelper;
	this->myClientsManager = new ClientsManager(clients_arr, arr_size, helper);
	clientProgramStatus = ClientsMainMenu;
}

void ClientMenuState::ShowTitle()
{
	switch (clientProgramStatus)
	{
	case ClientsMainMenu:
		cout << "MainMenu -> ClientsMenu\n\n";
		break;
	case ClientsSearchMenu:
		cout << "MainMenu -> ClientsMenu -> ClientsSearch\n\n";
		break;
	case ClientsSearchByName:
		cout << "MainMenu -> ClientsMenu -> ClientsSearch -> By Name\n\n";
		break;
	case ClientsSearchBySurname:
		cout << "MainMenu -> ClientsMenu -> ClientsSearch ->By Surname\n\n";
		break;
	case ClientsSearchByAge:
		cout << "MainMenu -> ClientsMenu -> ClientsSearch ->By Age\n\n";
		break;
	case ClientsSearchByPhone:
		cout << "MainMenu -> ClientsMenu -> ClientsSearch ->By Phone\n\n";
		break;
	case ClientsAdd:
		cout << "MainMenu -> ClientsMenu -> ClientsAdd\n\n";
		break;
	case ClientsSortMenu:
		cout << "MainMenu -> ClientsMenu -> ClientsSort\n\n";
		break;
	case ClientsSortByName:
		cout << "MainMenu -> ClientsMenu -> ClientsSort-> By Name\n\n";
		break;
	case ClientsSortBySurname:
		cout << "MainMenu -> ClientsMenu -> ClientsSort-> By Surname\n\n";
		break;
	case ClientsSortByAge:
		cout << "MainMenu -> ClientsMenu -> ClientsSort -> By Age\n\n";
		break;
	case ClientsSortByPhone:
		cout << "MainMenu -> ClientsMenu -> ClientsSort -> By Phone\n\n";
		break;
	case ClientsShowAll:
		cout << "MainMenu -> ClientsMenu -> All clients\n\n";
		break;
	case ClientsEdit:
		cout << "MainMenu -> ClientsMenu -> ClientsEdit\n\n";
		break;
	case ClientsDelete:
		cout << "MainMenu -> ClientsMenu -> ClientsDelete\n\n";
		break;
	}
}

void ClientMenuState::ShowBody()
{
	switch (clientProgramStatus)
	{
	case ClientsMainMenu:
		break;
	case ClientsSearchMenu:
		break;
	case ClientsSearchByName:
		ShowClientsByName();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsSearchBySurname:
		ShowClientsBySurname();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsSearchByAge:
		ShowClientsByAge();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsSearchByPhone:
		ShowClientsByPhone();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsAdd:
		CreateNewClient();
		cout << "\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsSortMenu:
		cout << "Sort by :\n-1 Name\n-2 Surname\n-3 Age\n-4 Phone_number\n\n-9 Clients menu\n-0 Main menu" << endl;
		break;
	case ClientsSortByName:
		this->myClientsManager->SortByName();
		this->myClientsManager->ShowAllClients();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsSortByAge:
		this->myClientsManager->SortByAge();
		this->myClientsManager->ShowAllClients();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsSortByPhone:
		this->myClientsManager->SortByPhone();
		this->myClientsManager->ShowAllClients();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsShowAll:
		this->myClientsManager->ShowAllClients();
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsEdit:
		cout << "What do you want to Edit :\n-1 Name\n-2 Surname\n-3 Age\n-4 Phone_number\n\n-9 Clients menu\n-0 Main menu " << endl;
		break;
	case ClientsDelete:
		cout << "" << endl;
		break;
	}
}

int ClientMenuState::NextActionMenu()
{
	int choise = 0;
	switch (clientProgramStatus)
	{
	case ClientsMainMenu:
		cout << "-1 Show all clients\n-2 Add client\n-3 Show sorted by...\n-4 Searsh by...\n\n-0 Main menu" << endl;
		cout << "\nEnter your choise : ";
		cin >> choise;
		if (choise == 1)
		{
			clientProgramStatus = ClientsShowAll;
		}
		else if (choise == 2)
		{
			clientProgramStatus = ClientsAdd;
		}
		else if (choise == 3)
		{
			clientProgramStatus = ClientsSortMenu;
		}
		if (choise == 4)
		{
			clientProgramStatus = ClientsSearchMenu;
		}
		break;
	case ClientsSearchMenu:
		cout << "Search by :\n-1 Name\n-2 Surname\n-3 Age\n-4 Phone_number\n\n-9 Clients menu\n-0 Main menu " << endl;
		cout << "\nEnter your choise : ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			clientProgramStatus = ClientsSearchByName;
			break;
		case 2:
			clientProgramStatus = ClientsSearchBySurname;
			break;
		case 3:
			clientProgramStatus = ClientsSearchByAge;
			break;
		case 4:
			clientProgramStatus = ClientsSearchByPhone;
			break;
		case 9:
			clientProgramStatus = ClientsMainMenu;
			break;
		}
		break;
	case ClientsSearchByName:
	case ClientsSearchBySurname:
	case ClientsSearchByAge:
	case ClientsSearchByPhone:
	case ClientsSortByName:
	case ClientsSortBySurname:
	case ClientsSortByAge:
	case ClientsSortByPhone:
	case ClientsShowAll:
		cout << "\nEnter your choise : ";
		cin >> choise;
		if (choise == 7)
		{
			int id;
			cout << "\nEnter ID for DELETE :";
			cin >> id;
			this->myClientsManager->DeleteClientDataByIndex(id);
		}
		if (choise == 8)
		{
			EditClient();
		}
		if (choise == 9)
		{
			clientProgramStatus = ClientsMainMenu;
		}
		break;
	case ClientsAdd:
		cout << "\nEnter your choise : ";
		cin >> choise;
		if (choise == 9)
		{
			clientProgramStatus = ClientsMainMenu;
		}
		break;
	case ClientsSortMenu:
		cout << "\nEnter your choise : ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			clientProgramStatus = ClientsSortByName;
			break;
		case 2:
			clientProgramStatus = ClientsSortBySurname;
			break;
		case 3:
			clientProgramStatus = ClientsSortByAge;
			break;
		case 4:
			clientProgramStatus = ClientsSortByPhone;
			break;
		case 9:
			clientProgramStatus = ClientsMainMenu;
			break;
		}
		break;
	}
	if (choise == 0)
	{
		clientProgramStatus = ClientsMainMenu;
	}
	return choise;
}

void ClientMenuState::InitClient()
{
}

void ClientMenuState::CreateNewClient()
{
	string name;
	cout << "Enter name : ";
	cin >> name;
	string surname;
	cout << "Enter surname : ";
	cin >> surname;
	int age;
	cout << "Enter age : ";
	cin >> age;
	int phone;
	cout << "Enter phone : ";
	cin >> phone;
	Client* new_client = new Client(name, surname, age, phone);
	this->myClientsManager->AddClient(new_client);
}

void ClientMenuState::EditClient()
{
	int id;
	cout << "\nEnter ID for EDIT : ";
	cin >> id;
	int editChoise;
	cout << "1.Edit Name\n2.Edit Surname\n3.Edit Age\n4.Edit Phone\nEnter your choise : ";
	cin >> editChoise;
	if (editChoise == 1)
	{
		string name;
		cout << "Enter new name : ";
		cin >> name;
		this->myClientsManager->EditClientNameByIndex(id, name);
	}
	else if (editChoise == 2)
	{
		string surname;
		cout << "Enter new surname : ";
		cin >> surname;
		this->myClientsManager->EditClientSurnameByIndex(id, surname);
	}
	else if (editChoise == 3)
	{
		int age;
		cout << "Enter new age : ";
		cin >> age;
		this->myClientsManager->EditClientAgeByIndex(id, age);
	}
	else if (editChoise == 4)
	{
		int phone;
		cout << "Enter new phone : ";
		cin >> phone;
		this->myClientsManager->EditClientPhoneByIndex(id, phone);
	}
}

void ClientMenuState::ShowClientsByName()
{
	string name;
	cout << "Enter name : ";
	cin >> name;
	this->myClientsManager->ShowClientsWithName(name);
}

void ClientMenuState::ShowClientsBySurname()
{
	string surname;
	cout << "Enter surname : ";
	cin >> surname;
	this->myClientsManager->ShowClientsWithSurname(surname);
}

void ClientMenuState::ShowClientsByAge()
{
	int age;
	cout << "Enter age : ";
	cin >> age;
	this->myClientsManager->ShowClientsWithAge(age);
}

void ClientMenuState::ShowClientsByPhone()
{
	int phone;
	cout << "Enter phone : ";
	cin >> phone;
	this->myClientsManager->ShowClientsWithPhone(phone);
}