#include "stdcol.h"

//ä�� ���� ��� boundary class
class RegisterEmployInfoUI {
    
public: 
    RegisterEmployInfoUI();

    ~RegisterEmployInfoUI();

    void startInterface();
    
    void inputEmployInfo(string work, int employCount, string deadLIne);
    
    void createNewEmployInfo(string work, int employCount, string deadLIne);
};
