#include "stdcol.h"
#include "EmployInfo.h"

//채용 정보 등록 control 클래스
class RegisterEmployInfo {
  
public: 
    RegisterEmployInfo();

    ~RegisterEmployInfo();
    
    void registerEmpolyInfo(string work, int employCount, string deadLIne);
};
