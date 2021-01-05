#ifndef __DATA_H__
#define __DATA_H__

//#define DEBUG

#define ROW 10
#define COLUMN 10

#define ID_LENGTH 15
#define PWD_LENGTH 20
#define NAME_LENGTH 10
#define SEAT_LIMIT 2

typedef struct
{
	int year; //연도를 저장(4자리)
	int month; //달을 저장(1자리)
	int date; //일을 저장(1자리)
} BIRTH; //생년월일을 저장할 구조체를 typedef로 선언

typedef struct RESER_SEAT
{
	int row; //좌석 행을 저장
	int column; //좌석 열을 저장
} RESER_SEAT; //좌석 정보를 저장할 구조체를 typedef로 선언

typedef struct CUSINFO
{
	struct CUSINFO *pre; //이전노드
	char id[ID_LENGTH]; //아이디를 저장
	char password[PWD_LENGTH]; //패스워드를 저장
	char name[NAME_LENGTH]; //이름을 저장
	BIRTH birth; //생년월일을 저장
	int seat_count; //고객이 예약한 좌석의 수
	RESER_SEAT infor_check[SEAT_LIMIT]; //예약 정보를 저장
	struct CUSINFO *next; //다음노드
} CUSINFO; //고객 구조체를 typedef로 선언 ->85 -> 4byte 블록 * 22 = 88byte(3byte)

#endif