#pragma once
#include "stdcol.h"

// 회원 정보 Entity Class
class Member {
public:
    bool isPasswordCorrect(string password);
    string getID();
    string getPassword();
    virtual string getMemberInfo()=0;
    virtual string getStats()=0;
    void setId(string id);
    void setPassword(string password);

private:
    string id;
    string password;
};

// 지원 정보 Entity class
class ApplyInfo
{
private:
    string companyName;
    int businessNumber;
    string work;
    string deadLine;
    int employCount;


public:
    ApplyInfo();
    ApplyInfo(string companyName, int businessNumber, string work, int employCount, string deadLine);

    string getCompanyName();
    int getBusinessNumber();
    string getWork();
    int getEmployCount();
    string getDeadLine();
    static bool compare(ApplyInfo a, ApplyInfo b);
};

// 지원 정보 리스트 Entity class
class ApplyInfoCollection {
private:
    vector <ApplyInfo> applyInfoList;

public:
    void addApplyInfo(ApplyInfo newApplyInfo);
    vector<ApplyInfo>& getApplyList();
};


// 일반 회원 Entity Class. Member를 상속함
class GeneralMember : public Member {
public:
    GeneralMember();
    GeneralMember(string id, string password, string name, int ssn);
    ApplyInfoCollection* getOwnedApplyInfoCollection();
    virtual string getMemberInfo();
    virtual string getStats();
private:
    string name;
    int ssn;
    ApplyInfoCollection* ownedApplyInfoCollection;
};


// 회사 회원 Entity Class. Member를 상속함
class CompanyMember : public Member {
public:
    CompanyMember();
    CompanyMember(string id, string password, string companyName, int businessNumber);
    virtual string getMemberInfo();
    virtual string getStats();
private:
    string companyName;
    int businessNumber;
};


// Member의 Collection Entity Class
class MemberCollection {
public:
    static MemberCollection* getMemberCollection();
    static Member* getCurrentMember();
    static void setCurrentMember(string newCurrentMember);
    Member* findByID(string id);
    void deleteCurrentMember();
    Member* addGeneralMember(string id, string password, string name, int ssn);
    Member* addCompanyMember(string id, string password, string companyName, int businessNumber);

private:
    static MemberCollection* memberList;
    static string currentMemberID;
    map<string, Member*> members;
};


//채용 정보  entity 클래스
class EmployInfo {
public:
    EmployInfo();

    string getEmployInfoDetails();

    EmployInfo getEmployInfo();

    EmployInfo(string companyName, int businessNumber, string work, int employCount, string deadLine);

    string getCompanyName();
    string getDeadline();
    int getBusinessNumber();
    string getWork();
    int getEmployCount();
    int getApplyCount();
    void increaseApplyCount();
    void decreaseApplyCount();

private:
    string companyName;
    int businessNumber;
    string work;
    int employCount;
    int applyCount;
    string deadLine;
};


//채용 정보 리스트  entity 클래스
class EmployInfoCollection {
private:
    vector<EmployInfo> employInfos;
    EmployInfo* employInfo;

public:
    EmployInfoCollection();

    void addEmployInfo(EmployInfo newEmployInfo);

    vector<EmployInfo> getEmployInfos();


};

