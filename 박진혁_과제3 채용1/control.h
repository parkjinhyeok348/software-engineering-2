#pragma once
#include "stdcol.h"

//채용 정보 등록 control 클래스
class RegisterEmployInfo {

public:
    RegisterEmployInfo();

    ~RegisterEmployInfo();

    void registerEmpolyInfo(string work, int employCount, string deadLIne);
};

//채용 정보 조회 control class
class AskEmployInfo {

public:
    AskEmployInfo();

    ~AskEmployInfo();

    vector<string> showEmployInfo();
};
