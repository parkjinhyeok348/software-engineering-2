#include "stdcol.h"
#include "employInfo.h"

EmployInfo::EmployInfo() {//������

}

EmployInfo::~EmployInfo() {//�Ҹ���

}

EmployInfo::EmployInfo(string work, int employCount,string deadLine) {//������ 2
    this->work = work;
    this->employCount = employCount;
    this->deadline = deadLine;
}

//ä�� ������ ����, ������, ��û �������� string���� ��ȯ��
string EmployInfo::getEmployInfoDetails() {
    string count = to_string(employCount);
    string details = work + " " + count + " " + deadline;
    return details;
}

// ä�� ���� ������
EmployInfo EmployInfo::getEmployInfo() {
    return *this;
}