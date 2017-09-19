#include <stdio.h>
#include "pre.h"

void init_board(BOARD arr) //초기화 함수 선언
{
	int row, column; //행과 열을 세기 위한 변수 선언

	for (row = 0; row < ROW; row++) //행 반복
		for (column = 0; column < COLUMN; column++) //열 반복
			arr[row][column] = ' '; //초기화
}

int get_player_move(int player, BOARD arr, char user) //유저 선택 함수 선언
{
	POINT input; //구조체 변수 선언

	while (1) //무한루프
	{
		printf("유저 %c - (x, y)좌표를 입력(종료: -1, -1): ", user);
		scanf("%d %d", &input.x, &input.y);

		if (input.x - 1 == -1 && input.y - 1 == -1) //종료 조건이면
			return 1; //무한루프를 멈추고 비정상 종료

		if (arr[input.x - 1][input.y - 1] == ' ') //입력한 좌표가 빈곳이면
			break; //무한루프를 빠져나감
		else //입력한 좌표가 이미 입력된 곳이면
			printf("잘못된 위치입니다. 다시 입력하세요! \n"); //조건식으로 돌아감
	}
	//위 2번째 if문에서 break되면
	if (player == 0) //사용자가 0이면
		arr[input.x - 1][input.y - 1] = 'X'; //X를 채움
	else //사용자가 1이면
		arr[input.x - 1][input.y - 1] = 'O'; //O를 채움

	return 0; //위 if~else문이 실행되면 정상 종료
}

void disp_board(BOARD arr) //출력 함수 선언
{
	int row, column; //행과 열을 세기 위한 변수 선언

	printf("  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 \n");
	printf("   ---|---|---|---|---|---|---|---|---|---\n");
	for (row = 0; row < ROW; row++) //행 반복
	{
		printf("%2d|", row + 1);
		for (column = 0; column < COLUMN; column++) //열 반복
		{
			printf(" %c", arr[row][column]); //출력
			printf(" |");
		}
		printf("\n  |---|---|---|---|---|---|---|---|---|---\n");
	}
}