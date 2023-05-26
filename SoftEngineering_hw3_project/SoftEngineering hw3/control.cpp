#include"stdcol.h"
#include "control.h"
#include "entity.h"
#include "boundary.h"

extern EmployInfoCollection employInfoCollection;
extern vector<string> split(string str, char dlim);


/*
    함수 이름 : Join::addMember
    기능 : 회원 정보를 받아 회원 목록에 회원을 등록하고 등록된 회원 정보를 반환함
*/
string Join::addMember(string info1, int info2, string id, string password){
    Member* newMember = NULL;
    if (this->memberType == 1) {
        newMember = MemberCollection::getMemberCollection()->addCompanyMember(id, password, info1, info2);
    }
    else if (this->memberType == 2) {
        newMember = MemberCollection::getMemberCollection()->addGeneralMember(id, password, info1, info2);
    }
    return newMember->getMemberInfo();
}

/*
    함수 이름 : Join::setMemberType
    기능 : 회원 종류(1: 회사 회원, 2: 일반 회원)을 입력받아 저장함
*/
void Join::setMemberType(int memberType)
{
    this->memberType = memberType;
}

/*
    함수 이름 : Join::run
    기능 : 생성된 회원 가입 Control의 기능을 시작함
*/
void Join::run()
{
    JoinUI* joinUI = new JoinUI;
    joinUI->startInterface(this);
}

/*
    함수 이름 : Login::run
    기능 : 생성된 로그인 Control의 기능을 시작함
*/
void Login::run()
{
    LoginUI* loginUI = new LoginUI;
    loginUI->startInterface(this);
}

/*
    함수 이름 : Login::authenticateMember
    기능 : 입력받은 ID, 비밀번호를 통해 회원을 인증하고, 회원 정보를 반환한다.
*/
string Login::authenticateMember(string id, string password) {
    string result;
    Member* member = MemberCollection::getMemberCollection()->findByID(id);
    if (member->isPasswordCorrect(password)) {
        MemberCollection::setCurrentMember(member->getID());
        result = member->getID() + " " + member->getPassword();
    }
    return result;
}


/*
    함수 이름 : Logout::run
    기능 : 생성된 로그아웃 Control의 기능을 시작함
*/
void Logout::run()
{
    LogoutUI* logoutUI = new LogoutUI;
    logoutUI->startInterface(this);
}

/*
    함수 이름 : Logout::processLogout
    기능 : 현재 로그인 된 회원을 로그아웃 처리하고 아이디를 반환함
*/
string Logout::processLogout()
{
    string logoutID = MemberCollection::getCurrentMember()->getID();
    MemberCollection::setCurrentMember("");
    return logoutID;
}


/*
    함수 이름 : Withdraw::deleteCurrentMember
    기능 : 현재 로그인 된 회원을 회원 가입, 로그아웃 처리하고 아이디를 반환함
*/
string Withdraw::deleteCurrentMember() {
    string deletedMemberID = MemberCollection::getCurrentMember()->getID();
    MemberCollection::getMemberCollection()->deleteCurrentMember();
    MemberCollection::setCurrentMember("");
    return deletedMemberID;
}

/*
    함수 이름 : Withdraw::run
    기능 : 생성된 회원 탈퇴 Control의 기능을 시작함
*/
void Withdraw::run()
{
    WithdrawUI* wdUI = new WithdrawUI;
    wdUI->startInterface(this);
}

/*
    함수 이름 :RegisterEmployInfo::RegisterEmployInfo
    기능 : RegisterEmployInfo 클래스 생성자
*/
RegisterEmployInfo::RegisterEmployInfo() {

}
/*
    함수 이름 :RegisterEmployInfo::registerEmployInfo
    기능 :채용 정보 리스트에 새로운 채용 정보 추가함
*/
void RegisterEmployInfo::registerEmpolyInfo(string work, int employCount, string deadline) {

    Member* currentMember = MemberCollection::getCurrentMember();
    string memberInfo = currentMember->getMemberInfo();
    vector<string> info = split(memberInfo, ' ');
    string companyName = info[0];
    int businessNumber = stoi(info[1]);
    EmployInfo newEmployInfo(companyName, businessNumber, work, employCount, deadline);
    employInfoCollection.addEmployInfo(newEmployInfo);
}

