#include "stdcol.h"
#include "RegisterEmployInfo.h"
#include "EmployInfo.h"
#include "EmployInfoCollection.h"

EmployInfoCollection employInfoCollection;

RegisterEmployInfo::RegisterEmployInfo() {//������

}
RegisterEmployInfo::~RegisterEmployInfo() { //�Ҹ���

}
// ä�� ���� ����Ʈ�� ���ο� ä�� ���� �߰���
void RegisterEmployInfo::registerEmpolyInfo(string work, int employCount, string deadLIne) {
    EmployInfo* newEmployInfo;
    newEmployInfo = new EmployInfo(work, employCount, deadLIne);
    employInfoCollection.AddEmployInfo(*newEmployInfo);
}