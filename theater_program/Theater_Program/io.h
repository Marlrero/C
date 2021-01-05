#ifndef __PRINT_H__
#define __PRINT_H__

#include "data.h"

#define BUFFER_SIZE 100

 int  printMenus(void); //메뉴를 출력하는 함수
void  printSeats(const int(*arr)[COLUMN]); //좌석의 현재상태를 출력하는 함수
void  printMemberList(CUSINFO *linked); //회원 명단을 출력하는 함수
void  printMemberSeatList(const CUSINFO *member); //회원의 좌석을 출력하는 함수
char* inputString(const char *mode, const unsigned int size); //문자열을 입력하는 함수
BIRTH*inputBirth(void);


#endif