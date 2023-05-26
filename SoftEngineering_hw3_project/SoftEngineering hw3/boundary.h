#pragma once
#include "stdcol.h"
#include "entity.h"
#include "control.h"


// 회원 가입 Boundary Class
class JoinUI {
public:

    void startInterface(Join* join);

    void selectMemberType();

    void submitMemberInfo();

private:
    Join* join;
};


// 로그인 Boundary Class
class LoginUI {
private:
    Login* login;
public:
    void startInterface(Login* login);
    void submitInfo();
};


// 로그아웃 Boundary Class
class LogoutUI {
private:
    Logout* logout;
public:
    void startInterface(Logout* logout);
    void confirmLogout();
};


// 회원탈퇴 Boundary Class
class WithdrawUI {
private:
    Withdraw* withdraw;

public:
    void startInterface(Withdraw* withdraw);
    void confirmWithdrawal();
};


//채용 정보 조회 boundary 클래스
class AskEmployInfoUI {

public:

    AskEmployInfoUI();

    void ask();
};

//채용 정보 등록 boundary class
class RegisterEmployInfoUI {

public:
    RegisterEmployInfoUI();

    void inputEmployInfo();

    void createNewEmployInfo(string work, int employCount, string deadline);
};

//채용 정보 검색 Boundary Class
class SearchEmployUI {
private:
    SearchEmploy* searchEmploy;
public:
    void startInterface();
    void search();
};

//채용 지원 Boundary Class
class ApplyEmployUI {
private:
    ApplyEmploy* applyEmploy;
public:
    void startInterface();
    void apply();
};


// 지원 정보 조회 Boundary class
class ShowApplyInfoUI {
private:
    ShowApplyInfo* control;

public:
    void clickApplyInfo();
};

// 지원 정보 통계 Boundary class
class ShowApplyStatsUI {
private:
    ShowApplyStats* showApplyStats;
public:
    void startInterface(ShowApplyStats* showApplyStats);
    void printApplyStats();
};

// 지원 취소 Boundary class
class CancelApplyInfoUI {
private:
    CancelApplyInfo* control;
public:
    void selectCancelApply();
};