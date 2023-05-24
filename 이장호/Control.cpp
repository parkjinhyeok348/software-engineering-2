#include "Control.h"

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

void Login::run(FILE* in_fp, FILE* out_fp)
{
	LoginUI * loginUI = new LoginUI;
	loginUI->startInterface(this, in_fp, out_fp);
}

string Login::authenticateMember(string id, string password) {
	string result;
	Member** member = MemberList::getMemberList()->findByID(id);
	if ((*member)->isPasswordCorrect(password)) {
		Member::setCurrentMember(member);
		result = (*member)->getID() + " " + (*member)->getPassword();
	}
	return result;
}

void Logout::run(FILE* in_fp, FILE* out_fp)
{
	LogoutUI* logoutUI = new LogoutUI;
	logoutUI->startInterface(this, in_fp, out_fp);
}

string Logout::processLogout()
{
	string logoutID = (*Member::getCurrentMember())->getID(); // 로그아웃될 아이디를 저장
	(*Member::getCurrentMember())->setLoginStatus(false); // 현재 로그인 된 회원을 로그아웃 상태로 변경
	Member::setCurrentMember(NULL); // 현재 회원의 주소를 NULL(아무도 선택되지 않은 상태)로 변경한다.
	return logoutID; // 로그아웃된 회원 아이디를 반환한다.
}


string Withdraw::deleteMember() {
    string deletedMemberID = (*Member::getCurrentMember())->getID(); // 탈퇴될 회원의 ID 저장
    MemberList::getMemberList()->deleteMember(Member::getCurrentMember()); // 회원 탈퇴 처리
    return deletedMemberID;
}

void Withdraw::run(FILE* in_fp, FILE* out_fp)
{
    WithdrawUI* wdUI = new WithdrawUI;
    wdUI->startInterface(this, in_fp, out_fp);
}
