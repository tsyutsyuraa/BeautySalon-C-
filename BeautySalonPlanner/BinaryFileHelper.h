#pragma once
#include <iostream>
#include <list>
#include <string>
#include<fstream>
#include "Service.h"

using namespace std;

class BinaryFileHelper
{
public:
	void SetPath(string path)
	{
		filepath = path;
	}

    void WriteToFile(list<Service> elements)
    {
        ofstream file;
        file.open(filepath, ofstream::in);
        if (!file.is_open())
        {
            cout << "Cannot open file!" << endl;
        }
        else
        {
            for (Service tmp : elements)
            {
                ServiceData data = tmp.GetServiceData();
                file.write((char*)&data, sizeof(ServiceData));
            }
        }
        file.close();
    }

    list<Service> ReadFile()
    {
        list<Service> result;
        ifstream file;
        file.open(filepath);
        if (!file.is_open())
        {
            cout << "Error. Cant open file" << endl;
        }
        else
        {
            while (file.peek() != EOF)
            {
                char* buffer = new char[sizeof(ServiceData)];
                file.read(buffer, sizeof(ServiceData));
                ServiceData* tmp = (ServiceData*)(buffer);

                Service serv(tmp);
                result.emplace_front(serv);
            }
        }
        file.close();
        return result;
    }
private:
    string filepath;
};