#ifndef _COMPANYMEMBER_H
#define _COMPANYMEMBER_H

#include "Member.h"
#include <string>
#include <sstream>

using namespace std;

// 회사 회원 클래스
class CompanyMember: public Member {
public:
    // 기본 생성자 (아래의 생성자 선언을 위해 만듦)
    CompanyMember();
    // 생성과 동시에 정보를 주입하는 생성자.
    CompanyMember(string id, string password, string companyName, int businessNum);
    // 회원 정보 문자열을 반환하는 함수
    virtual string getMemberInfo();
private: 
    // 회사 이름
    string companyName;
    // 사업자 등록 번호
    int businessNum;
};

#endif //_COMPANYMEMBER_H