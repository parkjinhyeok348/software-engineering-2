class Member {
public: 
    
bool isPasswordCorrect(string password);
        
void setLoginStatus(bool loginStatus);

static Member** getCurrentMember();
static void setCurrentMember(Member** newCurrentMember);
string getID();
string getPassword();
virtual string getMemberInfo();
void setId(string id);
void setPassword(string password);

private: 
    static Member** currentMember;
    string id;
    string password;
    bool loginStatus;
};

class GeneralMember: public Member {
public:
    // 기본 생성자 (아래의 생성자 선언을 위해 만듦)
    GeneralMember();
    // 생성과 동시에 정보를 주입하는 생성자.
    GeneralMember(string id, string password, string name, int ssn);
    // 회원 정보 문자열을 반환하는 함수
    virtual string getMemberInfo();
private: 
    // 이름
    string name;
    // 주민등록번호
    int ssn;
};

class CompanyMember: public Member {
public:
    // 기본 생성자 (아래의 생성자 선언을 위해 만듦)
    CompanyMember();
    // 생성과 동시에 정보를 주입하는 생성자.
    CompanyMember(string id, string password, string companyName, int businessNum);
    // 회원 정보 문자열을 반환하는 함수
    virtual string getMemberInfo();
private: 
    // 회사 이름
    string companyName;
    // 사업자 등록 번호
    int businessNum;
};

class MemberList {
public: 
// Singleton design
static MemberList* getMemberList();
// ID를 통해 해당하는 Member의 포인터를 저장한 배열의 위치를 반환하는 함수
Member** findByID(string id);
    
// 목록에서 해당 회원을 지우는 함수
void deleteMember(Member** deletedMember);
    
// 일반 회원을 등록하는 함수. 추가된 회원의 index를 반환한다.
GeneralMember * addGeneralMember(string id, string password, string name, int ssn);

// 회사 회원을 등록하는 함수. 추가된 회원의 index를 반환한다.
CompanyMember * addCompanyMember(string id, string password, string companyName, int businessNum);

    
private: 
    // Singleton Design
    MemberList();
    static MemberList * memberList;
    // 회원 목록
    Member * members[MAX_MEMBER];
    // 배열 크기(현재 회원 수)
    int size = 0;
};

class Join {
public: 
// 새로운 회원을 MemberList에 등록하는 함수.
string addMember(string memberInfo);
    
// memberType을 설정하는 함수
void setMemberType(int memberType);

// Control 생성 후 실행되는 코드
void run(FILE * in_fp, FILE * out_fp);

private: 
    // 가입 과정에서 선택된 회원 종류에 대해 알려주는 값
    int memberType = 0; // 0 : 지정되지 않음, 1 : 회사 회원, 2 : 일반 회원.
};

class Login {
public:
    // Control 생성 후 실행되는 함수
    void run(FILE* in_fp, FILE* out_fp);
    // ID와 Password를 통해 회원이 본인인지 인증하고 로그인시키는 함수,
    // 로그인이 완료되면 로그인된 아이디와 비밀번호를 반환한다.
    string authenticateMember(string id, string password);
};

class Logout {
public: 
    void run(FILE* in_fp, FILE* out_fp);
    string processLogout();
};

class Withdraw {
public: 
// 회원 리스트에서 현재 로그인 중인 회원을 탈퇴시키는 함수. 탈퇴된 회원의 ID를 반환한다.
string deleteMember();

// Control 생성 후 실행되는 함수
void run(FILE* in_fp, FILE* out_fp);
};
