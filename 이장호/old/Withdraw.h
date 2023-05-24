#ifndef _WITHDRAW_H
#define _WITHDRAW_H


#include <iostream>
#include <string>
#include <vector>
#include "MemberList.h"
#include "Member.h"

#define MAX_STRING 32


using namespace std;

// 회원 탈퇴에 사용되는 Control 클래스
class Withdraw {
public: 
// 회원 리스트에서 현재 로그인 중인 회원을 탈퇴시키는 함수. 탈퇴된 회원의 ID를 반환한다.
string deleteMember();

// Control 생성 후 실행되는 함수
void run(FILE* in_fp, FILE* out_fp);
};

class WithdrawUI {
private:
    Withdraw* withdraw;
    FILE* in_fp;
    FILE* out_fp;

public:

    void startInterface(Withdraw* withdraw, FILE* in_fp, FILE* out_fp);

    void confirmWithdrawal();
};

#endif //_WITHDRAW_H