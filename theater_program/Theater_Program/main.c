#include <stdio.h> //IO
#include <stdlib.h> //free() system()
//#include <windows.h> //Sleep()
#include "check.h"
#include "customer.h"
#include "data.h"
#include "file.h"
#include "io.h"
#include "reservation.h"

int main(void)
{
	int menu; //메뉴를 저장할 변수
	int seats[ROW][COLUMN] = { 0 }; //현재 좌석 상태는 0
	FILE *database = NULL, *seatdata = NULL; //고객 정보를 저장할 파일, 좌석을 저장할 파일
	CUSINFO *linked = NULL; //
	CUSINFO *member = NULL; //현재 로그인한 회원의 정보를 저장하는 구조체 포인터

#ifdef DEBUG
	printf("debug >> struct sizeof -> %d \n", sizeof(CUSINFO));
#endif
	while (1) //무한루프
	{
		menu = printMenus(); //메뉴 출력
		loadCustom(&linked, &database);
		loadSeats(seats, &seatdata);

		if (menu == 1) //예약하기
		{
			if ((member = loginMembership(linked)) != NULL) //로그인이 통과되면
			{
				printSeats(seats);

				if (bookSeats(seats, member)) //함수가 잘못 실행되면
					continue; //다시 루프 시작
#ifdef DEBUG
				printf("debug >> seats %d %d %d %d %d \n", member->seat_count, member->infor_check[0].row, member->infor_check[0].column, member->infor_check[1].row, member->infor_check[1].column);
#endif
			}
			else
				printf("아이디와 비밀번호를 찾을 수 없습니다!\n");

		}
		else if (menu == 2) //취소하기
		{
			if ((member = loginMembership(linked)) != NULL) //로그인이 통과되면
			{
				printSeats(seats);

				if (cancleSeats(seats, member)) //함수가 잘못 실행되면
					continue; //다시 루프 시작
#ifdef DEBUG
				printf("debug >> seats %d %d %d %d %d \n", member->seat_count, member->infor_check[0].row, member->infor_check[0].column, member->infor_check[1].row, member->infor_check[1].column);
#endif
			}
			else
				printf("아이디와 비밀번호를 찾을 수 없습니다!\n");
		}
		else if (menu == 3) //변경하기
		{
			if ((member = loginMembership(linked)) != NULL) //로그인이 통과되면
			{
				printSeats(seats);

				if (changeSeats(seats, member)) //함수가 잘못 실행되면
					continue; //다시 루프 시작
#ifdef DEBUG
				printf("debug >> seats %d %d %d %d %d \n", member->seat_count, member->infor_check[0].row, member->infor_check[0].column, member->infor_check[1].row, member->infor_check[1].column);
#endif
			}
			else
				printf("아이디와 비밀번호를 찾을 수 없습니다!\n");
		}
		else if (menu == 4) //좌석 보기
		{
			if ((member = loginMembership(linked)) != NULL) //로그인이 통과되면
			{
				printSeats(seats);
				printMemberSeatList(member);
			}
			else
				printf("아이디와 비밀번호를 찾을 수 없습니다!\n");
		}
		else if (menu == 5) //회원가입
			createMembership(&linked);
		else if (menu == 6) //회원탈퇴
		{
			if ((member = loginMembership(linked)) != NULL) //로그인이 통과되면
			{
				deleteMembership(member, seats, &linked);
			}
			else
				printf("아이디와 비밀번호를 찾을 수 없습니다!\n");
		}
		else if (menu == 7) //회원목록
			printMemberList(linked);
		else if (menu == 8) //좌석상태
			printSeats(seats);
		else if (menu == 9) //종료하기
		{
			printf("프로그램이 종료됩니다!\n");
			break;
		}
		else //잘못 메뉴를 입력한 경우
		{
			printf("메뉴 선택을 다시하세요!\n");
			continue; //다시 물어봄
		}

		member = NULL; //logout
		_sleep(1 * 1000); //1초 딜레이
		system("cls"); //화면지우기
		saveSeats(seats, &seatdata);
		saveCustom(&linked, &database);
	}
	return 0; //프로그램 종료
}