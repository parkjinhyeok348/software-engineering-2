#include <vector>
#include "EntityClass.h"

// vector<ApplyInfo> ApplyInfo::getApplyInfo() const{
//   vector<ApplyInfo> appliedInfo;
//   // 테스트

//     ApplyInfo info1;
//     info1.setCompanyName("Company 1");
//     info1.setBusinessNumber(12345);
//     info1.setWork("Work 1");
//     info1.setEmployCount(10);
//     info1.setDeadLine("2023-06-01");

//     ApplyInfo info2;
//     info2.setCompanyName("Company 2");
//     info2.setBusinessNumber(67890);
//     info2.setWork("Work 2");
//     info2.setEmployCount(5);
//     info2.setDeadLine("2023-06-15");

//     ApplyInfo info3;
//     info3.setCompanyName("Company 3");
//     info3.setBusinessNumber(13579);
//     info3.setWork("Work 2");
//     info3.setEmployCount(5);
//     info3.setDeadLine("2023-06-15");

//     ApplyInfo info4;
//     info4.setCompanyName("Company 4");
//     info4.setBusinessNumber(67890);
//     info4.setWork("Work 3");
//     info4.setEmployCount(5);
//     info4.setDeadLine("2023-06-15");

//     // 정보를 벡터에 추가
//     appliedInfo.push_back(info1);
//     appliedInfo.push_back(info2);
//     appliedInfo.push_back(info3);
//     appliedInfo.push_back(info4);

  
//   return appliedInfo;
// }

ApplyInfo::ApplyInfo() {

}

void ApplyInfo::setCompanyName(const string& name) {
    companyName = name;
}

string ApplyInfo::getCompanyName() const {
    return companyName;
}

void ApplyInfo::setBusinessNumber(int number) {
    businessNumber = number;
}

int ApplyInfo::getBusinessNumber() const {
    return businessNumber;
}

void ApplyInfo::setWork(const string& job) {
    work = job;
}

string ApplyInfo::getWork() const {
    return work;
}

void ApplyInfo::setEmployCount(int count) {
    employCount = count;
}

int ApplyInfo::getEmployCount() const {
    return employCount;
}

void ApplyInfo::setDeadLine(const string& deadline) {
    deadLine = deadline;
}

string ApplyInfo::getDeadLine() const {
    return deadLine;
}


vector<ApplyInfo*> ApplyInfoCollection::getApplyList() 
{
    return applyInfos;
}

ApplyInfoCollection GeneralMember::getOwnedApplyInfoCollection()
{
  return ownedApplyInfoCollection;
}

