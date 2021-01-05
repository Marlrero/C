#include <stdio.h>
#include "proheader.h"

int bookSeats(int arr[]) //좌석을 예약하는 함수의 정의
{
	int answer; //좌석번호를 저장하는 변수 선언
	int loop, person; //반복을 세기 위한 변수, 사람 수를 저장할 변수 선언
	int rest; //남은 자리를 저장하는 변수 선언
	
	printf("\n============= 예약 =============\n");
	printf("몇 명을 예약하시겠습니까?: ");
	scanf("%d", &person);
	
	if (person < 1 || person > SIZE) //좌석 수를 초과하거나 적게 입력하면
	{
		printf("예약 인원을 잘못입력하였습니다!\n");
		return 1; //예약 실패
	}

	rest = freqSeats(arr); //좌석의 수를 세는 함수를 호출
	if (rest < person) //좌석의 수가 입력한 값보다 작으면
	{
		printf("남은 좌석이 현재 %d명입니다. 예약할 수 없습니다! \n", rest);
		return 1; //예약 실패
	}


	for (loop = 0; loop < person; loop++)
	{
		printf("손님%d - 몇번째 좌석을 예약하시겠습니까? : ", loop + 1);
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //값의 범위를 초과한 값을 입력하면
		{
			printf("1부터 10사이의 숫자를 입력하세요! \n");
			continue; //다시 조건식으로 돌아가 물어봄
		}

		if (arr[answer-1] == 0) //예약되지 않은 좌석이면
		{
			arr[answer-1] = 1; //예약한다.
			printf("예약되었습니다! \n");
			break;
		}
		else //이미 예약한 좌석이면
		{
			printf("이미 예약된 자리입니다! \n");
			return 1; //예약 실패
		}
	}

	printSeats(arr); //좌석을 보여줌
	return 0; //정상종료
}

int cancleSeats(int arr[]) //좌석을 취소하는 함수의 정의
{
	int answer; //좌석번호를 저장하는 변수 선언

	while (1)
	{
		printf("\n============= 취소 =============\n");
		printf("몇번째 좌석을 취소하시겠습니까? : ");
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //값의 범위를 초과한 값을 입력하면
		{
			printf("1부터 10사이의 숫자를 입력하세요! \n");
			continue; //다시 조건식으로 돌아가 물어봄
		}

		if (arr[answer-1] == 1) //예약된 좌석이면이면
		{
			arr[answer-1] = 0; //취소한다.
			printf("취소되었습니다! \n");
			break;
		}
		else //취소할 필요가 없는 좌석이면
		{
			printf("취소할 수 없는 자리입니다! \n");
			return 1; //취소 실패
		}
	}

	printSeats(arr); //좌석을 보여줌
	return 0; //정상종료
}

int changeSeats(int arr[]) //예약을 변경하는 함수의 정의
{
	int answer; //예약할 좌석을 저장하는 변수 선언

	printf("\n============= 변경 =============\n");
	if (cancleSeats(arr)) //취소하는 함수 호출하여 잘못 실행되면
		return 1; //변경 실패

	while (1) //무한루프
	{
		 //취소하는 함수가 정상 실행되었으면
		printf("예약할 좌석을 입력하세요: ");
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //값의 범위를 초과한 값을 입력하면
		{
			printf("1부터 10사이의 숫자를 입력하세요! \n");
			continue; //다시 조건식으로 돌아가 물어봄
		}

		if (arr[answer-1] == 0) //예약되지 않은 좌석이면
		{
			arr[answer-1] = 1; //예약한다.
			printf("예약되었습니다! \n");
			break; //반복문을 빠져나옴
		}
		else //이미 예약한 좌석이면
		{
			printf("이미 예약된 자리입니다! \n");
			continue; //다시 조건식으로 돌아가 물어봄
		}
	}

	return 0; //위 리턴문을 안만나면 정상 종료
}