#pragma once
using namespace std;
#include <string>
#include "ServiceData.h"

class Service
{
private:
	ServiceData data;

public:
	Service();
	Service(ServiceData* serviceData);
	Service(string new_serviceName, int new_price, int new_time);

	ServiceData GetServiceData();

	string GetServiceName();
	void SetServiceName(string serviceName);

	int GetPrice();
	void SetPrice(int price);

	int GetTime();
	void SetTime(int time);

	void ShowService(int index);
};

