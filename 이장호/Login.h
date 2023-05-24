#ifndef _LOGIN_H
#define _LOGIN_H

#include <string>
#include <iostream>
#include "Member.h"
#include "MemberList.h"

#define MAX_STRING 32

using namespace std;

class Login {
public:
    // Control 생성 후 실행되는 함수
    void run(FILE* in_fp, FILE* out_fp);
    // ID와 Password를 통해 회원이 본인인지 인증하고 로그인시키는 함수,
    // 로그인이 완료되면 로그인된 아이디와 비밀번호를 반환한다.
    string authenticateMember(string id, string password);
};

class LoginUI {
private:
    Login* login;
    FILE* in_fp;
    FILE* out_fp;
public:
    // 사용자 인터페이스(파일 입/출력)의 시작을 위해 실행되는 함수.
    void startInterface(Login* login, FILE* in_fp, FILE* out_fp);
    // 사용자가 정보(ID, Password)를 입력하여 제출할 때 사용되는 함수.
    void submitInfo();
};

#endif //_LOGIN_H