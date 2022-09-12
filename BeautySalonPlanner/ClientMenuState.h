#pragma once
#include <string>
#include <iostream>
#include "BaseMenuState.h"
#include "ClientsManager.h"

enum ClientState //тип данних menustate з набором можливих значень
{
	ClientsMainMenu,
	ClientsSearchMenu,
	ClientsSearchByName,
	ClientsSearchBySurname,
	ClientsSearchByAge,
	ClientsSearchByPhone,
	ClientsAdd,
	ClientsSortMenu,
	ClientsSortByName,
	ClientsSortBySurname,
	ClientsSortByAge,
	ClientsSortByPhone,
	ClientsShowAll,
	ClientsEdit,
	ClientsDelete
};


class ClientMenuState : public BaseMenuState
{
protected:
	ClientState clientProgramStatus;
	ClientsManager* myClientsManager;
public:
	ClientMenuState();
	virtual void ShowTitle() override;
	virtual void ShowBody() override;
	virtual int NextActionMenu() override;

private: 
	void InitClient();
	void CreateNewClient();
	void EditClient();
	void ShowClientsByName();
	void ShowClientsBySurname();
	void ShowClientsByAge();
	void ShowClientsByPhone();
};
