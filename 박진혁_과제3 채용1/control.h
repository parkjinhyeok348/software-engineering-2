#pragma once
#include "stdcol.h"

//ä�� ���� ��� control Ŭ����
class RegisterEmployInfo {

public:
    RegisterEmployInfo();

    ~RegisterEmployInfo();

    void registerEmpolyInfo(string work, int employCount, string deadLIne);
};

//ä�� ���� ��ȸ control class
class AskEmployInfo {

public:
    AskEmployInfo();

    ~AskEmployInfo();

    vector<string> showEmployInfo();
};
