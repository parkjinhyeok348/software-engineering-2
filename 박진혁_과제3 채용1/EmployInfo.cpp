#include "stdcol.h"
#include "employInfo.h"

EmployInfo::EmployInfo() {//생성자

}

EmployInfo::~EmployInfo() {//소멸자

}

EmployInfo::EmployInfo(string work, int employCount,string deadLine) {//생성자 2
    this->work = work;
    this->employCount = employCount;
    this->deadline = deadLine;
}

//채용 정보의 업무, 지원수, 신청 마감일을 string으로 반환함
string EmployInfo::getEmployInfoDetails() {
    string count = to_string(employCount);
    string details = work + " " + count + " " + deadline;
    return details;
}

// 채용 정보 가져옴
EmployInfo EmployInfo::getEmployInfo() {
    return *this;
}