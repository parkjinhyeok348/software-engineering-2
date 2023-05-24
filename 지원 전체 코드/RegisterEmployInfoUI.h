#include "stdcol.h"

//채용 정보 등록 boundary class
class RegisterEmployInfoUI {
    
public: 
    RegisterEmployInfoUI();

    ~RegisterEmployInfoUI();

    void startInterface();
    
    void inputEmployInfo(string work, int employCount, string deadLIne);
    
    void createNewEmployInfo(string work, int employCount, string deadLIne);
};
