#pragma once
#include "stdcol.h"

//ä�� ���� ��ȸ boundary Ŭ����
class AskEmployInfoUI {

public:
    ~AskEmployInfoUI();

    AskEmployInfoUI();

    void ask();
};

//ä�� ���� ��� boundary class
class RegisterEmployInfoUI {

public:
    RegisterEmployInfoUI();

    ~RegisterEmployInfoUI();

    void inputEmployInfo(string work, int employCount, string deadLIne);

    void createNewEmployInfo(string work, int employCount, string deadLIne);
};
