#include "stdcol.h"
#include "RegisterEmployInfoUI.h"
#include "RegisterEmployInfo.h"
#include "EmployInfo.h"

#define OUTPUT_FILE_NAME "output.txt"

//Ŭ���� ����
RegisterEmployInfo registerEmployInfo;
ofstream out_fp(OUTPUT_FILE_NAME);


RegisterEmployInfoUI::RegisterEmployInfoUI( ) {//������

}
RegisterEmployInfoUI::~RegisterEmployInfoUI() {//�Ҹ���

}

void RegisterEmployInfoUI::startInterface() {
    
}
//����,������,��û ������ �Է� ����
void RegisterEmployInfoUI::inputEmployInfo(string work, int employCount, string deadline) {
    createNewEmployInfo(work,employCount,deadline);
}

//control Ŭ������ ����,������, ��û �������� ���� �� output.txt �� �����
void RegisterEmployInfoUI::createNewEmployInfo(string work, int employCount, string deadline) {
    registerEmployInfo.registerEmpolyInfo(work, employCount, deadline);
    out_fp<<"3.1 ä�� ���� ���"<<endl;
    out_fp << ">" << work << " " << employCount << " " << deadline << endl;
}