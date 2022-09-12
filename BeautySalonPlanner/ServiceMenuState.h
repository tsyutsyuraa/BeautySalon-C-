#pragma once
#include "BaseMenuState.h"
#include"ServiceManager.h"

enum ServiceState
{
	ServiceMainMenu,
	ServiceSearchMenu,
	ServiceSearchByServiceName,
	ServiceSearchByTime,
	ServiceSearchByPrice,
	ServiceAdd,
	ServiceSortMenu,
	ServiceSortByServiceName,
	ServiceSortByTime,
	ServiceSortByPrice,
	ServiceShowAll,
	ServiceEdit,
	ServiceDelete
};	


class ServiceMenuState : public BaseMenuState
{
public:
	ServiceMenuState();
	virtual void ShowTitle() override;
	virtual void ShowBody() override;
	virtual int NextActionMenu() override;

private:
	void CreateNewService();
	void EditService();
	void DeleteService();
	void ShowServicesByPrice();
	void ShowServicesByTime();
	void ShowServicesByName();

protected :
	ServiceState serviceProgramStatus;
	ServiceManager* myServiceManager;
};