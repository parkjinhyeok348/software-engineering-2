#include "stdcol.h"
#include "boundary.h"
#include "control.h"

extern ofstream out_fp;
extern ifstream in_fp;


/*
	�Լ� �̸� : JoinUI::startInterface
	��� : ����� Control�� �����͸� �����ϸ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void JoinUI::startInterface(Join* join) {
	this->join = join;
	out_fp << "1.1. ȸ������\n";
	selectMemberType();
	submitMemberInfo();
}

/*
	�Լ� �̸� : JoinUI::selectMemberType
	��� : ����ڿ��Լ� ȸ�� ������ 1 Ȥ�� 2�� �Է¹޾� Control�� ������
*/
void JoinUI::selectMemberType() {
	int memberType;
	in_fp >> memberType;
	out_fp << "> " << memberType << " ";
	join->setMemberType(memberType);
}

/*
	�Լ� �̸� : JoinUI::submitMemberInfo
	��� : ����ڿ��Լ� ȸ�� ������ �Է¹޾ƿ� Control�� ������
*/
void JoinUI::submitMemberInfo() {
	string info1, id, password, result;
	int info2;
	in_fp >> info1 >> info2 >> id >> password;
	result = this->join->addMember(info1, info2, id, password);
	out_fp << result << "\n\n";
}

/*
	�Լ� �̸� : LoginUI::startInterface
	��� : ����� Control�� �����͸� �����ϸ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void LoginUI::startInterface(Login* login)
{
	this->login = login;
	out_fp << "2.1. �α���\n";
	submitInfo();
}

/*
	�Լ� �̸� : JoinUI::submitInfo
	��� : ����ڿ��Լ� ȸ�� ������ �Է¹޾ƿ� Control�� �α��� ó���� ��û��
*/
void LoginUI::submitInfo() {
	string id, password, result;
	in_fp >> id >> password;
	result = login->authenticateMember(id, password);
	out_fp << "> " << result << "\n\n";
}

/*
	�Լ� �̸� : LogoutUI::startInterface
	��� : ����� Control�� �����͸� �����ϸ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void LogoutUI::startInterface(Logout* logout) {
	this->logout = logout;
	out_fp << "2.2. �α׾ƿ�\n";
	confirmLogout();
}

/*
	�Լ� �̸� : LogoutUI::submitInfo
	��� : ������� �α׾ƿ� ��û�� ó���ϰ� ����� ID�� �����
*/
void LogoutUI::confirmLogout() {
	string logoutID = logout->processLogout();
	out_fp << "> " << logoutID << "\n\n";
}

/*
	�Լ� �̸� : WithdrawUI::startInterface
	��� : ����� Control�� �����͸� �����ϸ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void WithdrawUI::startInterface(Withdraw* withdraw)
{
	this->withdraw = withdraw;
	out_fp << "1.2. ȸ��Ż��\n";
	confirmWithdrawal();
}

/*
	�Լ� �̸� : WithdrawUI::confirmWithdrawal
	��� : ������� ȸ��Ż�� ��û�� ó���ϰ� ����� ID�� �����
*/
void WithdrawUI::confirmWithdrawal() {
	string deletedMember = withdraw->deleteCurrentMember();
	out_fp << "> " << deletedMember << "\n\n";
}

//Ŭ���� ����
RegisterEmployInfo registerEmployInfo;

/*
	�Լ� �̸� :RegisterEmployInfoUI::RegisterEmployInfoUI
	��� : RegisterEmployInfoUI Ŭ���� ������
*/
RegisterEmployInfoUI::RegisterEmployInfoUI() {

}
/*
	�Լ� �̸� :RegisterEmployInfoUI::inputEmployInfo
	��� : ����,������,��û ������ �Է� ����
*/
void RegisterEmployInfoUI::inputEmployInfo() {
	string work;
	int employCount;
	string deadline;
	in_fp >> work >> employCount >> deadline;
	createNewEmployInfo(work, employCount, deadline);
}
/*
	�Լ� �̸� :RegisterEmployInfoUI::createNewEmployInfo
	��� : control Ŭ������ ����,������, ��û �������� ���� �� output.txt �� �����
*/
void RegisterEmployInfoUI::createNewEmployInfo(string work, int employCount, string deadline) {
	registerEmployInfo.registerEmpolyInfo(work, employCount, deadline);
	out_fp << "3.1 ä�� ���� ���" << endl;
	out_fp << "> " << work << " " << employCount << " " << deadline << "\n\n";
}

