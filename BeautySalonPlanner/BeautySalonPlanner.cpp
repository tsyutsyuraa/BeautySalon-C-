#include <iostream>
#include <stdlib.h>
#include "Client.h"
#include "ClientsManager.h"
#include "ClientMenuState.h"
#include "ServiceMenuState.h"
#include "BeautySalonPlanner.h"
using namespace std;

enum State
{
	MainMenu,
	ClientsMenu,
	ServiceMenu
};

State programStatus;
ClientMenuState clientMenuState;
ServiceMenuState serviceMenuState;

void ShowTitle()
{
	switch (programStatus)
	{
		case MainMenu:
			cout << "MainMenu\n\n";
			break;
		case ClientsMenu:
			clientMenuState.ShowTitle();
			break;
		case ServiceMenu:
			serviceMenuState.ShowTitle();
			break;
	}
}

void ShowBody()
{
	switch (programStatus)
	{
		case MainMenu:
			break;
		case ClientsMenu:
			clientMenuState.ShowBody();
			break;
		case ServiceMenu:
			serviceMenuState.ShowBody();
			break;
	}
}

void NextActionMenu()
{
	int choise;

	switch (programStatus)
	{
	case MainMenu:
		cout << "-1 Clients\n-2 Services\n-3 Timetable\n";
		cout << "\nEnter your choise : ";
		cin >> choise;
		if (choise == 1)
		{
			programStatus = ClientsMenu;
		}
		else if (choise == 2)
		{
			programStatus = ServiceMenu;
		}
		break;
	case ClientsMenu:
		choise = clientMenuState.NextActionMenu();
		break;
	case ServiceMenu:
		choise = serviceMenuState.NextActionMenu();
		break;
	}
	if (choise == 0)
	{
		programStatus = MainMenu;
	}
}

int main()
{
	bool continueProgram = true;
	programStatus = MainMenu;
	while (continueProgram)
	{
		system("CLS");
		ShowTitle();
		ShowBody();
		NextActionMenu();
	}
	return 0;
}