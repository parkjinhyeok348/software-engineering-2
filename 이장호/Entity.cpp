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