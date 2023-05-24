#include <stdio.h>
#include <vector>
#include "BoundaryClass.h"
#include "EntityClass.h"


/*
    함수 이름 : ShowApplyInfoUI::clickApplyInfo
    기능 : 지원 정보 출력
*/
void ShowApplyInfoUI::clickApplyInfo(FILE *out_fp)
{
  fprintf(out_fp, "4.3. 지원 정보 조회\n");

  control = new ShowApplyInfo();
  string result = control->viewApplyInfo();

  fprintf(out_fp, "> %s\n", result.c_str());
};


/*
    함수 이름 : PrintApplyNumUI::clickApplyNum
    기능 : 지원 횟수 출력
*/
void PrintApplyNumUI::clickApplyNum(FILE *out_fp)
{
  fprintf(out_fp, "5.1. 지원 횟수 출력\n");

  control = new PrintApplyNum();
  string result = control->printApplyNum();

  fprintf(out_fp, "> %s\n", result.c_str());
};


/*
    함수 이름 : CancelApplyInfoUI::selectCancelApply
    기능 : 지원 취소 결과 출력
*/
void CancelApplyInfoUI::selectCancelApply(FILE *in_fp,FILE *out_fp, int businessNumber)
{
  string companyName, work;

  fscanf(in_fp, "%d ", &businessNumber);

  fprintf(out_fp, "4.4. 지원 취소 startInterface\n");

  control = new CancelApplyInfo();
  string result = control-> cancelApply(businessNumber);

  fprintf(out_fp, "> %s\n", result.c_str());
};