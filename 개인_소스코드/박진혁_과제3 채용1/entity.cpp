#include "stdcol.h"
#include "employInfo.h"
#include "EmployInfoCollection.h"

EmployInfo::EmployInfo() {//생성자

}

EmployInfo::~EmployInfo() {//소멸자

}

EmployInfo::EmployInfo(string companyName, int businessNumber, string work, int employCount, string deadLine) {//생성자 2
    this->companyName = companyName;
    this->businessNumber = businessNumber;
    this->work = work;
    this->employCount = employCount;
    this->deadLine = deadLine;
}

//채용 정보의 업무, 지원수, 신청 마감일을 string으로 반환함
string EmployInfo::getEmployInfoDetails() {
    string count = to_string(employCount);
    string details = work + " " + count + " " + deadLine;
    return details;
}

// 채용 정보 가져옴
EmployInfo EmployInfo::getEmployInfo() {
    return *this;
}

EmployInfoCollection::EmployInfoCollection() {// 생성자

}
EmployInfoCollection::~EmployInfoCollection() { //소멸자

}

EmployInfo* EmployInfoCollection::findFirst() {

    return this->employInfo;
}


EmployInfo* EmployInfoCollection::getNext() {
    return this->employInfo;
}

//새로운 채용정보를 채용 정보 리스트에 추가함.
void EmployInfoCollection::AddEmployInfo(EmployInfo newEmployInfo) {
    employInfos.push_back(newEmployInfo);
}

//채용 정보 리스트를 가져옴
vector<EmployInfo> EmployInfoCollection::getEmployInfos() {
    return employInfos;
}