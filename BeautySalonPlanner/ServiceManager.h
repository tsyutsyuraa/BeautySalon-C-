#pragma once
#include"Service.h"
#include"CoutHelper.h"
#include"BinaryFileHelper.h"

class ServiceManager
{
private:
	Service* service_arr;
	int size;
	CoutHelper* helper;
	BinaryFileHelper fileHelper;

	void ShowHeader();
	void ShowFooter();
	bool CheckIndexIsCorrect(int index);
public:
	ServiceManager();
	ServiceManager(Service* new_service_arr, int new_size);

	void LoadDataFromFile();
	void SaveDataToFile();

	void SortByName();
	void SortByPrice();
	void SortByTime();

	void ShowAllService();

	void AddService(Service* new_service);

	void ShowServicesByName(string serviceName);
	void ShowServicesByPrice(int price);
	void ShowServicesByTime(int time);

	void EditNameByIndex(int index, string new_serviceName);
	void EditPriceByIndex(int index, int new_price);
	void EditTimeByIndex(int index, int new_time);
		 
	void DeleteByIndex(int index);
};

