#include "ServiceManager.h"

void ServiceManager::ShowHeader()
{
	helper->Header(5, 25, 25, 25, 5, "ID", "Service", "Time", " Price ", " - ");
}

void ServiceManager::ShowFooter()
{
	helper->Footer(5, 25, 25, 25, 5);
}

bool ServiceManager::CheckIndexIsCorrect(int index)
{
	if (index < 0 || index > size)
	{
		cout << "[ERROR] wrong index" << endl;
		return false;
	}
	return true;
}

ServiceManager::ServiceManager()
{
	helper = new CoutHelper;
	fileHelper.SetPath("Services.dat");
	LoadDataFromFile();
}

ServiceManager::ServiceManager(Service* new_service_arr, int new_size)
{
	service_arr = new_service_arr;
	size = new_size;
	helper = new CoutHelper;
	fileHelper.SetPath("Services.dat");
}

void ServiceManager::LoadDataFromFile()
{
	list<Service> allServices = fileHelper.ReadFile();
	
	size = allServices.size();
	service_arr = new Service[size];
	
	int i = 0;
	for (Service tmp : allServices)
	{
		service_arr[i] = tmp;
	}
}

void ServiceManager::SaveDataToFile()
{
	list<Service> allServices;
	for (int i = 0; i < size; i++)
	{
		allServices.emplace_front(service_arr[i]);
	}
	fileHelper.WriteToFile(allServices);
}

void ServiceManager::SortByName()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{ 
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (service_arr[currentIndex].GetServiceName() < service_arr[smallestIndex].GetServiceName())
			{
				smallestIndex = currentIndex;
			}
		}
		Service tmp = service_arr[startIndex];
		service_arr[startIndex] = service_arr[smallestIndex];
		service_arr[smallestIndex] = tmp;
	}
}

void ServiceManager::SortByPrice()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (service_arr[currentIndex].GetPrice() < service_arr[smallestIndex].GetPrice())
			{
				smallestIndex = currentIndex;
			}
		}
		Service tmp = service_arr[startIndex];
		service_arr[startIndex] = service_arr[smallestIndex];
		service_arr[smallestIndex] = tmp;
	}
}

void ServiceManager::SortByTime()
{
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		int smallestIndex = startIndex;
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			if (service_arr[currentIndex].GetTime() < service_arr[smallestIndex].GetTime())
			{
				smallestIndex = currentIndex;
			}
		}
		Service tmp = service_arr[startIndex];
		service_arr[startIndex] = service_arr[smallestIndex];
		service_arr[smallestIndex] = tmp;
	}
}

void ServiceManager::ShowAllService()
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		service_arr[i].ShowService(i);
	}
	ShowFooter();
}

void ServiceManager::AddService(Service* new_service)
{
	size++;
	Service* temp = new Service[size];
	for (int i = 0; i < size - 1; i++)
	{
		temp[i] = service_arr[i];
	}
	temp[size - 1] = *new_service;
	delete[]service_arr;
	service_arr = temp;
}

void ServiceManager::ShowServicesByName(string serviceName)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		if (service_arr[i].GetServiceName() == serviceName)
		{
			service_arr[i].ShowService(i);
		}
	}
	ShowFooter();
}

void ServiceManager::ShowServicesByPrice(int price)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		if (service_arr[i].GetPrice() == price)
		{
			service_arr[i].ShowService(i);
		}
	}
	ShowFooter();
}

void ServiceManager::ShowServicesByTime(int time)
{
	ShowHeader();
	for (int i = 0; i < size; i++)
	{
		if (service_arr[i].GetTime() == time)
		{
			service_arr[i].ShowService(i);
		}
	}
	ShowFooter();
}

void ServiceManager::EditNameByIndex(int index, string new_serviceName)
{
	if (CheckIndexIsCorrect(index))
	{
		service_arr[index].SetServiceName(new_serviceName);
		cout << "[DONE] servise with ID" << index << " changed nameServise to - " << new_serviceName << endl;

		ShowHeader();
		service_arr[index].ShowService(index);
		ShowFooter();
	}
}

void ServiceManager::EditPriceByIndex(int index, int new_price)
{
	if (CheckIndexIsCorrect(index))
	{
		service_arr[index].SetPrice(new_price);
		cout << "[DONE] servise with ID" << index << " changed price to - " << new_price << endl;

		ShowHeader();
		service_arr[index].ShowService(index);
		ShowFooter();
	}
}

void ServiceManager::EditTimeByIndex(int index, int new_time)
{
	if (CheckIndexIsCorrect(index))
	{
		service_arr[index].SetTime(new_time);
		cout << "[DONE] servise with ID" << index << " changed time to - " << new_time << endl;

		ShowHeader();
		service_arr[index].ShowService(index);
		ShowFooter();
	}
}

void ServiceManager::DeleteByIndex(int index)
{
	if (CheckIndexIsCorrect(index))
	{
		size--;
		Service* temp = new Service[size];
		for (int i = 0; i < size; i++)
		{
			if (i < index)
			{
				temp[i] = service_arr[i];
			}
			else
			{
				temp[i] = service_arr[i + 1];
			}
		}
		delete[]service_arr;
		service_arr = temp;
	}
}
