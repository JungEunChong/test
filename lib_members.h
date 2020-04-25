#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MEMBERS 100

typedef struct lib_member
{
	char name[20];
	char birthyear[20];
	char phone[20];
	char city[20];
	char enrollment_date[20];
	char recent_visit[20];
} T_record;


int m_is_available();       // chech if there is a space for new member
int m_first_available();    // return the first pointer which has index of an array
int m_count();              // return count
void m_create(char* n, char* ph, char* b, char* c, char* e);   // create new member
void sort(int size); //sort by name 
void r_create(char *n, char * str); //recent visit can be made 
T_record* m_search_by_name(char* n);                // 이름이 일치하는 회원 레코드 포인터 찾기
void m_update(T_record* p, char* ph, char* b, char* c);  // 특정 회원 레코드의 정보 업데이트
void m_delete(T_record* p);     // 특정 회원 레코드의 회원정보 제거
void m_get_all(T_record* a[]);  // 회원정보가 들어있는 모든 레코드 포인터의 배열을 만들기
void m_get_all2(T_record* a[]);  // 모든 레코드 포인터의 배열을 만들기 (for debug)
char* m_to_string(T_record* p); // 특정 회원 레코드의 내용을 문자열로 가져오기
char* m_getname(T_record* p);   // 특정 회원 레코드의 회원이름 가져오기
char* m_getphone(T_record* p);  // 특정 회원 레코드의 회원전화번호 가져오기
char* m_getbirthyear(T_record* p);// 특정 회원 레코드의 회원생년 가져오기
char* m_getcity(T_record* p);// 특정 회원 레코드의 회원거주도시 가져오기
char* m_getenrollment_date(T_record* p); //get enrollment date
int m_get_all_by_name(T_record* a[], char* n);  // 회원이름에 문자열이 포함된 모든 레코드 포인터의 배열 만들기
int m_get_all_by_number(T_record * a[], char * n); //find member who has a certain phone number
int m_get_all_by_city(T_record* a[], char* n);  // 회원거주도시가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
void m_init(); // 모든 레코드 제거
char* m_to_string_save(T_record* p); // 특정 회원 레코드의 내용을 파일저장용 문자열로 가져오기
