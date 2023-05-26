#define _CRT_SECURE_NO_WARNINGS
#include "Login.h"


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