/*
    함수 이름 : AskEmployInfo::AskEmployInfo
    기능 :AskEmployInfo 클래스 생성자
*/
AskEmployInfo::AskEmployInfo() {} //생성자

/*
    함수 이름 : AskEmployInfo::showEmployInfo
    기능 :채용 정보 리스트에서 상세정보를 받아 반환함
*/
vector<string> AskEmployInfo::showEmployInfo() {
    vector<EmployInfo> employInfos;
    vector<string> detailList;
    employInfos = employInfoCollection.getEmployInfos();
    for (int i = 0; i < employInfos.size(); i++) {
        detailList.push_back(employInfos[i].getEmployInfoDetails());
    }
    return detailList;
}

/*
    함수 이름: SearchEmploy::start
    기능: 채용 정보 검색 control 기능 수행을 시작함
*/
void SearchEmploy::start()
{
    SearchEmployUI* searchEmployUI = new SearchEmployUI;
    searchEmployUI->startInterface();
}

/*
    함수 이름: SearchEmploy::doSearch
    기능: companyName을 받아서 채용 정보 검색 기능을 수행함
*/
string SearchEmploy::doSearch(string companyName) {
    string employInfoDetails;
    vector<EmployInfo> employInfos;
    employInfos = employInfoCollection.getEmployInfos();
    int businessNumber=0;
    string work;
    string deadLine;
    for (int i = 0; i < employInfos.size(); i++) {
        if (employInfos[i].getCompanyName() == companyName) {
            businessNumber = employInfos[i].getBusinessNumber();
            work = employInfos[i].getWork();
            deadLine = employInfos[i].getDeadline();
        }
    }
    string bn = to_string(businessNumber);
    employInfoDetails = companyName + " " + bn + " " + work + " " + deadLine;
    return employInfoDetails;
}

/*
    함수 이름: ApplyEmploy::start
    기능: 채용 지원 control 기능 수행을 시작함
*/
void ApplyEmploy::start()
{
    ApplyEmployUI* applyEmployUI = new ApplyEmployUI;
    applyEmployUI->startInterface();
}

/*
    함수 이름: ApplyEmploy::doApply
    기능: businessNumber을 받아서 채용 지원 기능을 수행함
*/
string ApplyEmploy::doApply(int businessNumber) {
    vector<EmployInfo> employInfos;
    employInfos = employInfoCollection.getEmployInfos();
    string companyName;
    string work;
    string deadLine;
    int employCount=0;
    for (int i = 0; i < employInfos.size(); i++) {
        if (employInfos[i].getBusinessNumber() == businessNumber) {
            companyName = employInfos[i].getCompanyName();
            work = employInfos[i].getWork();
            deadLine = employInfos[i].getDeadline();
            employCount = employInfos[i].getEmployCount();
            employInfos[i].increaseApplyCount();
        }
    }
    ApplyInfo* newApplyInfo;
    string applyInfoDetails;
    newApplyInfo = new ApplyInfo(companyName, businessNumber, work, employCount, deadLine);
    ApplyInfoCollection* applyInfoList = ((GeneralMember*)(MemberCollection::getCurrentMember()))->getOwnedApplyInfoCollection();
    applyInfoList->addApplyInfo(*newApplyInfo);

    string bn = to_string(businessNumber);
    applyInfoDetails = companyName + " " + bn + " " + work;
    return applyInfoDetails;
}

/*
    함수 이름 : ShowApplyInfo::ShowApplyInfo
    기능 :ShowApplyInfo 클래스 생성자
*/
ShowApplyInfo::ShowApplyInfo() {
    pGeneralMember = ((GeneralMember*)MemberCollection::getCurrentMember());
}

