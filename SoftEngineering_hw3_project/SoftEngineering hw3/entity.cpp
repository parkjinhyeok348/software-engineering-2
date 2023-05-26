#include "stdcol.h"
#include"entity.h"
#include"boundary.h"

extern EmployInfoCollection employInfoCollection;

/*
    �Լ� �̸� : Member::isPasswordCorrect
    ��� : �Ű������� ���޵� ��й�ȣ�� ����� ��й�ȣ�� ��ġ�ϴ��� Ȯ����
*/
bool Member::isPasswordCorrect(string password) {
    if (this->password == password) {
        return true;
    }
    else {
        return false;
    }
}

/*
    �Լ� �̸� : Member::getID
    ��� : ȸ���� ID�� ��ȯ��
*/
string Member::getID()
{
    return this->id;
}

/*
    �Լ� �̸� : Member::getPassword
    ��� : ȸ���� Password�� ��ȯ��
*/
string Member::getPassword()
{
    return this->password;
}

/*
    �Լ� �̸� : Member::setId
    ��� : ȸ���� ID�� ������
*/
void Member::setId(string id)
{
    this->id = id;
}

/*
    �Լ� �̸� : Member::setPassword
    ��� : ȸ���� Password�� ������
*/
void Member::setPassword(string password)
{
    this->password = password;
}

/*
    �Լ� �̸� : GeneralMember::GeneralMember
    ��� : GeneralMember�� �⺻ ������
*/
GeneralMember::GeneralMember() {

}

/*
    �Լ� �̸� : GeneralMember::GeneralMember
    ��� : GeneralMember�� �ʱⰪ ���� ������
*/
GeneralMember::GeneralMember(string id, string password, string name, int ssn)
{
    this->setId(id);
    this->setPassword(password); // id, password�� ���� Ŭ������ private �����̹Ƿ� setter�� ������.
    this->name = name;
    this->ssn = ssn;
    this->ownedApplyInfoCollection = new ApplyInfoCollection;
}

/*
    �Լ� �̸� : GeneralMember::getOwnedApplyInfoCollection
    ��� : �Ϲ� ȸ���� �������� ApplyInfoCollection�� �ּҸ� ��ȯ��
*/
ApplyInfoCollection* GeneralMember::getOwnedApplyInfoCollection()
{
    return ownedApplyInfoCollection;
}

/*
    �Լ� �̸� : GeneralMember::getMemberInfo
    ��� : �Ϲ� ȸ���� ������ ���ڿ��� ��ȯ��
*/
string GeneralMember::getMemberInfo()
{
    stringstream ss;
    ss << this->name << " " << this->ssn << " " << getID() << " " << this->getPassword();
    return ss.str();
}

/*
   �Լ� �̸� : GeneralMember::getStats
   ��� : �Ϲ� ȸ���� ������ ���� Ƚ�� ��踦 ���ڿ��� ��ȯ��
*/
string GeneralMember::getStats()
{
    string result;
    map<string, int> stats;
    for (auto it : ownedApplyInfoCollection->getApplyList()) {
        string work = it.getWork();
        if (stats.find(work) == stats.end()) {
            stats.insert(make_pair(work, 1));
        }
        else {
            stats.find(work)->second++;
        }
    }
    for (auto it = stats.begin(); it != stats.end(); it++) {
        result.append(it->first + " " + to_string(it->second));
        result.append("\n");
    }
    return result;
}

/*
    �Լ� �̸� : CompanyMember::CompanyMember
    ��� : CompanyMember�� �⺻ ������
*/
CompanyMember::CompanyMember() {

}

/*
    �Լ� �̸� : CompanyMember::CompanyMember
    ��� : CompanyMember�� �ʱⰪ ���� ������
*/
CompanyMember::CompanyMember(string id, string password, string companyName, int businessNumber)
{
    this->setId(id);
    this->setPassword(password);
    this->companyName = companyName;
    this->businessNumber = businessNumber;
}


/*
    �Լ� �̸� : CompanyMember::getMemberInfo
    ��� : ȸ�� ȸ���� ������ ���ڿ��� ��ȯ��
*/
string CompanyMember::getMemberInfo()
{
    stringstream ss;
    ss << this->companyName << " " << this->businessNumber << " " << this->getID() << " " << this->getPassword();
    return ss.str();
}

