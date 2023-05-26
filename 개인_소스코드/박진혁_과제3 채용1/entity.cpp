#include "stdcol.h"
#include "employInfo.h"
#include "EmployInfoCollection.h"

EmployInfo::EmployInfo() {//������

}

EmployInfo::~EmployInfo() {//�Ҹ���

}

EmployInfo::EmployInfo(string companyName, int businessNumber, string work, int employCount, string deadLine) {//������ 2
    this->companyName = companyName;
    this->businessNumber = businessNumber;
    this->work = work;
    this->employCount = employCount;
    this->deadLine = deadLine;
}

//ä�� ������ ����, ������, ��û �������� string���� ��ȯ��
string EmployInfo::getEmployInfoDetails() {
    string count = to_string(employCount);
    string details = work + " " + count + " " + deadLine;
    return details;
}

// ä�� ���� ������
EmployInfo EmployInfo::getEmployInfo() {
    return *this;
}

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