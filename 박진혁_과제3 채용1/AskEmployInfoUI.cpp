#include "stdcol.h"
#include "AskEmployInfoUI.h"
#include "AskEmployInfo.h"

#define OUTPUT_FILE_NAME "output.txt"

//Ŭ���� ����
AskEmployInfo askEmployInfo;

AskEmployInfoUI::AskEmployInfoUI(){}//������

AskEmployInfoUI::~AskEmployInfoUI(){}//�Ҹ���
ofstream out_fp(OUTPUT_FILE_NAME);


//control Ŭ������ ȸ��ȸ���� ����� ä�� ���� ����Ʈ ��û�Ͽ� �����
void AskEmployInfoUI::ask() {
    vector<string>detailList;
    out_fp << "3.2 ä�� ���� ��ȸ" << endl;
    detailList= askEmployInfo.showEmployInfo();
    for (int i = 0; i < detailList.size(); i++) {
        out_fp << detailList[i] << endl;
    }
}