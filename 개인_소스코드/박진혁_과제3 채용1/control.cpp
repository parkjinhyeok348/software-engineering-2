#include"stdcol.h"
#include "control.h"
#include "EmployInfo.h"
#include "EmployInfoCollection.h"

//ä�� ���� ����Ʈ Ŭ���� ����
EmployInfoCollection employInfoCollection;

RegisterEmployInfo::RegisterEmployInfo() {//������

}
RegisterEmployInfo::~RegisterEmployInfo() { //�Ҹ���

}
// ä�� ���� ����Ʈ�� ���ο� ä�� ���� �߰���
void RegisterEmployInfo::registerEmpolyInfo(string work, int employCount, string deadLIne) {
    EmployInfo* newEmployInfo;
    string companyNumber = ;
    string businessNumber;
    newEmployInfo = new EmployInfo(companyNumber, businessNumber, work, employCount, deadLIne);
    employInfoCollection.AddEmployInfo(*newEmployInfo);
}


AskEmployInfo::AskEmployInfo() {} //������
AskEmployInfo::~AskEmployInfo() {}//�Ҹ���

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

