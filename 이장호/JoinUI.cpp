#define _CRT_SECURE_NO_WARNINGS
#include "Join.h"


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