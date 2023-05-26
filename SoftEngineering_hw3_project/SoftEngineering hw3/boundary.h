#pragma once
#include "stdcol.h"
#include "entity.h"
#include "control.h"


// ȸ�� ���� Boundary Class
class JoinUI {
public:

    void startInterface(Join* join);

    void selectMemberType();

    void submitMemberInfo();

private:
    Join* join;
};


// �α��� Boundary Class
class LoginUI {
private:
    Login* login;
public:
    void startInterface(Login* login);
    void submitInfo();
};


// �α׾ƿ� Boundary Class
class LogoutUI {
private:
    Logout* logout;
public:
    void startInterface(Logout* logout);
    void confirmLogout();
};


// ȸ��Ż�� Boundary Class
class WithdrawUI {
private:
    Withdraw* withdraw;

public:
    void startInterface(Withdraw* withdraw);
    void confirmWithdrawal();
};


//ä�� ���� ��ȸ boundary Ŭ����
class AskEmployInfoUI {

public:

    AskEmployInfoUI();

    void ask();
};

//ä�� ���� ��� boundary class
class RegisterEmployInfoUI {

public:
    RegisterEmployInfoUI();

    void inputEmployInfo();

    void createNewEmployInfo(string work, int employCount, string deadline);
};

//ä�� ���� �˻� Boundary Class
class SearchEmployUI {
private:
    SearchEmploy* searchEmploy;
public:
    void startInterface();
    void search();
};

//ä�� ���� Boundary Class
class ApplyEmployUI {
private:
    ApplyEmploy* applyEmploy;
public:
    void startInterface();
    void apply();
};


// ���� ���� ��ȸ Boundary class
class ShowApplyInfoUI {
private:
    ShowApplyInfo* control;

public:
    void clickApplyInfo();
};

// ���� ���� ��� Boundary class
class ShowApplyStatsUI {
private:
    ShowApplyStats* showApplyStats;
public:
    void startInterface(ShowApplyStats* showApplyStats);
    void printApplyStats();
};

// ���� ��� Boundary class
class CancelApplyInfoUI {
private:
    CancelApplyInfo* control;
public:
    void selectCancelApply();
};