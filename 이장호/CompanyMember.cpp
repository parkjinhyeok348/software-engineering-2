#include "CompanyMember.h"

CompanyMember::CompanyMember()
{
    // 아래의 생성자 정의를 위해 임의로 아무것도 하지 않는 생성자 정의
}

CompanyMember::CompanyMember(string id, string password, string companyName, int businessNum)
{
    this->setId(id);
    this->setPassword(password); // id, password는 상위 클래스의 private 변수이므로 setter로 접근함.
    this->companyName = companyName;
    this->businessNum = businessNum;
}

string CompanyMember::getMemberInfo()
{
    stringstream ss;
    ss << this->companyName << " " << this->businessNum << " " << this->getID() << " " << this->getPassword();
    return ss.str();
}
