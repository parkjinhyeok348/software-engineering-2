#include "stdcol.h"
#include"employInfo.h"

//채용 정보 리스트  entity 클래스
class EmployInfoCollection {
private:
    vector<EmployInfo> employInfos;
    EmployInfo* employInfo;
    
public:
    EmployInfoCollection();
     ~EmployInfoCollection();
    
    EmployInfo* findFirst();
    
    EmployInfo* getNext();
    
    void AddEmployInfo(EmployInfo newEmployInfo);

    vector<EmployInfo> getEmployInfos();
};