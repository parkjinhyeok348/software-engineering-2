#include "Logout.h"


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
