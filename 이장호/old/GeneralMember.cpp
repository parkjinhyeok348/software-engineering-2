/**
 * Project Untitled
 */


#include "GeneralMember.h"

/**
 * GeneralMember implementation
 */

GeneralMember::GeneralMember()
{
    // 아래의 생성자 정의를 위해 임의로 아무것도 하지 않는 생성자 정의
}

GeneralMember::GeneralMember(string id, string password, string name, int ssn)
{
    this->setId(id);
    this->setPassword(password); // id, password는 상위 클래스의 private 변수이므로 setter로 접근함.
    this->name = name;
    this->ssn = ssn;
}

string GeneralMember::getMemberInfo()
{
    stringstream ss;
    ss << this->name << " " << this->ssn << " " << this->getID() << " " << this->getPassword();
    return ss.str();
}
