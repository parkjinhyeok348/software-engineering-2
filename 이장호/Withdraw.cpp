#include "Withdraw.h"

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
