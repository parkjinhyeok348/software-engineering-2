#include"stdcol.h"
#include "AskEmployInfo.h"
#include "EmployInfo.h"

AskEmployInfo::AskEmployInfo(){} //������
AskEmployInfo::~AskEmployInfo(){}//�Ҹ���

//ä�� ���� ����Ʈ���� �������� �޾� ��ȯ��
vector<string> AskEmployInfo::showEmployInfo() {
    vector<EmployInfo> employInfos;
    vector<string> detailList;
    //employInfos= companyMember->employInfoCollection.getEmployInfos();
    for (int i = 0; i < employInfos.size(); i++) {
        detailList.push_back(employInfos[i].getEmployInfoDetails());
   }
    return detailList;
}