#include"stdcol.h"
#include "AskEmployInfo.h"
#include "EmployInfo.h"

AskEmployInfo::AskEmployInfo(){} //생성자
AskEmployInfo::~AskEmployInfo(){}//소멸자

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