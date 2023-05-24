#ifndef _MEMBERLIST_H
#define _MEMBERLIST_H

#include <string>
#include <sstream>
#include <vector>
#include "Member.h"
#include "CompanyMember.h"
#include "GeneralMember.h"

#define MAX_MEMBER 32

using namespace std;

// Member의 목록을 담고 있는 클래스
class MemberList {
public: 
// Singleton design
static MemberList* getMemberList();
// ID를 통해 해당하는 Member의 포인터를 저장한 배열의 위치를 반환하는 함수
Member** findByID(string id);
    
// 목록에서 해당 회원을 지우는 함수
void deleteMember(Member** deletedMember);
    
// 일반 회원을 등록하는 함수. 추가된 회원의 index를 반환한다.
GeneralMember * addGeneralMember(string id, string password, string name, int ssn);

// 회사 회원을 등록하는 함수. 추가된 회원의 index를 반환한다.
CompanyMember * addCompanyMember(string id, string password, string companyName, int businessNum);

    
private: 
    // Singleton Design
    MemberList();
    static MemberList * memberList;
    // 회원 목록
    Member * members[MAX_MEMBER];
    // 배열 크기(현재 회원 수)
    int size = 0;
};

#endif //_MEMBERLIST_H