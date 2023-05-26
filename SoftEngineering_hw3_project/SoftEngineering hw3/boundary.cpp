#include "stdcol.h"
#include "boundary.h"
#include "control.h"

extern ofstream out_fp;
extern ifstream in_fp;


/*
	함수 이름 : JoinUI::startInterface
	기능 : 통신할 Control의 포인터를 저장하며, 사용자와의 상호작용을 시작함
*/
void JoinUI::startInterface(Join* join) {
	this->join = join;
	out_fp << "1.1. 회원가입\n";
	selectMemberType();
	submitMemberInfo();
}

/*
	함수 이름 : JoinUI::selectMemberType
	기능 : 사용자에게서 회원 종류를 1 혹은 2로 입력받아 Control에 전달함
*/
void JoinUI::selectMemberType() {
	int memberType;
	in_fp >> memberType;
	out_fp << "> " << memberType << " ";
	join->setMemberType(memberType);
}

/*
	함수 이름 : JoinUI::submitMemberInfo
	기능 : 사용자에게서 회원 정보를 입력받아와 Control에 전달함
*/
void JoinUI::submitMemberInfo() {
	string info1, id, password, result;
	int info2;
	in_fp >> info1 >> info2 >> id >> password;
	result = this->join->addMember(info1, info2, id, password);
	out_fp << result << "\n\n";
}

/*
	함수 이름 : LoginUI::startInterface
	기능 : 통신할 Control의 포인터를 저장하며, 사용자와의 상호작용을 시작함
*/
void LoginUI::startInterface(Login* login)
{
	this->login = login;
	out_fp << "2.1. 로그인\n";
	submitInfo();
}

/*
	함수 이름 : JoinUI::submitInfo
	기능 : 사용자에게서 회원 정보를 입력받아와 Control에 로그인 처리를 요청함
*/
void LoginUI::submitInfo() {
	string id, password, result;
	in_fp >> id >> password;
	result = login->authenticateMember(id, password);
	out_fp << "> " << result << "\n\n";
}

/*
	함수 이름 : LogoutUI::startInterface
	기능 : 통신할 Control의 포인터를 저장하며, 사용자와의 상호작용을 시작함
*/
void LogoutUI::startInterface(Logout* logout) {
	this->logout = logout;
	out_fp << "2.2. 로그아웃\n";
	confirmLogout();
}

/*
	함수 이름 : LogoutUI::submitInfo
	기능 : 사용자의 로그아웃 요청을 처리하고 사용자 ID를 출력함
*/
void LogoutUI::confirmLogout() {
	string logoutID = logout->processLogout();
	out_fp << "> " << logoutID << "\n\n";
}

/*
	함수 이름 : WithdrawUI::startInterface
	기능 : 통신할 Control의 포인터를 저장하며, 사용자와의 상호작용을 시작함
*/
void WithdrawUI::startInterface(Withdraw* withdraw)
{
	this->withdraw = withdraw;
	out_fp << "1.2. 회원탈퇴\n";
	confirmWithdrawal();
}

/*
	함수 이름 : WithdrawUI::confirmWithdrawal
	기능 : 사용자의 회원탈퇴 요청을 처리하고 사용자 ID를 출력함
*/
void WithdrawUI::confirmWithdrawal() {
	string deletedMember = withdraw->deleteCurrentMember();
	out_fp << "> " << deletedMember << "\n\n";
}

//클래스 선언
RegisterEmployInfo registerEmployInfo;

/*
	함수 이름 :RegisterEmployInfoUI::RegisterEmployInfoUI
	기능 : RegisterEmployInfoUI 클래스 생성자
*/
RegisterEmployInfoUI::RegisterEmployInfoUI() {

}
/*
	함수 이름 :RegisterEmployInfoUI::inputEmployInfo
	기능 : 업무,지원수,신청 마감일 입력 받음
*/
void RegisterEmployInfoUI::inputEmployInfo() {
	string work;
	int employCount;
	string deadline;
	in_fp >> work >> employCount >> deadline;
	createNewEmployInfo(work, employCount, deadline);
}
/*
	함수 이름 :RegisterEmployInfoUI::createNewEmployInfo
	기능 : control 클래스에 업무,지원수, 신청 마감일을 전달 후 output.txt 에 출력함
*/
void RegisterEmployInfoUI::createNewEmployInfo(string work, int employCount, string deadline) {
	registerEmployInfo.registerEmpolyInfo(work, employCount, deadline);
	out_fp << "3.1 채용 정보 등록" << endl;
	out_fp << "> " << work << " " << employCount << " " << deadline << "\n\n";
}

