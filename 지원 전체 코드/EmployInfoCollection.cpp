#include "stdcol.h"
#include "EmployInfoCollection.h"

EmployInfoCollection::EmployInfoCollection() {// ������

}
EmployInfoCollection::~EmployInfoCollection() { //�Ҹ���

}

EmployInfo* EmployInfoCollection::findFirst() {
    
    return this->employInfo;
}


EmployInfo* EmployInfoCollection::getNext() {
    return this->employInfo;
}

//���ο� ä�������� ä�� ���� ����Ʈ�� �߰���.
void EmployInfoCollection::AddEmployInfo(EmployInfo newEmployInfo) {
    employInfos.push_back(newEmployInfo);
}

//ä�� ���� ����Ʈ�� ������
vector<EmployInfo> EmployInfoCollection::getEmployInfos() {
    return employInfos;
}