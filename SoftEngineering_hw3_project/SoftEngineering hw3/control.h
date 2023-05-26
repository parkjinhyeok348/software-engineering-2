#pragma once
#include "stdcol.h"
#include "entity.h"

// ȸ�� ���� Control Class
class Join {
public:
    string addMember(string info1, int info2, string id, string password);
    void setMemberType(int memberType);
    void run();

private:
    int memberType = 0;
};


// �α��� Control Class
class Login {
public:
    void run();
    string authenticateMember(string id, string password);
};


// �α׾ƿ� Control Class
class Logout {
public:
    void run();
    string processLogout();
};


// ȸ�� Ż�� Control Class
class Withdraw {
public:
    string deleteCurrentMember();
    void run();
};

//ä�� ���� ��� control Ŭ����
class RegisterEmployInfo {

public:
    RegisterEmployInfo();

    void registerEmpolyInfo(string work, int employCount, string deadline);
};

//ä�� ���� ��ȸ control class
class AskEmployInfo {

public:
    AskEmployInfo();

    vector<string> showEmployInfo();
};

//ä�� ���� �˻� Control Class
class SearchEmploy {
public:
    void start();
    string doSearch(string companyName);
};

//ä�� ���� Control Class
class ApplyEmploy {
public:
    void start();
    string doApply(int businessNumber);
    static bool compare(ApplyInfo a, ApplyInfo b);
};


// ���� ���� ��ȸ Control class
class ShowApplyInfo {
private:
    GeneralMember* pGeneralMember;

public:
    ShowApplyInfo();
    string viewApplyInfo();
};

// ���� ���� ��� Control class
class ShowApplyStats {
public:
    void run();
    string showApplyStats();
};


// ���� ��� Control class
class CancelApplyInfo {
private:
    GeneralMember* pGeneralMember;

public:
    CancelApplyInfo();
    CancelApplyInfo(GeneralMember* refGeneralMember);
    string cancelApply(int businessNumber);
};