//클래스 선언
AskEmployInfo askEmployInfo;

/*
	함수 이름 :AskEmployInfoUI::AskEmployInfoUI
	기능 : AskEmployInfoUI 클래스 생성자
*/
AskEmployInfoUI::AskEmployInfoUI() {}

/*
	함수 이름 :AskEmployInfoUI::ask
	기능 : control 클래스에 회사회원이 등록한 채용 정보 리스트 요청하여 출력함
*/
void AskEmployInfoUI::ask() {
	vector<string>detailList;
	out_fp << "3.2 채용 정보 조회" << endl;
	detailList = askEmployInfo.showEmployInfo();
	out_fp << "> ";
	for (int i = 0; i < detailList.size(); i++) {
		out_fp << detailList[i] << "\n\n";
	}
}
 
/*
	함수 이름: SearchEmployUI::startInterface
	기능: 통신할 Control의 포인터를 저장하며, 사용자와의 상호작용을 시작함
*/
void SearchEmployUI::startInterface() {
	out_fp << "4.1. 채용 정보 검색" << "\n";
	search();
}

/*
	함수 이름: SearchEmployUI::search
	기능: 채용 정보 검색을 수행하고 채용 정보의 내용(companyName, businessName, work, employCount, deadline)을 출력함
*/
void SearchEmployUI::search() {
	string companyName;
	string employInfoDetails;
	in_fp >> companyName;
	employInfoDetails = searchEmploy->doSearch(companyName);
	out_fp << "> " << employInfoDetails << "\n\n";
}

/*
	함수 이름: ApplyEmployUI::startInterface
	기능: 통신할 Control의 포인터를 저장하며, 사용자와의 상호작용을 시작함
*/
void ApplyEmployUI::startInterface() {
	out_fp << "4.2. 채용 지원" << "\n";
	apply();
}

/*
	함수 이름: ApplyEmployUI::apply
	기능: 채용 지원을 수행하고 채용 지원의 내용(companyName, businessName, work)을 출력함
*/
void ApplyEmployUI::apply() {
	int businessNumber;
	string applyInfoDetails;
	in_fp >> businessNumber;
	applyInfoDetails = applyEmploy->doApply(businessNumber);
	out_fp << "> " << applyInfoDetails << "\n\n";
}

/*
	함수 이름 : ShowApplyInfoUI::clickApplyInfo
	기능 : 회사이름, 사업자번호, 업무, 인원 수, 신청마감일을 담은 지원 정보 string을 출력함
*/
void ShowApplyInfoUI::clickApplyInfo()
{
	out_fp << "4.3. 지원 정보 조회" << endl;

	control = new ShowApplyInfo();
	string result = control->viewApplyInfo();

	out_fp << "> " << result << "\n";
};


/*
	함수 이름 : ShowApplyStatsUI::startInterface
	기능 : 통신할 Control의 포인터를 저장하고, 사용자와의 상호작용을 시작함
*/
void ShowApplyStatsUI::startInterface(ShowApplyStats* showApplyStats) {
	this->showApplyStats = showApplyStats;
	out_fp << "5.1. 지원 정보 출력\n";
	printApplyStats();
}

/*
	함수 이름 : ShowApplyStatsUI::printApplyStats
	기능 : 업무별 지원 통계를 출력함
*/
void ShowApplyStatsUI::printApplyStats() {
	string result = showApplyStats->showApplyStats();
	out_fp << "> " << result << "\n";
}

/*
	함수 이름 : CancelApplyInfoUI::selectCancelApply
	기능 : 취소한 지원 정보(회사이름, 사업자번호, 업무)를 담은 string을 출력함
*/
void CancelApplyInfoUI::selectCancelApply()
{
	string companyName, work;
	int businessNumber;

	in_fp >> businessNumber;
	out_fp << "4.4. 지원 취소" << endl;

	control = new CancelApplyInfo();
	string result = control->cancelApply(businessNumber);

	out_fp << "> " << result << "\n\n";
};

