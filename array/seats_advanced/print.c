#include <stdio.h>
#include "proheader.h"

int printMenus(void) //메뉴를 출력하는 함수의 정의
{
	int select; //메뉴번호를 저장하기 위한 변수 선언

	printf("\n============= MENU =============\n");
	printf("1. 예약하기\n");
	printf("2. 취소하기\n");
	printf("3. 변경하기\n");
	printf("4. 종료하기\n");
	printf("메뉴를 선택하시오: ");
	scanf("%d", &select); //메뉴 선택

	if (select < 1 || select > 4) //메뉴를 잘못선택하면
		return 0;

	return select;
}

void printSeats(int arr[]) //좌석의 현재상태를 출력하는 함수의 정의
{
	int index; //배열의 인덱스를 세기 위한 변수 선언

	printf("\n============= 좌석 =============\n");
	printf("  1  2  3  4  5  6  7  8  9  10 \n");
	printf("================================\n");

	for (index = 0; index < SIZE; index++)
		printf("  %d", arr[index]);

	printf("\n");
	printf("================================\n");
}