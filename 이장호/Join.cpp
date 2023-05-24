/**
 * Project Untitled
 */


#include "Join.h"

string Join::addMember(string memberInfo) {
    stringstream ss(memberInfo); // 입력값 parsing 위한 stringstream
    string id;
    string password;
    Member* newMember = NULL;
    if(this->memberType == 1){ // memberType이 1일 경우 : 회사 회원 추가
        string companyName;
        int businessNum;
        ss >> companyName >> businessNum >> id >> password;
        newMember = MemberList::getMemberList()->addCompanyMember(id, password, companyName, businessNum);
    }
    else if(this->memberType == 2){ // memberType이 2일 경우 : 일반 회원 추가
        string name;
        int ssn;
        ss >> name >> ssn >> id >> password;
        newMember = MemberList::getMemberList()->addGeneralMember(id, password, name, ssn);
    }
    return newMember->getMemberInfo(); // override된 getMemberInfo() 호출
}

void Join::setMemberType(int memberType)
{
    this->memberType = memberType;
}

void Join::run(FILE * in_fp, FILE * out_fp)
{
    JoinUI * joinUI = new JoinUI;
    joinUI->startInterface(this, in_fp, out_fp);
}

