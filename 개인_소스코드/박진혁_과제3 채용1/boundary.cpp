#include "stdcol.h"
#include "boundary.h"
#include "control.h"

#define OUTPUT_FILE_NAME "output.txt"

//Ŭ���� ����
AskEmployInfo askEmployInfo;

AskEmployInfoUI::AskEmployInfoUI() {}//������

AskEmployInfoUI::~AskEmployInfoUI() {}//�Ҹ���
ofstream out_fp(OUTPUT_FILE_NAME);


//control Ŭ������ ȸ��ȸ���� ����� ä�� ���� ����Ʈ ��û�Ͽ� �����
void AskEmployInfoUI::ask() {
    vector<string>detailList;
    out_fp << "3.2 ä�� ���� ��ȸ" << endl;
    detailList = askEmployInfo.showEmployInfo();
    for (int i = 0; i < detailList.size(); i++) {
        out_fp << detailList[i] << endl;
    }
}


//Ŭ���� ����
RegisterEmployInfo registerEmployInfo;


RegisterEmployInfoUI::RegisterEmployInfoUI() {//������

}
RegisterEmployInfoUI::~RegisterEmployInfoUI() {//�Ҹ���

}

//����,������,��û ������ �Է� ����
void RegisterEmployInfoUI::inputEmployInfo(string work, int employCount, string deadline) {
    createNewEmployInfo(work, employCount, deadline);
}

//control Ŭ������ ����,������, ��û �������� ���� �� output.txt �� �����
void RegisterEmployInfoUI::createNewEmployInfo(string work, int employCount, string deadline) {
    registerEmployInfo.registerEmpolyInfo(work, employCount, deadline);
    out_fp << "3.1 ä�� ���� ���" << endl;
    out_fp << ">" << work << " " << employCount << " " << deadline << endl;
}