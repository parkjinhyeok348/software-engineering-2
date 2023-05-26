#pragma once
#include "stdcol.h"
#include "entity.h"

// 회원 가입 Control Class
class Join {
public:
    string addMember(string info1, int info2, string id, string password);
    void setMemberType(int memberType);
    void run();

private:
    int memberType = 0;
};


// 로그인 Control Class
class Login {
public:
    void run();
    string authenticateMember(string id, string password);
};


// 로그아웃 Control Class
class Logout {
public:
    void run();
    string processLogout();
};


// 회원 탈퇴 Control Class
class Withdraw {
public:
    string deleteCurrentMember();
    void run();
};

//채용 정보 등록 control 클래스
class RegisterEmployInfo {

public:
    RegisterEmployInfo();

    void registerEmpolyInfo(string work, int employCount, string deadline);
};

//채용 정보 조회 control class
class AskEmployInfo {

public:
    AskEmployInfo();

    vector<string> showEmployInfo();
};

//채용 정보 검색 Control Class
class SearchEmploy {
public:
    void start();
    string doSearch(string companyName);
};

//채용 지원 Control Class
class ApplyEmploy {
public:
    void start();
    string doApply(int businessNumber);
    static bool compare(ApplyInfo a, ApplyInfo b);
};


// 지원 정보 조회 Control class
class ShowApplyInfo {
private:
    GeneralMember* pGeneralMember;

public:
    ShowApplyInfo();
    string viewApplyInfo();
};

// 지원 정보 통계 Control class
class ShowApplyStats {
public:
    void run();
    string showApplyStats();
};


// 지원 취소 Control class
class CancelApplyInfo {
private:
    GeneralMember* pGeneralMember;

public:
    CancelApplyInfo();
    CancelApplyInfo(GeneralMember* refGeneralMember);
    string cancelApply(int businessNumber);
};