/*
    �Լ� �̸� : CompanyMember::getStats
    ��� : ȸ�� ȸ���� ������ ���� Ƚ�� ��踦 ���ڿ��� ��ȯ��
*/
string CompanyMember::getStats()
{
    string result;
    map<string, int> stats;
    for (auto& it : employInfoCollection.getEmployInfos()) {
        string work = it.getWork();
        if (stats.find(work) == stats.end()) {
            stats.insert(make_pair(work, it.getApplyCount()));
        }
        else {
            stats.find(work)->second += it.getApplyCount();
        }
    }
    for (auto it = stats.begin(); it != stats.end(); it++) {
        result.append(it->first + " " + to_string(it->second));
        result.append("\n");
    }
    return result;
}



MemberCollection* MemberCollection::memberList = nullptr;
string MemberCollection::currentMemberID = "";
/*
    �Լ� �̸� : MemberCollection::getCurrentMember
    ��� : ���� �α��� �� ȸ���� �ּҸ� ��ȯ��
*/
Member* MemberCollection::getCurrentMember()
{
    return getMemberCollection()->findByID(currentMemberID);
}

/*
    �Լ� �̸� : MemberCollection::setCurrentMember
    ��� : ���� �α��� �� ȸ���� ID�� ���� ������
*/
void MemberCollection::setCurrentMember(string newCurrentMember)
{
    currentMemberID = newCurrentMember;
}

/*
    �Լ� �̸� : MemberCollection::getMemberList
    ��� : MemberCollection Instance�� ������ �����ϰ�, �����͸� ��ȯ��
*/
MemberCollection* MemberCollection::getMemberCollection()
{
    if (memberList == NULL) {
        memberList = new MemberCollection;
    }
    return memberList;
}

/*
    �Լ� �̸� : MemberCollection::findByID
    ��� : ID�� �ش��ϴ� ȸ�� ������ �����͸� ��ȯ��
*/
Member* MemberCollection::findByID(string id)
{
    return members[id];
}

/*
    �Լ� �̸� : MemberCollection::deleteCurrentMember
    ��� : ���� �α��� �� ȸ���� Collection���� ������
*/
void MemberCollection::deleteCurrentMember() {
    members.erase(currentMemberID);
}

/*
    �Լ� �̸� : MemberCollection::addGeneralMember
    ��� : �Ϲ� ȸ���� ȸ�� Collection�� �����
*/
Member* MemberCollection::addGeneralMember(string id, string password, string name, int ssn)
{
    GeneralMember* newMember = new GeneralMember(id, password, name, ssn);
    members.insert(make_pair(id, newMember));
    return members[id];
}

/*
    �Լ� �̸� : MemberCollection::addCompanyMember
    ��� : �Ϲ� ȸ���� ȸ�� Collection�� �����
*/
Member* MemberCollection::addCompanyMember(string id, string password, string companyName, int businessNumber)
{
    CompanyMember* newMember = new CompanyMember(id, password, companyName, businessNumber);
    members.insert(make_pair(id, newMember));
    return members[id];
}


/*
    �Լ� �̸� : EmployInfo::EmployInfo
    ��� : ä�� ���� entity ������
*/
EmployInfo::EmployInfo() {

}
/*
    �Լ� �̸� : EmployInfo::EmployInfo
    ��� : ȸ���̸�, ���������, ����, ������, ��û �������� �Ķ���ͷ� ����ä�� ���� entity ������
*/
EmployInfo::EmployInfo(string companyName, int businessNumber, string work, int employCount, string deadLine) {
    this->companyName = companyName;
    this->businessNumber = businessNumber;
    this->work = work;
    this->employCount = employCount;
    this->deadLine = deadLine;
}
/*
    �Լ� �̸� : EmployInfo::getEmployInfoDetails
    ��� : ä�� ������ ����, ������, ��û �������� string���� ��ȯ��
*/
string EmployInfo::getEmployInfoDetails() {
    string count = to_string(employCount);
    string details = work + " " + count + " " + deadLine;
    return details;
}

/*
    �Լ� �̸� : EmployInfo::getEmployInfoDetails
    ��� : ä�� ������ ������
*/
EmployInfo EmployInfo::getEmployInfo() {
    return *this;
}

