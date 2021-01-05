#include <stdio.h>
#include "pre.h"

int check_win(BOARD arr, char str) //승패 검사 함수 정의
{
	int rstart, cstart, rend, cend; //행과 열을 초기화하기 위한 변수 선언
	int row, column; //행과 열을 세기 위한 변수 선언
	int count = 0; //카운트 변수 선언

				   //가로검사
	for (row = 0; row < ROW - 1; row++) //행증가
	{
		count = 0;
		for (column = 0; column < COLUMN - 1; column++) //열증가
		{
			if (arr[row][column] == str && arr[row][column + 1] == str) //원소의 값에 str이 있으면
				count++; //카운트 하나 증가
		}
		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}

	//세로검사
	for (column = 0; column < COLUMN - 1; column++) //열증가
	{
		count = 0;
		for (row = 0; row < ROW - 1; row++) //행증가
		{
			if (arr[row][column] == str && arr[row + 1][column] == str) //원소의 값에 str이 있으면
				count++; //카운트 하나 증가
		}

		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}

	//아래에 '대각선검사 초기화'는 '대각선방향 검사 함수'의 행과 열에 시작값과 끝값을 결정합니다.
	//대각선검사 초기화 (↘)(←)
	for (rstart = 0, cend = COLUMN - 1; rstart < ROW - CHECK && cend > CHECK; rstart++, cend--)
		if (check1_diagonal(arr, str, rstart, ROW, 0, cend)) //이 함수가 반환한 값이 1이면
			return 1; //정상 종료

	//대각선검사 초기화 (↘)(→)
	for (cstart = 0, rend = ROW - 1; cstart < COLUMN - CHECK, rend > CHECK; cstart++, rend--)
		if (check1_diagonal(arr, str, 0, rend, cstart, COLUMN - 1)) //이 함수가 반환한 값이 1이면
			return 1; //정상 종료

	//대각선검사 초기화 (↙)(←)
	for (cstart = COLUMN - 1, rend = ROW - 1; cstart > CHECK, rend > CHECK; cstart--, rend--) //시작, 끝변수
		if (check2_diagonal(arr, str, 0, rend, cstart, 0)) //이 함수가 반환한 값이 1이면
			return 1; //정상 종료

	 //대각선검사 초기화 (↙)(→)
	for (rstart = 0, cend = 0; rstart < ROW - CHECK && cend < COLUMN - CHECK; rstart++, cend++)
		if (check2_diagonal(arr, str, rstart, ROW, COLUMN - 1, cend)) //이 함수가 반환한 값이 1이면
			return 1; //정상 종료

	//위에 문제점: 가운데 ↘와 ↙줄은 두번 검사하게 됨 --> 속도 감소
	//위에 문제점: 정사각형 배열에서만 성립 --> 직사각형에 경우에는 더 어려워짐...(이건 만들지 말자...)
	//위에 문제점: 논리적으로 보기가 불편하다고 생각함 --> 논리적으로 더 편한방법이 있을까??

	//아직 결과가 나오지 않으면
	return 0;
}

//아래에 함수는 ↘방향으로만 검사하는 함수, ↙방향으로만 검사하는 함수를 따로 정의함
int check1_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend) //대각선방향 검사 함수1 (↘)
{
	int row, column, count = 0;

	for (row = rstart, column = cstart; row < rend && column < cend; row++, column++) //행과 열을 같이 증가
	{
		if (row == ROW - 1 && column == COLUMN - 1) //직전까지 검사하면 아래 if문은 +1인덱스에서 범위 초과
			return 0; //비정상 종료

		if (arr[row][column] == str && arr[row + 1][column + 1] == str) //원소의 값에 str이 있으면
			count++; //카운트 하나 증가

		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}

	//아직 결과가 나오지 않으면
	return 0; //비정상 종료
}

int check2_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend) //대각선방향 검사 함수2 (↙)
{
	int row, column, count = 0;

	for (row = rstart, column = cstart; row < rend && column > cend; row++, column--) //행증가, 열감소
	{
		if (row == ROW - 1 && column == 0) //직전까지 검사하면 아래 if문은 +1과 -1인덱스에서 범위 초과
			return 0; //비정상 종료

		if (arr[row][column] == str && arr[row + 1][column - 1] == str) //원소의 값에 str이 있으면
			count++; //카운트 하나 증가

		if (count == CHECK) //오목이면
			return 1; //정상 종료
	}

	//아직 결과가 나오지 않으면
	return 0; //비정상 종료
}