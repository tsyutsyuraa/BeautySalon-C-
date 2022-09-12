#include "ServiceMenuState.h"
#include <iostream>
using namespace std;

ServiceMenuState::ServiceMenuState()
{
	const int arr_size = 7;
	Service* services_arr = new Service[arr_size]
	{
		Service("Nail: Gel polish", 350, 30),
		Service("Nail: Franch", 200, 45),
		Service("Nail: Gel", 450, 60),
		Service("Beauty: Piling", 700, 80),
		Service("Beauty: polish", 900, 75),
		Service("Haircut: mens hair", 350, 60),
		Service("Haircut: women hair", 800, 85),
	};
	this->myServiceManager = new ServiceManager(services_arr, arr_size);

	serviceProgramStatus = ServiceMainMenu;
}

void ServiceMenuState::ShowTitle()
{
	switch (serviceProgramStatus)
	{
	case ServiceMainMenu:
		cout << "MainMenu -> ServiceMenu\n\n";break;
		break;
	case ServiceSearchMenu:
		cout << "MainMenu -> ServiceMenu -> ServiceSearch\n\n";
		break;
	case ServiceSearchByServiceName:
		cout << "MainMenu -> ServiceMenu -> ServiceSearch -> By name\n\n";
		break;
	case ServiceSearchByTime:
		cout << "MainMenu -> ServiceMenu -> ServiceSearch ->By time\n\n";
		break;
	case ServiceSearchByPrice:
		cout << "MainMenu -> ServiceMenu -> ServiceSearch ->By price\n\n";
		break;
	case ServiceAdd:
		cout << "MainMenu -> ServiceMenu -> Add service\n\n";
		break;
	case ServiceSortMenu:
		cout << "MainMenu -> ServiceMenu -> SortMenu\n\n";
		break;
	case ServiceSortByServiceName:
		cout << "MainMenu -> ServiceMenu -> SortMenu -> By name\n\n";
		break;
	case ServiceSortByTime:
		cout << "MainMenu -> ServiceMenu -> SortMenu -> By time\n\n";
		break;
	case ServiceSortByPrice:
		cout << "MainMenu -> ServiceMenu -> SortMenu -> By price\n\n";
		break;
	case ServiceShowAll:
		cout << "MainMenu -> ServiceMenu -> Show all\n\n";
		break;
	case ServiceEdit:
		cout << "MainMenu -> ServiceMenu -> Service edit\n\n";
		break;
	case ServiceDelete:
		cout << "MainMenu -> ServiceMenu -> Service delete\n\n";
		break;
	}
}

void ServiceMenuState::ShowBody()
{
	switch (serviceProgramStatus)
	{
	case ServiceMainMenu:
		break;
	case ServiceSearchMenu:
		break;
	case ServiceSearchByServiceName:
		ShowServicesByName();
		break;
	case ServiceSearchByTime:
		ShowServicesByTime();
		break;
	case ServiceSearchByPrice:
		ShowServicesByPrice();
		break;
	case ServiceAdd:
		CreateNewService();
		break;
	case ServiceSortMenu:
		break;
	case ServiceSortByServiceName:
		myServiceManager->SortByName();
		myServiceManager->ShowAllService();
		break;
	case ServiceSortByTime:
		myServiceManager->SortByTime();
		myServiceManager->ShowAllService();
		break;
	case ServiceSortByPrice:
		myServiceManager->SortByPrice();
		myServiceManager->ShowAllService();
		break;
	case ServiceShowAll:
		myServiceManager->ShowAllService();
		break;
	case ServiceEdit:
		EditService();
		break;
	case ServiceDelete:
		DeleteService();
		break;
	}
}

