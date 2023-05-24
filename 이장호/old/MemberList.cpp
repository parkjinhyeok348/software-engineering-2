#include "MemberList.h"

MemberList* MemberList::memberList = nullptr;

MemberList *MemberList::getMemberList()
{
    if(memberList == NULL){
        memberList = new MemberList;
    }
    return memberList;
}

Member **MemberList::findByID(string id)
{
    for (int i = 0; i < size; i++) { // 등록된 모든 회원 중
        if(members[i]->getID() == id) { // 해당 위치의 Member와 id가 같을 경우
            return &members[i]; // 
        }
    }
    return NULL; // 못 찾았을 때는 NULL 반환.
}

void MemberList::deleteMember(Member** deletedMember) {
    Member * target = *deletedMember;
    *deletedMember = members[size - 1]; // 목록의 가장 마지막 Member를 삭제될 Member의 위치에 저장함.
    delete target; //
    size--; // 배열의 size를 1 줄여준다.
}

GeneralMember * MemberList::addGeneralMember(string id, string password, string name, int ssn) {
    GeneralMember * newMember = new GeneralMember(id, password, name, ssn);
    members[size++] = newMember; // 목록 맨 뒤에 새로운 Member의 포인터를 저장한다. 그 후 size를 +1 한다.
    return newMember;
}

CompanyMember * MemberList::addCompanyMember(string id, string password, string companyName, int businessNum) {
    CompanyMember * newMember = new CompanyMember(id, password, companyName, businessNum);
    members[size++] = newMember; // 목록 맨 뒤에 새로운 Member의 포인터를 저장한다. size를 +1 한다.
    return newMember;
}

MemberList::MemberList()
{
}
