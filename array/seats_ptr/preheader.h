//헤더파일 선언
#include <stdio.h>
#include <string.h> //문자열 처리 함수가 정의된 헤더파일 선언

//기호상수 정의
#define ROW 10
#define COLUMN 10
#define PEOPLE 100

//typedef 선언
//windows에서 메모리는 4byte단위로 관리
typedef struct
{
	int num; //회원번호(구조체 배열의 인덱스)멤버
	int seat_row; //좌석의 행 멤버
	int seat_column; //좌석의 열 멤버
	int age; //나이 멤버
	char name[10]; //고객이름 멤버
	char handnum[15]; //휴대폰번호 멤버
} CUSINFO; //고객 구조체를 typedef로 선언

//전역변수 선언
CUSINFO cusarr[PEOPLE]; //전역변수로 구조체배열 설정(인덱스가 회원번호)
static int cus_num = 0; //회원번호를 정적전역변수로 설정(회원번호는 차례대로 할당)

/* 
   좌석을 전역변수로 사용하면 인자로 배열을 전달할 필요는 없음
   void bookSeats(int answer);

   이 프로그램의 방식은 배열과 포인터를 이용함
*/

//함수원형 선언
//print.c
int printMenus(void); //메뉴를 출력하는 함수의 원형
void printSeats(int arr[][COLUMN]); //좌석의 현재상태를 출력하는 함수의 원형
int findMenuCusto(void); //고객을 찾을 때 메뉴를 출력하는 함수의 정의
//reservation.c
int bookSeats(int arr[][COLUMN]); //좌석을 예약하는 함수의 원형
int cancleSeats(int arr[][COLUMN]); //좌석을 취소하는 함수의 원형
int changeSeats(int arr[][COLUMN]); //예약을 수정하는 함수의 정의
//check.c
int freqSeats(int arr[][COLUMN]); //좌석의 수를 세는 함수의 원형
int checkInput(int row, int column); //사용자가 입력한 값을 검사하는 함수의 원형
//find.c
int find_customer_main(void); //고객을 찾는 함수의 원형
int find_customer_num(void); //고객번호를 찾는 함수의 원형
int find_customer_name(void); //고객이름을 찾는 함수의 원형
int find_customer_hand(void); //고객 핸드폰번호를 찾는 함수의 원형