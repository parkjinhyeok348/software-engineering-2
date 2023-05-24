#include "stdcol.h"
#include "RegisterEmployInfoUI.h"
#include "RegisterEmployInfo.h"
#include "EmployInfo.h"

#define OUTPUT_FILE_NAME "output.txt"

//클래스 선언
RegisterEmployInfo registerEmployInfo;
ofstream out_fp(OUTPUT_FILE_NAME);


RegisterEmployInfoUI::RegisterEmployInfoUI( ) {//생성자

}
RegisterEmployInfoUI::~RegisterEmployInfoUI() {//소멸자

}

void RegisterEmployInfoUI::startInterface() {
    
}
//업무,지원수,신청 마감일 입력 받음
void RegisterEmployInfoUI::inputEmployInfo(string work, int employCount, string deadline) {
    createNewEmployInfo(work,employCount,deadline);
}

//control 클래스에 업무,지원수, 신청 마감일을 전달 후 output.txt 에 출력함
void RegisterEmployInfoUI::createNewEmployInfo(string work, int employCount, string deadline) {
    registerEmployInfo.registerEmpolyInfo(work, employCount, deadline);
    out_fp<<"3.1 채용 정보 등록"<<endl;
    out_fp << ">" << work << " " << employCount << " " << deadline << endl;
}