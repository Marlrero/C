#include <stdio.h>
#include "proheader.h"

int freqSeats(int arr[]) //좌석의 수를 세는 함수 선언
{
	int freq = 0; //좌석의 수를 세는 변수 선언(초기화 0)
	int index; //인덱스를 세는 변수 선언

	for (index = 0; index < SIZE; index++)
	{
		if (arr[index] == 0) //빈좌석이면
			freq++; //좌석의 수를 1증가
	}

	return freq; //좌석의 수를 반환
}