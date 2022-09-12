#include "Service.h"
#include<iomanip>
#include <iostream>
using namespace std;

Service::Service()
{
}

Service::Service(ServiceData* serviceData)
{
    data = *serviceData;
}

Service::Service(string new_serviceName, int new_price, int new_time)
{
    data.serviceName = new_serviceName;
    data.price = new_price;
    data.time = new_time;
}

ServiceData Service::GetServiceData()
{
    return data;
}

string Service::GetServiceName()
{
    return data.serviceName;
}

void Service::SetServiceName(string new_serviceName)
{
    data.serviceName = new_serviceName;
}

int Service::GetPrice()
{
    return data.price;
}

void Service::SetPrice(int new_price)
{
    data.price = new_price;
}

int Service::GetTime()
{
    return data.time;
}

void Service::SetTime(int new_time)
{
    data.time = new_time;
}

void Service::ShowService(int index)
{
    cout << left
        << char(186) << setw(4) << index
        << char(186) << setw(24) << data.serviceName
        << char(186) << setw(24) << data.time
        << char(186) << setw(24) << data.price
        << char(186) << setw(4) << " - " << char(186) << endl;
}
