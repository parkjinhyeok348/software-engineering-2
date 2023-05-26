#include "stdcol.h"
#include"entity.h"
#include"boundary.h"

extern EmployInfoCollection employInfoCollection;

/*
    함수 이름 : Member::isPasswordCorrect
    기능 : 매개변수로 전달된 비밀번호가 저장된 비밀번호와 일치하는지 확인함
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
    함수 이름 : Member::getID
    기능 : 회원의 ID를 반환함
*/
string Member::getID()
{
    return this->id;
}

/*
    함수 이름 : Member::getPassword
    기능 : 회원의 Password를 반환함
*/
string Member::getPassword()
{
    return this->password;
}

/*
    함수 이름 : Member::setId
    기능 : 회원의 ID를 설정함
*/
void Member::setId(string id)
{
    this->id = id;
}

/*
    함수 이름 : Member::setPassword
    기능 : 회원의 Password를 설정함
*/
void Member::setPassword(string password)
{
    this->password = password;
}

/*
    함수 이름 : GeneralMember::GeneralMember
    기능 : GeneralMember의 기본 생성자
*/
GeneralMember::GeneralMember() {

}

/*
    함수 이름 : GeneralMember::GeneralMember
    기능 : GeneralMember의 초기값 설정 생성자
*/
GeneralMember::GeneralMember(string id, string password, string name, int ssn)
{
    this->setId(id);
    this->setPassword(password); // id, password는 상위 클래스의 private 변수이므로 setter로 접근함.
    this->name = name;
    this->ssn = ssn;
    this->ownedApplyInfoCollection = new ApplyInfoCollection;
}

/*
    함수 이름 : GeneralMember::getOwnedApplyInfoCollection
    기능 : 일반 회원이 보유중인 ApplyInfoCollection의 주소를 반환함
*/
ApplyInfoCollection* GeneralMember::getOwnedApplyInfoCollection()
{
    return ownedApplyInfoCollection;
}

/*
    함수 이름 : GeneralMember::getMemberInfo
    기능 : 일반 회원의 정보를 문자열로 반환함
*/
string GeneralMember::getMemberInfo()
{
    stringstream ss;
    ss << this->name << " " << this->ssn << " " << getID() << " " << this->getPassword();
    return ss.str();
}

/*
   함수 이름 : GeneralMember::getStats
   기능 : 일반 회원의 업무별 지원 횟수 통계를 문자열로 반환함
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
    함수 이름 : CompanyMember::CompanyMember
    기능 : CompanyMember의 기본 생성자
*/
CompanyMember::CompanyMember() {

}

/*
    함수 이름 : CompanyMember::CompanyMember
    기능 : CompanyMember의 초기값 설정 생성자
*/
CompanyMember::CompanyMember(string id, string password, string companyName, int businessNumber)
{
    this->setId(id);
    this->setPassword(password);
    this->companyName = companyName;
    this->businessNumber = businessNumber;
}


/*
    함수 이름 : CompanyMember::getMemberInfo
    기능 : 회사 회원의 정보를 문자열로 반환함
*/
string CompanyMember::getMemberInfo()
{
    stringstream ss;
    ss << this->companyName << " " << this->businessNumber << " " << this->getID() << " " << this->getPassword();
    return ss.str();
}

/*
    함수 이름 : CompanyMember::getStats
    기능 : 회사 회원의 업무별 지원 횟수 통계를 문자열로 반환함
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
    함수 이름 : MemberCollection::getCurrentMember
    기능 : 현재 로그인 된 회원의 주소를 반환함
*/
Member* MemberCollection::getCurrentMember()
{
    return getMemberCollection()->findByID(currentMemberID);
}

/*
    함수 이름 : MemberCollection::setCurrentMember
    기능 : 현재 로그인 된 회원의 ID를 새로 설정함
*/
void MemberCollection::setCurrentMember(string newCurrentMember)
{
    currentMemberID = newCurrentMember;
}

/*
    함수 이름 : MemberCollection::getMemberList
    기능 : MemberCollection Instance가 없으면 생성하고, 포인터를 반환함
*/
MemberCollection* MemberCollection::getMemberCollection()
{
    if (memberList == NULL) {
        memberList = new MemberCollection;
    }
    return memberList;
}

/*
    함수 이름 : MemberCollection::findByID
    기능 : ID에 해당하는 회원 정보의 포인터를 반환함
*/
Member* MemberCollection::findByID(string id)
{
    return members[id];
}

/*
    함수 이름 : MemberCollection::deleteCurrentMember
    기능 : 현재 로그인 된 회원을 Collection에서 제거함
*/
void MemberCollection::deleteCurrentMember() {
    members.erase(currentMemberID);
}

/*
    함수 이름 : MemberCollection::addGeneralMember
    기능 : 일반 회원을 회원 Collection에 등록함
*/
Member* MemberCollection::addGeneralMember(string id, string password, string name, int ssn)
{
    GeneralMember* newMember = new GeneralMember(id, password, name, ssn);
    members.insert(make_pair(id, newMember));
    return members[id];
}

/*
    함수 이름 : MemberCollection::addCompanyMember
    기능 : 일반 회원을 회원 Collection에 등록함
*/
Member* MemberCollection::addCompanyMember(string id, string password, string companyName, int businessNumber)
{
    CompanyMember* newMember = new CompanyMember(id, password, companyName, businessNumber);
    members.insert(make_pair(id, newMember));
    return members[id];
}


