#include <stdio.h>
#define SIZE 10

/* 
   좌석을 전역변수로 사용하면 인자로 배열을 전달할 필요는 없음
   void printSeats(void);
   void bookSeats(int answer);
*/

//아래의 방식은 배열과 포인터를 이용한 방식
int printMenus(void); //메뉴를 출력하는 함수의 원형
void printSeats(int arr[]); //좌석의 현재상태를 출력하는 함수의 원형
int bookSeats(int arr[]); //좌석을 예약하는 함수의 원형
int cancleSeats(int arr[]); //좌석을 취소하는 함수의 원형

int main(void)
{
	int menu; //메뉴를 저장할 변수
	int seats[SIZE] = {0}; //현재 좌석 상태는 0
	
	while (1) //무한루프
	{	
		menu = printMenus(); //메뉴 출력

		if (menu == 1) //예약하기
		{
			printSeats(seats);
			if (bookSeats(seats)) //함수가 잘못 실행되면
				continue; //다시 루프 시작
			printSeats(seats); //예약이 정상적으로 되었는지 출력
		}
		else if (menu == 2) //취소하기
		{
			printSeats(seats);
			if (cancleSeats(seats)) //함수가 잘못 실행되면
				continue; //다시 루프 시작
			printSeats(seats); //취소가 정상적으로 되었는지 출력
		}
		else if (menu == 3) //종료하기
		{
			printSeats(seats); //종료 전 좌석 상황 출력
			printf("프로그램이 종료됩니다!\n");
			return 0; //프로그램 종료
		}
		else //잘못 메뉴를 입력한 경우
		{
			printf("메뉴 선택을 다시하세요!\n");
			continue;
		}
	}

	return 0;
}

int printMenus(void) //메뉴를 출력하는 함수의 정의
{
	int select; //메뉴번호를 저장하기 위한 변수 선언

	printf("============== MENU ============\n");
	printf("1. 예약하기\n");
	printf("2. 취소하기\n");
	printf("3. 종료하기\n");
	printf("메뉴를 선택하시오: ");
	scanf("%d", &select); //메뉴 선택
	printf("================================\n");

	if (select < 1 || select > 3) //메뉴를 잘못선택하면
		return 0;

	return select;
}

void printSeats(int arr[]) //좌석의 현재상태를 출력하는 함수의 정의
{
	int index; //배열의 인덱스를 세기 위한 변수 선언

	printf("============= 좌석 =============\n");
	printf("  1  2  3  4  5  6  7  8  9  10 \n");
	printf("================================\n");

	for (index = 0; index < SIZE; index++)
		printf("  %d", arr[index]);

	printf("\n");
	printf("================================\n");
}

int bookSeats(int arr[]) //좌석을 예약하는 함수의 정의
{
	int answer; //좌석번호를 저장하는 변수 선언
	int loop, person; //반복을 세기 위한 변수, 사람 수를 저장할 변수 선언
				
	printf("몇 명을 예약하시겠습니까?: ");
	scanf("%d", &person);
	
	if (person < 1 || person > SIZE) //좌석 수를 초과하거나 적게 입력하면
	{
		printf("예약 인원을 잘못입력하였습니다!\n");
		return 1; //예약 실패
	}

	for (loop = 0; loop < person; loop++)
	{
		printf("손님%d - 몇번째 좌석을 예약하시겠습니까? : ", loop + 1);
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //값의 범위를 초과한 값을 입력하면
		{
			printf("1부터 10사이의 숫자를 입력하세요! \n");
			continue;
		}

		if (arr[answer-1] == 0) //예약되지 않은 좌석이면
		{
			arr[answer-1] = 1; //예약한다.
			printf("예약되었습니다! \n");
		}
		else //이미 예약한 좌석이면
		{
			printf("이미 예약된 자리입니다! \n");
			return 1; //예약 실패
		}
	}

	return 0; //정상종료
}

int cancleSeats(int arr[]) //좌석을 취소하는 함수의 정의 --> 취소함수를 무한루프로 돌릴 필요가 있을까??
{
	int answer; //좌석번호를 저장하는 변수 선언

	while (1) //무한루프
	{
		printf("몇번째 좌석을 취소하시겠습니까? : ");
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //값의 범위를 초과한 값을 입력하면
		{
			printf("1부터 10사이의 숫자를 입력하세요! \n");
			continue;
		}

		if (arr[answer-1] == 1) //예약된 좌석이면이면
		{
			arr[answer-1] = 0; //취소한다.
			printf("취소되었습니다! \n");
			break; //취소가 완료되면 무한루프를 벗어남
		}
		else //취소할 필요가 없는 좌석이면
		{
			printf("취소할 수 없는 자리입니다! \n");
			return 1; //취소 실패
		}
	}
	return 0; //정상종료
}