/*
    �Լ� �̸� : EmployInfo::increaseApplyCount
    ��� : ä�� ������ ������ ���� +1 ��.
*/
void EmployInfo::increaseApplyCount() {
    applyCount++;
}
/*
    �Լ� �̸� : EmployInfo::increaseApplyCount
    ��� : ä�� ������ ������ ���� -1 ��.
*/
void EmployInfo::decreaseApplyCount() {
    applyCount--;
}

/*
    �Լ� �̸� :EmployInfoCollection::EmployInfoCollection
    ��� : ä�� ���� ����Ʈ ������
*/
EmployInfoCollection::EmployInfoCollection() {

}
/*
    �Լ� �̸� :EmployInfoCollection::addEmployInfo
    ��� : ���ο� ä�������� ä�� ���� ����Ʈ�� �߰���.
*/
void EmployInfoCollection::addEmployInfo(EmployInfo newEmployInfo) {
    employInfos.push_back(newEmployInfo);
}
/*
    �Լ� �̸� :EmployInfoCollection::getEmployInfos
    ��� : ä�� ���� ����Ʈ�� ������.
*/
vector<EmployInfo> EmployInfoCollection::getEmployInfos() {
    return employInfos;
}

/*
    �Լ��̸�: EmployInfo::getCompanyName
    ���: ä�� ������ ȸ�� �̸��� ��ȯ��.
*/
string EmployInfo::getCompanyName() {
    return companyName;
}

/*
    �Լ��̸�: EmployInfo::getBusinessNumber
    ���: ä�� ������ ����� ��ȣ�� ��ȯ��.
*/
int EmployInfo::getBusinessNumber() {
    return businessNumber;
}
/*
    �Լ� �̸� : ApplyInfo::getWork
    ��� : ������ ��ȯ��
*/
string EmployInfo::getWork() {
    return work;
}
/*
    �Լ� �̸� : ApplyInfo::getEmployCount
    ��� : ������ ���� ��ȯ��
*/
int EmployInfo::getEmployCount() {
    return employCount;
}

/*
    �Լ� �̸� : ApplyInfo::getApplyCount
    ��� : �������� ��ȯ��
*/
int EmployInfo::getApplyCount() {
    return applyCount;
}

/*
    �Լ��̸�: EmployInfo::getBusinessNumber
    ���: ä�� ������ ����� ��ȣ�� ��ȯ��.
*/
string EmployInfo::getDeadline() {
    return deadLine;
}

/*
    �Լ� �̸� : ApplyInfoCollection::addApplyInfo
    ��� : ���ο� ���� ������ ���� ���� ����Ʈ�� �߰���.
*/
void ApplyInfoCollection::addApplyInfo(ApplyInfo newApplyInfo) {
    applyInfoList.push_back(newApplyInfo);
}


/*
    �Լ� �̸� : ApplyInfo::ApplyInfo
    ��� : ���� ���� Entity ������
*/
ApplyInfo::ApplyInfo() {

}

/*
    �Լ� �̸� : ApplyInfo::ApplyInfo
    ��� : ȸ���̸�, ����ڹ�ȣ, ����, ������, �������� ���� ���� ���� �ʱⰪ ���� ������
*/
ApplyInfo::ApplyInfo( string companyName, int businessNumber, string work, int employCount, string deadLine) {
    this->companyName = companyName;
    this->businessNumber = businessNumber;
    this->work = work;
    this->employCount = employCount;
    this->deadLine = deadLine;
}

/*
    �Լ� �̸� : ApplyInfo::getCompanyName
    ��� : ȸ�� �̸��� ��ȯ��
*/
string ApplyInfo::getCompanyName()  {
    return companyName;
}

/*
    �Լ� �̸� : ApplyInfo::getBusinessNumber
    ��� : ����ڹ�ȣ�� ��ȯ��
*/
int ApplyInfo::getBusinessNumber() {
    return businessNumber;
}

/*
    �Լ� �̸� : ApplyInfo::getWork
    ��� : ������ ��ȯ��
*/
string ApplyInfo::getWork() {
    return work;
}

/*
    �Լ� �̸� : ApplyInfo::getEmployCount
    ��� : ������ ���� ��ȯ��
*/
int ApplyInfo::getEmployCount() {
    return employCount;
}


/*
    �Լ� �̸� : ApplyInfo::getDeadLine
    ��� : �������� ��ȯ��
*/
string ApplyInfo::getDeadLine() {
    return deadLine;
}


vector<ApplyInfo>& ApplyInfoCollection::getApplyList()
{
    return applyInfoList;
}
