#include <iostream>
#include <vector>
#pragma once

using namespace std;

class ApplyInfo
{
private:
    string companyName;
    int businessNumber;
    string work;     
    string deadLine;
    int employCount;
    int applyNum;

public:
    ApplyInfo();
    // vector<ApplyInfo> getApplyInfo() const;

    void setCompanyName(const string& name);
    string getCompanyName() const;

    void setBusinessNumber(int number);
    int getBusinessNumber() const;

    void setWork(const string& job);
    string getWork() const;

    void setEmployCount(int count);
    int getEmployCount() const;

    void setDeadLine(const string& deadline);
    string getDeadLine() const;
}; 

class ApplyInfoCollection {
  private:
    vector <ApplyInfo*> applyInfos;

  public:
    vector<ApplyInfo*> getApplyList();
};

class GeneralMember {
  private:
    ApplyInfoCollection ownedApplyInfoCollection;

  public:
    ApplyInfoCollection getOwnedApplyInfoCollection();
};