int ServiceMenuState::NextActionMenu()
{
	int choise = 0;

	switch (serviceProgramStatus)
	{
	case ServiceMainMenu:
	case ServiceAdd:
	case ServiceEdit:
	case ServiceDelete:
		cout << "-1 Show all services\n-2 Add service\n-3 Show sorted by...\n-4 Searsh by...\n\n-0 Main menu" << endl;
		cout << "\nEnter your choise : ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			serviceProgramStatus = ServiceShowAll;
			break;
		case 2:
			serviceProgramStatus = ServiceAdd;
			break;
		case 3:
			serviceProgramStatus = ServiceSortMenu;
			break;
		case 4:
			serviceProgramStatus = ServiceSearchMenu;
			break;
		}
		break;
	case ServiceSearchMenu:
		cout << "Search by :\n-1 Name\n-2 Time\n-3 Price\n\n-9 Services menu\n-0 Main menu" << endl;
		cout << "\nEnter your choise : ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			serviceProgramStatus = ServiceSearchByServiceName;
			break;
		case 2:
			serviceProgramStatus = ServiceSearchByTime;
			break;
		case 3:
			serviceProgramStatus = ServiceSearchByPrice;
			break;
		}
		break;
	case ServiceSortMenu:
		cout << "Sort by :\n-1 Name\n-2 Time\n-3 Price\n\n-9 Services menu\n-0 Main menu" << endl;
		cout << "\nEnter your choise : ";
		cin >> choise;
		switch (choise)
		{
		case 1:
			serviceProgramStatus = ServiceSortByServiceName;
			break;
		case 2:
			serviceProgramStatus = ServiceSortByTime;
			break;
		case 3:
			serviceProgramStatus = ServiceSortByPrice;
			break;
		}
		break;
	case ServiceSearchByTime:
	case ServiceSearchByPrice:
	case ServiceSearchByServiceName:
	case ServiceSortByServiceName:
	case ServiceSortByTime:
	case ServiceSortByPrice:
	case ServiceShowAll:
		cout << "\n-7 Delete by ID \n-8 Edit by ID\n-9 Service menu\n-0 Main menu " << endl;
		cout << "\nEnter your choise : ";
		cin >> choise;
		switch (choise)
		{
		case 7:
			serviceProgramStatus = ServiceDelete;
			break;
		case 8:
			serviceProgramStatus = ServiceEdit;
			break;
		}
		break;
	}

	if (choise == 9 || choise == 0)
	{
		serviceProgramStatus = ServiceMainMenu;
	}
	return choise;
}

void ServiceMenuState::CreateNewService()
{
	string name;
	cout << "Enter service name : ";
	cin >> name;
	int price;
	cout << "Enter service price : ";
	cin >> price;
	int time;
	cout << "Enter service time : ";
	cin >> time;
	
	Service* new_service = new Service(name, price, time);
	this->myServiceManager->AddService(new_service);
}

void ServiceMenuState::EditService()
{
	myServiceManager->ShowAllService();

	int id;
	cout << "\n\nEnter ID for EDIT : ";
	cin >> id;
	int editChoise;
	cout << "1.Edit Name\n2.Edit price\n3.Edit time\nEnter your choise : ";
	cin >> editChoise;
	if (editChoise == 1)
	{
		string name;
		cout << "Enter new name : ";
		cin >> name;
		this->myServiceManager->EditNameByIndex(id, name);
	}
	else if (editChoise == 2)
	{
		int price;
		cout << "Enter new price : ";
		cin >> price;
		this->myServiceManager->EditPriceByIndex(id, price);
	}
	else if (editChoise == 3)
	{
		int time;
		cout << "Enter new time : ";
		cin >> time;
		this->myServiceManager->EditTimeByIndex(id, time);
	}
}

void ServiceMenuState::DeleteService()
{
	myServiceManager->ShowAllService();


	int id;
	cout << "\n\nEnter ID for Delete : ";
	cin >> id;
	myServiceManager->DeleteByIndex(id);
}

void ServiceMenuState::ShowServicesByPrice()
{
	int price;
	cout << "Enter price : ";
	cin >> price;
	myServiceManager->ShowServicesByPrice(price);
}

void ServiceMenuState::ShowServicesByTime()
{
	int time;
	cout << "Enter time : ";
	cin >> time;
	myServiceManager->ShowServicesByTime(time);
}

void ServiceMenuState::ShowServicesByName()
{
	string name;
	cout << "Enter name : ";
	cin >> name;
	myServiceManager->ShowServicesByName(name);
}

