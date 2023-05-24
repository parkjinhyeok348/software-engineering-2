#include "stdcol.h"
#include "RegisterEmployInfo.h"
#include "EmployInfo.h"
#include "EmployInfoCollection.h"

EmployInfoCollection employInfoCollection;

RegisterEmployInfo::RegisterEmployInfo() {//생성자

}
RegisterEmployInfo::~RegisterEmployInfo() { //소멸자

}
// 채용 정보 리스트에 새로운 채용 정보 추가함
void RegisterEmployInfo::registerEmpolyInfo(string work, int employCount, string deadLIne) {
    EmployInfo* newEmployInfo;
    newEmployInfo = new EmployInfo(work, employCount, deadLIne);
    employInfoCollection.AddEmployInfo(*newEmployInfo);
}