#ifndef _LOGOUT_H
#define _LOGOUT_H

#include <string>
#include <iostream>
#include "Member.h"
#include "MemberList.h"

#define MAX_STRING 32


using namespace std;

class Logout {
public: 
    void run(FILE* in_fp, FILE* out_fp);
    string processLogout();
};


class LogoutUI {
private:
    Logout* logout;
    FILE* in_fp;
    FILE* out_fp;

public:
    // 사용자 인터페이스(파일 입/출력)의 시작을 위해 실행되는 함수.
    void startInterface(Logout* logout, FILE* in_fp, FILE* out_fp);
    // 사용자의 로그아웃을 확정하는 함수.
    void confirmLogout();
};
#endif //_LOGOUT_H