/*
    함수 이름 : ApplyInfo::compare()
    기능 : 지원정보를 회사이름 오름차순으로 정렬함
*/
bool ApplyInfo::compare(ApplyInfo a, ApplyInfo b) {
    return a.getCompanyName() < b.getCompanyName();
}

/*
    함수 이름 : ShowApplyInfo::viewApplyInfo
    기능 : 지원 정보를 받아 string으로 반환함
*/
string ShowApplyInfo::viewApplyInfo() {

    ApplyInfoCollection* applyInfoCollection = pGeneralMember->getOwnedApplyInfoCollection();

    vector<ApplyInfo> applyInfos = applyInfoCollection->getApplyList();
   
    sort(applyInfos.begin(), applyInfos.end(), ApplyInfo::compare);

    int listSize = applyInfos.size();

    string returnValue = "";

    for (int i = 0; i < listSize; i++)
    {
        returnValue.append(applyInfos[i].getCompanyName());
        returnValue.append(" ");
        returnValue.append(to_string(applyInfos[i].getBusinessNumber()));
        returnValue.append(" ");
        returnValue.append(applyInfos[i].getWork());
        returnValue.append(" ");
        returnValue.append(to_string(applyInfos[i].getEmployCount()));
        returnValue.append(" ");
        returnValue.append(applyInfos[i].getDeadLine());
        returnValue.append("\n");
    }

    return returnValue;
}

/*
    함수 이름 : ShowApplyStats::run
    기능 : 생성된 지원 통계 Control의 기능을 시작함
*/
void ShowApplyStats::run() {
    ShowApplyStatsUI* showApplyStatsUI = new ShowApplyStatsUI;
    showApplyStatsUI->startInterface(this);
}

/*
    함수 이름 : ShowApplyStats::showApplyStats
    기능 : 현재 로그인 된 회원의 지원 통계 정보를 반환함
*/
string ShowApplyStats::showApplyStats() {
    Member* currentMember = MemberCollection::getCurrentMember();
    return currentMember->getStats();
}

/*
    함수 이름 : CancelApplyInfo::CancelApplyInfo
    기능 :CancelApplyInfo 클래스 생성자
*/
CancelApplyInfo::CancelApplyInfo() {
    pGeneralMember = nullptr;
}

/*
    함수 이름 : CancelApplyInfo::CancelApplyInfo
    기능 :CancelApplyInfo 클래스 생성자
*/
CancelApplyInfo::CancelApplyInfo(GeneralMember* refGeneralMember) {
    pGeneralMember = refGeneralMember;
}

/*
    함수 이름 : CancelApplyInfo::cancelApply
    기능 : 지원 정보를 받아 입력한 사업자 번호와 일치하는 지원을 취소 처리하고, 취소한 지원 정보를 string으로 반환함
*/
string CancelApplyInfo::cancelApply(int businessNumber) {
    ApplyInfoCollection* applyInfoCollection = ((GeneralMember*)MemberCollection::getCurrentMember())->getOwnedApplyInfoCollection();
    vector<ApplyInfo>& cancelInfoList = applyInfoCollection->getApplyList();
    vector<EmployInfo> employlist = employInfoCollection.getEmployInfos();
    for (int i = 0; i < employlist.size(); i++) {
        if (employlist.at(i).getBusinessNumber() == businessNumber) {
            employlist.at(i).decreaseApplyCount();
        }
    }
    string returnValue = "";
    for (auto it = cancelInfoList.begin(); it != cancelInfoList.end(); it++)
        if ((it->getBusinessNumber() == businessNumber)) {
            returnValue.append(it->getCompanyName());
                returnValue.append("");
                returnValue.append(to_string(it->getBusinessNumber()));
                returnValue.append("");
                returnValue.append(it->getWork());
                returnValue.append("\n");
                cancelInfoList.erase(it);
                return returnValue;
        }
}
