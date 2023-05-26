#pragma once
#include "stdcol.h"

//채용 정보  entity 클래스
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

