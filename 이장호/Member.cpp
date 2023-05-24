#include "Member.h"

Member** Member::currentMember = nullptr;

bool Member::isPasswordCorrect(string password) {
    if(this->password == password){
        return true;
    }
    else{
        return false;
    }
}

void Member::setLoginStatus(bool loginStatus) {
    this->loginStatus = loginStatus;
}

Member **Member::getCurrentMember()
{
    return currentMember;
}

void Member::setCurrentMember(Member **newCurrentMember)
{
    currentMember = newCurrentMember;
}

string Member::getID()
{
    return this->id;
}

string Member::getPassword()
{
    return this->password;
}

string Member::getMemberInfo()
{
    stringstream ss;
    ss << this->getID() << " " << this->getPassword();
    return ss.str();
}

void Member::setId(string id)
{
    this->id = id;
}

void Member::setPassword(string password)
{
    this->password = password;
}