//Ŭ���� ����
AskEmployInfo askEmployInfo;

/*
	�Լ� �̸� :AskEmployInfoUI::AskEmployInfoUI
	��� : AskEmployInfoUI Ŭ���� ������
*/
AskEmployInfoUI::AskEmployInfoUI() {}

/*
	�Լ� �̸� :AskEmployInfoUI::ask
	��� : control Ŭ������ ȸ��ȸ���� ����� ä�� ���� ����Ʈ ��û�Ͽ� �����
*/
void AskEmployInfoUI::ask() {
	vector<string>detailList;
	out_fp << "3.2 ä�� ���� ��ȸ" << endl;
	detailList = askEmployInfo.showEmployInfo();
	out_fp << "> ";
	for (int i = 0; i < detailList.size(); i++) {
		out_fp << detailList[i] << "\n\n";
	}
}
 
/*
	�Լ� �̸�: SearchEmployUI::startInterface
	���: ����� Control�� �����͸� �����ϸ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void SearchEmployUI::startInterface() {
	out_fp << "4.1. ä�� ���� �˻�" << "\n";
	search();
}

/*
	�Լ� �̸�: SearchEmployUI::search
	���: ä�� ���� �˻��� �����ϰ� ä�� ������ ����(companyName, businessName, work, employCount, deadline)�� �����
*/
void SearchEmployUI::search() {
	string companyName;
	string employInfoDetails;
	in_fp >> companyName;
	employInfoDetails = searchEmploy->doSearch(companyName);
	out_fp << "> " << employInfoDetails << "\n\n";
}

/*
	�Լ� �̸�: ApplyEmployUI::startInterface
	���: ����� Control�� �����͸� �����ϸ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void ApplyEmployUI::startInterface() {
	out_fp << "4.2. ä�� ����" << "\n";
	apply();
}

/*
	�Լ� �̸�: ApplyEmployUI::apply
	���: ä�� ������ �����ϰ� ä�� ������ ����(companyName, businessName, work)�� �����
*/
void ApplyEmployUI::apply() {
	int businessNumber;
	string applyInfoDetails;
	in_fp >> businessNumber;
	applyInfoDetails = applyEmploy->doApply(businessNumber);
	out_fp << "> " << applyInfoDetails << "\n\n";
}

/*
	�Լ� �̸� : ShowApplyInfoUI::clickApplyInfo
	��� : ȸ���̸�, ����ڹ�ȣ, ����, �ο� ��, ��û�������� ���� ���� ���� string�� �����
*/
void ShowApplyInfoUI::clickApplyInfo()
{
	out_fp << "4.3. ���� ���� ��ȸ" << endl;

	control = new ShowApplyInfo();
	string result = control->viewApplyInfo();

	out_fp << "> " << result << "\n";
};


/*
	�Լ� �̸� : ShowApplyStatsUI::startInterface
	��� : ����� Control�� �����͸� �����ϰ�, ����ڿ��� ��ȣ�ۿ��� ������
*/
void ShowApplyStatsUI::startInterface(ShowApplyStats* showApplyStats) {
	this->showApplyStats = showApplyStats;
	out_fp << "5.1. ���� ���� ���\n";
	printApplyStats();
}

/*
	�Լ� �̸� : ShowApplyStatsUI::printApplyStats
	��� : ������ ���� ��踦 �����
*/
void ShowApplyStatsUI::printApplyStats() {
	string result = showApplyStats->showApplyStats();
	out_fp << "> " << result << "\n";
}

/*
	�Լ� �̸� : CancelApplyInfoUI::selectCancelApply
	��� : ����� ���� ����(ȸ���̸�, ����ڹ�ȣ, ����)�� ���� string�� �����
*/
void CancelApplyInfoUI::selectCancelApply()
{
	string companyName, work;
	int businessNumber;

	in_fp >> businessNumber;
	out_fp << "4.4. ���� ���" << endl;

	control = new CancelApplyInfo();
	string result = control->cancelApply(businessNumber);

	out_fp << "> " << result << "\n\n";
};

