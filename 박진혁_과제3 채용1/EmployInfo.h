#pragma once
#include "stdcol.h"

//채용 정보  entity 클래스
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

