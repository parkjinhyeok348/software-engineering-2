#include "stdcol.h"
#include"employInfo.h"

//ä�� ���� ����Ʈ  entity Ŭ����
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