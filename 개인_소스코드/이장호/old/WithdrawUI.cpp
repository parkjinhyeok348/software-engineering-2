#define _CRT_SECURE_NO_WARNINGS
#include "Withdraw.h"



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