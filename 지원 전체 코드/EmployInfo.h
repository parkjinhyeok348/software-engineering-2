#pragma once
#include "stdcol.h"

//ä�� ����  entity Ŭ����
class EmployInfo {
public: 
    EmployInfo();

    ~EmployInfo();

    EmployInfo(string work, int employCount, string deadline);

    string getEmployInfoDetails();
    
    EmployInfo getEmployInfo();

private: 
    string companyNumber;
    string businessNumber;
    string work;
    int employCount;
    string deadline;
};

