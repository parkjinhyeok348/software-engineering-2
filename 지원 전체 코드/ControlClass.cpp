#include <stdio.h>
#include <vector>
#include "ControlClass.h"
#include "EntityClass.h"

ShowApplyInfo::ShowApplyInfo() {
  pGeneralMember = nullptr;
}

ShowApplyInfo::ShowApplyInfo(GeneralMember *refGeneralMember)
{
  pGeneralMember = refGeneralMember;
}


/*
    함수 이름 : ShowApplyInfo::viewApplyInfo
    기능 : 지원 조회 리스트 string으로 변환
*/
string ShowApplyInfo::viewApplyInfo(){

  ApplyInfoCollection applyInfoCollection = pGeneralMember->getOwnedApplyInfoCollection();

  const vector<ApplyInfo *> applyInfos = applyInfoCollection.getApplyList();

  int listSize = applyInfos.size();

  string returnValue = "";

  for (int i = 0; i < listSize; i++)
  {
    returnValue.append(applyInfos[i]->getCompanyName());
    returnValue.append(" ");
    returnValue.append(to_string(applyInfos[i]->getBusinessNumber()));
    returnValue.append(" ");
    returnValue.append(applyInfos[i]->getWork());
    returnValue.append(" ");
    returnValue.append(to_string(applyInfos[i]->getEmployCount()));
    returnValue.append(" ");
    returnValue.append(applyInfos[i]->getDeadLine());
    returnValue.append("\n");
  }

  return returnValue;
}

PrintApplyNum::PrintApplyNum() {
  pGeneralMember = nullptr;
}

PrintApplyNum::PrintApplyNum(GeneralMember *refGeneralMember)
{
  pGeneralMember = refGeneralMember;
}

/*
    함수 이름 : PrintApplyNum::printApplyNum
    기능 : 지원 횟수 리스트 string으로 변환
*/
string PrintApplyNum::printApplyNum(){

  ApplyInfoCollection applyInfoCollection = pGeneralMember->getOwnedApplyInfoCollection();

  const vector<ApplyInfo *> applyInfos = applyInfoCollection.getApplyList();

  int listSize = applyInfos.size();

  string returnValue = "";
  vector<pair<string, int>> workNumList;

  for (int i = 0; i < listSize; i++)
  {
    string work = applyInfos[i]->getWork();
    if (i == 0) 
      workNumList.push_back(make_pair(work, 1));

		for (int j = 1; j < workNumList.size(); j++)
		{
			if (workNumList[j].first == work)
			{
				workNumList[j].second++;
				break;
			}
			if (j == workNumList.size() - 1)
			{
				workNumList.push_back(make_pair(work, 1));
			}
		}
  }
  for (int i = 0; i < workNumList.size(); i++) {
    returnValue.append(workNumList[i].first);
    returnValue.append(" ");
    returnValue.append(to_string(workNumList[i].second));
    returnValue.append("\n");
  }
  return returnValue;
}

CancelApplyInfo::CancelApplyInfo() {
  pGeneralMember = nullptr;
}


CancelApplyInfo::CancelApplyInfo(GeneralMember* refGeneralMember){
  pGeneralMember = refGeneralMember;
}

/*
    함수 이름 : CancelApplyInfo::cancelApply
    기능 : 지원 취소 결과 string으로 변환
*/
string CancelApplyInfo::cancelApply(int businessNumber){

  ApplyInfoCollection applyInfoCollection = pGeneralMember->getOwnedApplyInfoCollection();

  const vector<ApplyInfo *> cancelInfoList = applyInfoCollection.getApplyList();

  string returnValue = "";

  for(auto cancelInfo : cancelInfoList)
    if(cancelInfo->getBusinessNumber() == businessNumber) {
      returnValue.append(cancelInfo->getCompanyName());
      returnValue.append(" ");
      returnValue.append(to_string(cancelInfo->getBusinessNumber()));
      returnValue.append(" ");
      returnValue.append(cancelInfo->getWork());
      returnValue.append("\n");

      // delete cancelInfo;

      return returnValue;
    }

  //delete
}
