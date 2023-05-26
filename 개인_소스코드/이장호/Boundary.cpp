void JoinUI::startInterface(Join * join, FILE * in_fp, FILE * out_fp) {
    this->join = join;
    this->in_fp = in_fp;
    this->out_fp = out_fp;
    fprintf(out_fp, "1.1. 회원가입\n");
    selectMemberType();
    submitMemberInfo();
}

void JoinUI::selectMemberType() {
    int memberType;
    fscanf(in_fp,"%d ", &memberType);
    fprintf(out_fp, "> %d", memberType);
    join->setMemberType(memberType);
}

void JoinUI::submitMemberInfo() {
    string memberInfo, result;
    char tmp[MAX_STRING]; // fscanf를 받기 위한 임시 버퍼
    fscanf(in_fp,"%s", tmp);
    memberInfo = tmp; // 임시 버퍼의 문자열을 string memberInfo로 옮김
    result = this->join->addMember(memberInfo); // 회원가입 수행 후 결과(가입된 회원의 정보)를 문자열로 받아옴.
    fprintf(out_fp, "%s\n\n", result.c_str());
}


void LoginUI::startInterface(Login* login, FILE* in_fp, FILE* out_fp)
{
	this->in_fp = in_fp;
	this->out_fp = out_fp;
	this->login = login;
	fprintf(out_fp, "2.1. 로그인\n");
	submitInfo();
}

void LoginUI::submitInfo() {
	string id, password, result;
	char tmp1[MAX_STRING], tmp2[MAX_STRING]; // 입력을 받기 위한 임시 char배열
	fscanf(in_fp, "%s %s", tmp1, tmp2);
	id = tmp1;
	password = tmp2;
	result = login->authenticateMember(id, password);
	fprintf(out_fp, "%s\n\n", result.c_str());
}


void LogoutUI::startInterface(Logout* logout, FILE* in_fp, FILE* out_fp) {
	this->in_fp = in_fp;
	this->out_fp = out_fp;
	this->logout = logout;
	fprintf(out_fp, "2.2. 로그아웃\n");
	confirmLogout();
}

void LogoutUI::confirmLogout() {
	string logoutID = logout->processLogout();
	fprintf(out_fp, "> %s\n\n", logoutID.c_str());
}


void WithdrawUI::startInterface(Withdraw* withdraw, FILE* in_fp, FILE* out_fp)
{
	this->withdraw = withdraw;
	this->in_fp = in_fp;
	this->out_fp = out_fp;
	fprintf(out_fp, "1.2. 회원탈퇴\n");
	confirmWithdrawal();
}

void WithdrawUI::confirmWithdrawal() {
	string deletedMember = withdraw->deleteMember();
	fprintf(out_fp, "> %s\n\n", deletedMember.c_str());
}