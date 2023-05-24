#ifndef _GENERALMEMBER_H
#define _GENERALMEMBER_H

#include "Member.h"
#include <string>
#include <sstream>



using namespace std;

// 일반 회원 클래스
class GeneralMember: public Member {
public:
    // 기본 생성자 (아래의 생성자 선언을 위해 만듦)
    GeneralMember();
    // 생성과 동시에 정보를 주입하는 생성자.
    GeneralMember(string id, string password, string name, int ssn);
    // 회원 정보 문자열을 반환하는 함수
    virtual string getMemberInfo();
private: 
    // 이름
    string name;
    // 주민등록번호
    int ssn;
};

#endif //_GENERALMEMBER_H