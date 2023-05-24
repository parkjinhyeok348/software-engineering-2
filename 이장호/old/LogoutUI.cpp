#define _CRT_SECURE_NO_WARNINGS
#include "Logout.h"


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