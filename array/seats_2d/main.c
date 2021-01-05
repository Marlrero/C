#include <stdio.h>
#include "proheader.h"

int main(void)
{
	int menu; //메뉴를 저장할 변수
	int seats[ROW][COLUMN] = {0}; //현재 좌석 상태는 0
	
	while (1) //무한루프
	{	
		menu = printMenus(); //메뉴 출력

		if (menu == 1) //예약하기
		{
			printSeats(seats);
			if (bookSeats(seats)) //함수가 잘못 실행되면
				continue; //다시 루프 시작
		}
		else if (menu == 2) //취소하기
		{
			printSeats(seats);
			if (cancleSeats(seats)) //함수가 잘못 실행되면
				continue; //다시 루프 시작
		}
		else if (menu == 3) //변경하기
		{
			printSeats(seats);
			if (changeSeats(seats)) //함수가 잘못 실행되면
				continue; //다시 루프 시작
		}
		else if (menu == 4) //좌석 보기
		{
			printSeats(seats);
			continue; //다시 루프 시작
		}
		else if (menu == 5) //종료하기
		{
			printf("프로그램이 종료됩니다!\n");
			return 0; //프로그램 종료
		}
		else //잘못 메뉴를 입력한 경우
		{
			printf("메뉴 선택을 다시하세요!\n");
			continue; //다시 물어봄
		}
	}

	return 0;
}