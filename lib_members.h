#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 10

typedef struct lib_member
{
	char name[20];
	char birthyear[20];
	char phone[20];
	char city[20];
	char number[20];
	int bookBorrow;
	int bookReturn;
} T_record;


int m_is_available();       // 현재 추가할 수 있는 데이터 공간이 있는가?
int m_first_available();    // 추가할 수 있는 가장 빠른 포인터 배열의 인덱스 찾기
int m_count();              // 현재 저장된 회원 레코드의 갯수 가져오기
void m_create(char* n, char* ph, char* b, char* c);   // 회원정보로 신규 회원 레코드 추가
void number_create(T_record * p);
T_record* m_search_by_name(char* n);                // 이름이 일치하는 회원 레코드 포인터 찾기
//void m_update(T_record* p, char* ph, char* b, char* c);  // 특정 회원 레코드의 정보 업데이트
//void m_delete(T_record* p);     // 특정 회원 레코드의 회원정보 제거
void m_get_all(T_record* a[]);  // 회원정보가 들어있는 모든 레코드 포인터의 배열을 만들기
void m_get_all2(T_record* a[]);  // 모든 레코드 포인터의 배열을 만들기 (for debug)
char* m_to_string(T_record* p); // 특정 회원 레코드의 내용을 문자열로 가져오기
char* m_getname(T_record* p);   // 특정 회원 레코드의 회원이름 가져오기
char* m_getphone(T_record* p);  // 특정 회원 레코드의 회원전화번호 가져오기
char* m_getbirthyear(T_record* p);// 특정 회원 레코드의 회원생년 가져오기
char* m_getcity(T_record* p);// 특정 회원 레코드의 회원거주도시 가져오기
char* m_getnumber(T_record* p);
//int m_get_all_by_name(T_record* a[], char* n);  // 회원이름에 문자열이 포함된 모든 레코드 포인터의 배열 만들기 
//int m_get_all_by_city(T_record* a[], char* n);  // 회원거주도시가 문자열과 일치하는 모든 레코드 포인터의 배열 만들기 
void m_init(); // 모든 레코드 제거
char* m_to_string_save(T_record* p); // 특정 회원 레코드의 내용을 파일저장용 문자열로 가져오기
