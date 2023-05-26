#pragma once
#include "stdcol.h"

// ȸ�� ���� Entity Class
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

// ���� ���� Entity class
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

// ���� ���� ����Ʈ Entity class
class ApplyInfoCollection {
private:
    vector <ApplyInfo> applyInfoList;

public:
    void addApplyInfo(ApplyInfo newApplyInfo);
    vector<ApplyInfo>& getApplyList();
};


// �Ϲ� ȸ�� Entity Class. Member�� �����
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


// ȸ�� ȸ�� Entity Class. Member�� �����
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


// Member�� Collection Entity Class
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


//ä�� ����  entity Ŭ����
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


//ä�� ���� ����Ʈ  entity Ŭ����
class EmployInfoCollection {
private:
    vector<EmployInfo> employInfos;
    EmployInfo* employInfo;

public:
    EmployInfoCollection();

    void addEmployInfo(EmployInfo newEmployInfo);

    vector<EmployInfo> getEmployInfos();


};

