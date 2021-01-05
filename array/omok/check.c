#include <stdio.h>
#include "pre.h"

int check_win(BOARD arr, char str) //승패 검사 함수 정의
{
	int row, column; //행, 열 변수 선언
	int count = 0; //카운트 변수 선언

	//가로검사
	for (row = 0; row < ROW; row++) //행증가
	{
		count = 0;
		for (column = 0; column < COLUMN; column++) //열증가
		{
			if (arr[row][column] == str) //원소의 값에 str이 있으면
				count++; //카운트 하나 증가
		}
		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}

	//세로검사
	for (column = 0; column < COLUMN; column++) //열증가
	{
		count = 0;
		for (row = 0; row < ROW; row++) //행증가
		{
			if (arr[row][column] == str) //원소의 값에 str이 있으면
				count++; //카운트 하나 증가
		}

		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}
	//대각선검사1 (↘)
	count = 0;
	for (row = 0, column = 0; row < ROW && column < COLUMN; row++, column++) //행과 열을 같이 증가
	{
		if (arr[row][column] == str) //원소의 값에 str이 있으면
			count++; //카운트 하나 증가

		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}
	//대각선검사2 (↙)
	count = 0;
	for (row = 0, column = COLUMN-1; row < ROW && column >= 0; row++, column--) //행증가, 열감소
	{
		if (arr[row][column] == str) //원소의 값에 str이 있으면
			count++; //카운트 하나 증가

		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}
	//아직 결과가 나오지 않으면
	return 0;
}

/* 만약에 5x5에서 3목을 한다면 어떤 조건을 추가해야 할까? */