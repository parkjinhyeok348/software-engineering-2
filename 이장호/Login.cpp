#include "Login.h"



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