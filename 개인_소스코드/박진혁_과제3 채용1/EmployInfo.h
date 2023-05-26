#pragma once
#include "stdcol.h"

//ä�� ����  entity Ŭ����
class EmployInfo {
public: 
    EmployInfo();

    ~EmployInfo();

    string getEmployInfoDetails();
    
    EmployInfo getEmployInfo();

    EmployInfo(string companyName, int businessNumber, string work, int employCount, string deadLine){}

    string getEmployInfo() const;
    string getEmployInfoDetails(const string& companyName);
    string getEmployInfoDetails(int businessNumber);
    string getCompanyName() const;

    int getBusinessNumber() const;

private: 
    string companyName;
    int businessNumber;
    string work;
    int employCount;
    string deadLine;
};

