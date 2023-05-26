#pragma once
#include "stdcol.h"

//채용 정보 조회 boundary 클래스
class AskEmployInfoUI {

public:
    ~AskEmployInfoUI();

    AskEmployInfoUI();

    void ask();
};

//채용 정보 등록 boundary class
class RegisterEmployInfoUI {

public:
    RegisterEmployInfoUI();

    ~RegisterEmployInfoUI();

    void inputEmployInfo(string work, int employCount, string deadLIne);

    void createNewEmployInfo(string work, int employCount, string deadLIne);
};
