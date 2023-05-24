#include "stdcol.h"
#include "EmployInfoCollection.h"

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