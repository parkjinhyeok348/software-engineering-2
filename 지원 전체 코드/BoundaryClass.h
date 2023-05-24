#include <vector>
#include <iostream>
#include "ControlClass.h"

using namespace std;

class ShowApplyInfoUI {
  private:
    ShowApplyInfo *control;

  public:
    void clickApplyInfo(FILE *out_fp);
};

class PrintApplyNumUI {
  private:
    PrintApplyNum *control;
  public:
    void clickApplyNum(FILE*out_fp);
};

class CancelApplyInfoUI {
  private:
    CancelApplyInfo *control;
  public:
    void selectCancelApply(FILE*in_fp, FILE*out_fp, int businessNumber);
};