/*
    함수 이름 : EmployInfo::EmployInfo
    기능 : 채용 정보 entity 생성자
*/
EmployInfo::EmployInfo() {

}
/*
    함수 이름 : EmployInfo::EmployInfo
    기능 : 회사이름, 사업자정보, 업무, 지원수, 신청 마감일을 파라미터로 갖는채용 정보 entity 생성자
*/
EmployInfo::EmployInfo(string companyName, int businessNumber, string work, int employCount, string deadLine) {
    this->companyName = companyName;
    this->businessNumber = businessNumber;
    this->work = work;
    this->employCount = employCount;
    this->deadLine = deadLine;
}
/*
    함수 이름 : EmployInfo::getEmployInfoDetails
    기능 : 채용 정보의 업무, 지원수, 신청 마감일을 string으로 반환함
*/
string EmployInfo::getEmployInfoDetails() {
    string count = to_string(employCount);
    string details = work + " " + count + " " + deadLine;
    return details;
}

/*
    함수 이름 : EmployInfo::getEmployInfoDetails
    기능 : 채용 정보를 리턴함
*/
EmployInfo EmployInfo::getEmployInfo() {
    return *this;
}

/*
    함수 이름 : EmployInfo::increaseApplyCount
    기능 : 채용 정보의 지원자 수를 +1 함.
*/
void EmployInfo::increaseApplyCount() {
    applyCount++;
}
/*
    함수 이름 : EmployInfo::increaseApplyCount
    기능 : 채용 정보의 지원자 수를 -1 함.
*/
void EmployInfo::decreaseApplyCount() {
    applyCount--;
}

/*
    함수 이름 :EmployInfoCollection::EmployInfoCollection
    기능 : 채용 정보 리스트 생성자
*/
EmployInfoCollection::EmployInfoCollection() {

}
/*
    함수 이름 :EmployInfoCollection::addEmployInfo
    기능 : 새로운 채용정보를 채용 정보 리스트에 추가함.
*/
void EmployInfoCollection::addEmployInfo(EmployInfo newEmployInfo) {
    employInfos.push_back(newEmployInfo);
}
/*
    함수 이름 :EmployInfoCollection::getEmployInfos
    기능 : 채용 정보 리스트를 리턴함.
*/
vector<EmployInfo> EmployInfoCollection::getEmployInfos() {
    return employInfos;
}

/*
    함수이름: EmployInfo::getCompanyName
    기능: 채용 정보의 회사 이름을 반환함.
*/
string EmployInfo::getCompanyName() {
    return companyName;
}

/*
    함수이름: EmployInfo::getBusinessNumber
    기능: 채용 정보의 사업자 번호를 반환함.
*/
int EmployInfo::getBusinessNumber() {
    return businessNumber;
}
/*
    함수 이름 : ApplyInfo::getWork
    기능 : 업무를 반환함
*/
string EmployInfo::getWork() {
    return work;
}
/*
    함수 이름 : ApplyInfo::getEmployCount
    기능 : 지원자 수를 반환함
*/
int EmployInfo::getEmployCount() {
    return employCount;
}

/*
    함수 이름 : ApplyInfo::getApplyCount
    기능 : 지원수를 반환함
*/
int EmployInfo::getApplyCount() {
    return applyCount;
}

/*
    함수이름: EmployInfo::getBusinessNumber
    기능: 채용 정보의 사업자 번호를 반환함.
*/
string EmployInfo::getDeadline() {
    return deadLine;
}

/*
    함수 이름 : ApplyInfoCollection::addApplyInfo
    기능 : 새로운 지원 정보를 지원 정보 리스트에 추가함.
*/
void ApplyInfoCollection::addApplyInfo(ApplyInfo newApplyInfo) {
    applyInfoList.push_back(newApplyInfo);
}


/*
    함수 이름 : ApplyInfo::ApplyInfo
    기능 : 지원 정보 Entity 생성자
*/
ApplyInfo::ApplyInfo() {

}

/*
    함수 이름 : ApplyInfo::ApplyInfo
    기능 : 회사이름, 사업자번호, 업무, 지원수, 마감일을 갖는 지원 정보 초기값 설정 생성자
*/
ApplyInfo::ApplyInfo( string companyName, int businessNumber, string work, int employCount, string deadLine) {
    this->companyName = companyName;
    this->businessNumber = businessNumber;
    this->work = work;
    this->employCount = employCount;
    this->deadLine = deadLine;
}

/*
    함수 이름 : ApplyInfo::getCompanyName
    기능 : 회사 이름을 반환함
*/
string ApplyInfo::getCompanyName()  {
    return companyName;
}

/*
    함수 이름 : ApplyInfo::getBusinessNumber
    기능 : 사업자번호를 반환함
*/
int ApplyInfo::getBusinessNumber() {
    return businessNumber;
}

/*
    함수 이름 : ApplyInfo::getWork
    기능 : 업무를 반환함
*/
string ApplyInfo::getWork() {
    return work;
}

/*
    함수 이름 : ApplyInfo::getEmployCount
    기능 : 지원자 수를 반환함
*/
int ApplyInfo::getEmployCount() {
    return employCount;
}


/*
    함수 이름 : ApplyInfo::getDeadLine
    기능 : 마감일을 반환함
*/
string ApplyInfo::getDeadLine() {
    return deadLine;
}


vector<ApplyInfo>& ApplyInfoCollection::getApplyList()
{
    return applyInfoList;
}
