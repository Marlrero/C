#ifndef __RESERV_H__
#define __RESERV_H__

#define MEMBER_LIMIT 10
 int bookSeats(int(*arr)[COLUMN], CUSINFO *member); //좌석을 예약하는 함수
 int cancleSeats(int(*arr)[COLUMN], CUSINFO *member); //좌석을 취소하는 함수
 int changeSeats(int(*arr)[COLUMN], CUSINFO *member); //예약을 변경하는 함수의 정의
CUSINFO *getLastNode(CUSINFO *linked);
void removeNode(CUSINFO *member, CUSINFO **linked);

#endif