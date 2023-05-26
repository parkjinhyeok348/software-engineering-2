#include <stdio.h>
#include <cstdio>
#include "EntityClass.h"

class ShowApplyInfo {
  private:
    GeneralMember *pGeneralMember;

  public:
    ShowApplyInfo();
    ShowApplyInfo(GeneralMember *refGeneralMember);
    string viewApplyInfo();
};

class PrintApplyNum {
  private:
    GeneralMember *pGeneralMember;
  public:
    PrintApplyNum();
    PrintApplyNum(GeneralMember *refGeneralMember);
    string printApplyNum();
};

class CancelApplyInfo {
  private:
    GeneralMember *pGeneralMember;
    
  public:
    CancelApplyInfo();
    CancelApplyInfo(GeneralMember *refGeneralMember);
    string cancelApply(int businessNumber);
};



