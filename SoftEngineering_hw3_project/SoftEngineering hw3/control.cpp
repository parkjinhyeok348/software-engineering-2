#include"stdcol.h"
#include "control.h"
#include "entity.h"
#include "boundary.h"

extern EmployInfoCollection employInfoCollection;
extern vector<string> split(string str, char dlim);


/*
    �Լ� �̸� : Join::addMember
    ��� : ȸ�� ������ �޾� ȸ�� ��Ͽ� ȸ���� ����ϰ� ��ϵ� ȸ�� ������ ��ȯ��
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
    �Լ� �̸� : Join::setMemberType
    ��� : ȸ�� ����(1: ȸ�� ȸ��, 2: �Ϲ� ȸ��)�� �Է¹޾� ������
*/
void Join::setMemberType(int memberType)
{
    this->memberType = memberType;
}

/*
    �Լ� �̸� : Join::run
    ��� : ������ ȸ�� ���� Control�� ����� ������
*/
void Join::run()
{
    JoinUI* joinUI = new JoinUI;
    joinUI->startInterface(this);
}

/*
    �Լ� �̸� : Login::run
    ��� : ������ �α��� Control�� ����� ������
*/
void Login::run()
{
    LoginUI* loginUI = new LoginUI;
    loginUI->startInterface(this);
}

/*
    �Լ� �̸� : Login::authenticateMember
    ��� : �Է¹��� ID, ��й�ȣ�� ���� ȸ���� �����ϰ�, ȸ�� ������ ��ȯ�Ѵ�.
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
    �Լ� �̸� : Logout::run
    ��� : ������ �α׾ƿ� Control�� ����� ������
*/
void Logout::run()
{
    LogoutUI* logoutUI = new LogoutUI;
    logoutUI->startInterface(this);
}

/*
    �Լ� �̸� : Logout::processLogout
    ��� : ���� �α��� �� ȸ���� �α׾ƿ� ó���ϰ� ���̵� ��ȯ��
*/
string Logout::processLogout()
{
    string logoutID = MemberCollection::getCurrentMember()->getID();
    MemberCollection::setCurrentMember("");
    return logoutID;
}


/*
    �Լ� �̸� : Withdraw::deleteCurrentMember
    ��� : ���� �α��� �� ȸ���� ȸ�� ����, �α׾ƿ� ó���ϰ� ���̵� ��ȯ��
*/
string Withdraw::deleteCurrentMember() {
    string deletedMemberID = MemberCollection::getCurrentMember()->getID();
    MemberCollection::getMemberCollection()->deleteCurrentMember();
    MemberCollection::setCurrentMember("");
    return deletedMemberID;
}

/*
    �Լ� �̸� : Withdraw::run
    ��� : ������ ȸ�� Ż�� Control�� ����� ������
*/
void Withdraw::run()
{
    WithdrawUI* wdUI = new WithdrawUI;
    wdUI->startInterface(this);
}

/*
    �Լ� �̸� :RegisterEmployInfo::RegisterEmployInfo
    ��� : RegisterEmployInfo Ŭ���� ������
*/
RegisterEmployInfo::RegisterEmployInfo() {

}
/*
    �Լ� �̸� :RegisterEmployInfo::registerEmployInfo
    ��� :ä�� ���� ����Ʈ�� ���ο� ä�� ���� �߰���
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
    �Լ� �̸� : AskEmployInfo::AskEmployInfo
    ��� :AskEmployInfo Ŭ���� ������
*/
AskEmployInfo::AskEmployInfo() {} //������

/*
    �Լ� �̸� : AskEmployInfo::showEmployInfo
    ��� :ä�� ���� ����Ʈ���� �������� �޾� ��ȯ��
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
    �Լ� �̸�: SearchEmploy::start
    ���: ä�� ���� �˻� control ��� ������ ������
*/
void SearchEmploy::start()
{
    SearchEmployUI* searchEmployUI = new SearchEmployUI;
    searchEmployUI->startInterface();
}

/*
    �Լ� �̸�: SearchEmploy::doSearch
    ���: companyName�� �޾Ƽ� ä�� ���� �˻� ����� ������
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
    �Լ� �̸�: ApplyEmploy::start
    ���: ä�� ���� control ��� ������ ������
*/
void ApplyEmploy::start()
{
    ApplyEmployUI* applyEmployUI = new ApplyEmployUI;
    applyEmployUI->startInterface();
}

/*
    �Լ� �̸�: ApplyEmploy::doApply
    ���: businessNumber�� �޾Ƽ� ä�� ���� ����� ������
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
    �Լ� �̸� : ShowApplyInfo::ShowApplyInfo
    ��� :ShowApplyInfo Ŭ���� ������
*/
ShowApplyInfo::ShowApplyInfo() {
    pGeneralMember = ((GeneralMember*)MemberCollection::getCurrentMember());
}

/*
    �Լ� �̸� : ApplyInfo::compare()
    ��� : ���������� ȸ���̸� ������������ ������
*/
bool ApplyInfo::compare(ApplyInfo a, ApplyInfo b) {
    return a.getCompanyName() < b.getCompanyName();
}

/*
    �Լ� �̸� : ShowApplyInfo::viewApplyInfo
    ��� : ���� ������ �޾� string���� ��ȯ��
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
    �Լ� �̸� : ShowApplyStats::run
    ��� : ������ ���� ��� Control�� ����� ������
*/
void ShowApplyStats::run() {
    ShowApplyStatsUI* showApplyStatsUI = new ShowApplyStatsUI;
    showApplyStatsUI->startInterface(this);
}

/*
    �Լ� �̸� : ShowApplyStats::showApplyStats
    ��� : ���� �α��� �� ȸ���� ���� ��� ������ ��ȯ��
*/
string ShowApplyStats::showApplyStats() {
    Member* currentMember = MemberCollection::getCurrentMember();
    return currentMember->getStats();
}

/*
    �Լ� �̸� : CancelApplyInfo::CancelApplyInfo
    ��� :CancelApplyInfo Ŭ���� ������
*/
CancelApplyInfo::CancelApplyInfo() {
    pGeneralMember = nullptr;
}

/*
    �Լ� �̸� : CancelApplyInfo::CancelApplyInfo
    ��� :CancelApplyInfo Ŭ���� ������
*/
CancelApplyInfo::CancelApplyInfo(GeneralMember* refGeneralMember) {
    pGeneralMember = refGeneralMember;
}

/*
    �Լ� �̸� : CancelApplyInfo::cancelApply
    ��� : ���� ������ �޾� �Է��� ����� ��ȣ�� ��ġ�ϴ� ������ ��� ó���ϰ�, ����� ���� ������ string���� ��ȯ��
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
