#include <stdio.h> //IO
#include "data.h"
#include "check.h"

int freqSeats(const int(*arr)[COLUMN]) //좌석의 수를 세는 함수 선언
{
	int freq = 0; //좌석의 수를 세는 변수 선언(초기화 0)
	int row, column; //행과 열을 세는 변수 선언

	for (row = 0; row < ROW; row++)
	{
		for (column = 0; column < COLUMN; column++)
		{
			if (*(*(arr + row) + column) == 0) //빈좌석이면
				freq++; //좌석의 수를 1증가
		}
	}

	return freq; //좌석의 수를 반환
}

int checkInput(const int row, const int column) //좌석 입력 검사 함수 선언
{
	if (row <= 0 || row > ROW) //행의 범위를 초과한 값을 입력하면
	{
		printf("행 오류! 1부터 %d사이의 숫자를 입력하세요! \n", ROW);
		return 1; //비정상 종료
	}
	if (column <= 0 || column > COLUMN) //열의 범위를 초과한 값을 입력하면
	{
		printf("열 오류! 1부터 %d사이의 숫자를 입력하세요! \n", COLUMN);
		return 1; //비정상 종료
	}

	return 0; //정상 종료
}