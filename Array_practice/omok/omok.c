/* 이 프로그램은 10*10 보드판 오목 게임 */
#include <stdio.h>
#include <stdlib.h>
#include "pre.h"

int main(void)
{
	char arr[ROW][COLUMN]; //보드를 char형 배열로 선언

	init_board(arr); //초기화 함수를 호출

	while (1) //무한루프
	{
		disp_board(arr); //보드를 출력하는 함수를 호출
		if (get_player_move(0, arr, 'X')) //유저가 선택하는 함수를 호출하여 1을 반환하면
			break; //무한루프를 멈춘다.
		if (check_win(arr, 'X')) //승패 검사 함수를 호출하여 1을 반환하면
		{
			printf("사용자X가 이겼습니다! \n");
			break; //무한루프를 멈춘다.
		}

		disp_board(arr); //보드를 출력하는 함수를 재호출
		if (get_player_move(1, arr, 'O')) //유저가 선택하는 함수를 호출하여 1을 반환하면
			break; //무한루프를 멈춘다.
		if (check_win(arr, 'O')) //승패 검사 함수를 호출하여 1을 반환하면
		{
			printf("사용자O가 이겼습니다! \n");
			break; //무한루프를 멈춘다.
		}
	}

	disp_board(arr); //결과 호출
	return 0;
}