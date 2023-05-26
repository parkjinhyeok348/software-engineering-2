#include"stdcol.h"
#include "control.h"
#include "EmployInfo.h"
#include "EmployInfoCollection.h"

//채용 정보 리스트 클래스 선언
EmployInfoCollection employInfoCollection;

RegisterEmployInfo::RegisterEmployInfo() {//생성자

}
RegisterEmployInfo::~RegisterEmployInfo() { //소멸자

}
// 채용 정보 리스트에 새로운 채용 정보 추가함
void RegisterEmployInfo::registerEmpolyInfo(string work, int employCount, string deadLIne) {
    EmployInfo* newEmployInfo;
    string companyNumber = ;
    string businessNumber;
    newEmployInfo = new EmployInfo(companyNumber, businessNumber, work, employCount, deadLIne);
    employInfoCollection.AddEmployInfo(*newEmployInfo);
}


AskEmployInfo::AskEmployInfo() {} //생성자
AskEmployInfo::~AskEmployInfo() {}//소멸자

//채용 정보 리스트에서 상세정보를 받아 반환함
vector<string> AskEmployInfo::showEmployInfo() {
    vector<EmployInfo> employInfos;
    vector<string> detailList;
    //employInfos= companyMember->employInfoCollection.getEmployInfos();
    for (int i = 0; i < employInfos.size(); i++) {
        detailList.push_back(employInfos[i].getEmployInfoDetails());
    }
    return detailList;
}

