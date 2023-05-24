#ifndef _REGISTER_H
#define _REGISTER_H

#include <string>
#include <sstream>
#include <iostream>
#include "MemberList.h"

#define MAX_STRING 32

using namespace std;


class Join {
public: 
// 새로운 회원을 MemberList에 등록하는 함수.
string addMember(string memberInfo);
    
// memberType을 설정하는 함수
void setMemberType(int memberType);

// Control 생성 후 실행되는 코드
void run(FILE * in_fp, FILE * out_fp);

private: 
    // 가입 과정에서 선택된 회원 종류에 대해 알려주는 값
    int memberType = 0; // 0 : 지정되지 않음, 1 : 회사 회원, 2 : 일반 회원.
};

class JoinUI {
public:

    void startInterface(Join* join, FILE* in_fp, FILE* out_fp);

    void selectMemberType();

    void submitMemberInfo();

private:
    // 이 Boundary를 사용중인 Control의 포인터
    Join* join;
    // 파일 입출력 주소
    FILE* in_fp;
    FILE* out_fp;
};


#endif //_REGISTER_H