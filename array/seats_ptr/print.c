#include "preheader.h"

int printMenus(void) //메뉴를 출력하는 함수의 정의
{
	int select; //메뉴번호를 저장하기 위한 변수 선언

	printf("\n==================== MENU ======================\n");
	printf("1. 예약하기\n");
	printf("2. 취소하기\n");
	printf("3. 변경하기\n");
	printf("4. 좌석보기\n");
	printf("5. 회원정보\n");
	printf("6. 종료하기\n");
	printf("메뉴를 선택하시오: ");
	scanf("%d", &select); //메뉴 선택

	if (select < 1 || select > 4) //메뉴를 잘못선택하면
		return 0;

	return select;
}

void printSeats(int arr[][COLUMN]) //좌석의 현재상태를 출력하는 함수의 정의
{
	int row, column; //배열의 행과 열을 세기 위한 변수 선언

	printf("\n==================== 좌석 ======================\n");
	printf("       1열 2열 3열 4열 5열 6열 7열 8열 9열 10열 \n");
	printf("================================================\n");

	for (row = 0; row < ROW; row++)
	{
		printf("%3d행", row + 1);
		for (column = 0; column < COLUMN; column++)
			printf(" %3d", arr[row][column]);
		printf("\n");
	}

	printf("================================================\n");
}

int findMenuCusto(void) //고객을 찾을 때 메뉴를 출력하는 함수의 정의
{
	int input; //고객을 찾을 때 입력하는 값을 저장할 변수 선언

	printf("\n================== 회원찾기 ====================\n");
	printf("1. 회원번호로 찾기 \n");
	printf("2. 이름으로 찾기 \n");
	printf("3. 핸드폰번호로 찾기 \n");
	printf("메뉴를 선택하시오: ");
	scanf("%d", &input); //메뉴 선택

	if (input < 1 || input > 3) //메뉴를 잘못선택하면
		return 0; //비정상종료

	return input; //정상종료하면 메뉴선택한 값을 반환
}
