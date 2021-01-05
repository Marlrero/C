#include <stdio.h> //IO
#include <stdlib.h> //malloc()
#include <string.h> //strlen()
#include "data.h"
#include "io.h"

int printMenus(void) //메뉴를 출력하는 함수의 정의
{
	int select; //메뉴번호를 저장하기 위한 변수 선언

	printf("\n===================== MENU ======================\n");
	printf("1. 예약하기\n");
	printf("2. 취소하기\n");
	printf("3. 변경하기\n");
	printf("4. 좌석보기\n");
	printf("5. 회원가입\n");
	printf("6. 회원탈퇴\n");
	printf("7. 회원목록\n");
	printf("8. 좌석상태\n");
	printf("9. 종료하기\n");
	printf("메뉴를 선택하시오: ");
	scanf_s("%d", &select); //메뉴 선택

	if (select < 1 || select > 9) //메뉴를 잘못선택하면
	{
		printf("메뉴를 잘못선택하였습니다!\n");
		printf("=================================================\n");
		return 0;
	}
	printf("=================================================\n");
	return select;
}

void printSeats(const int(*arr)[COLUMN]) //좌석의 현재상태를 출력하는 함수의 정의
{
	int row, column; //배열의 행과 열을 세기 위한 변수 선언

	printf("\n===================== 좌석 ======================\n");
	printf("       1열 2열 3열 4열 5열 6열 7열 8열 9열 10열 \n");
	printf("=================================================\n");

	for (row = 0; row < ROW; row++)
	{
		printf("%3d행", row + 1);
		for (column = 0; column < COLUMN; column++)
			printf(" %3d", (int)*(*(arr + row) + column));
		printf("\n");
	}

	printf("=================================================\n");
}

void printMemberList(CUSINFO *linked) //회원 명단을 출력하는 함수
{
	CUSINFO *now = linked; //현재 가리키고 있는 노드 포인터

	printf("=================================================\n");
	printf("|=====이름=====|======아이디======|===생년월일===|\n");

	if (linked == NULL)
		printf("가입한 회원정보가 없습니다!\n");

	while (now != NULL) //현재 가리키는 값이 NULL이면 모두 찾은 것임
	{
		printf("|%14s|%18s|%2d년%2d월%2d일|\n", now->name, now->id, now->birth.year, now->birth.month, now->birth.date);
		now = now->next; //현재 노드는 다음 노드를 가리킴
	}
	printf("=================================================\n");
}

void printMemberSeatList(const CUSINFO *member)
{
	int index;

	printf("=================================================\n");
	printf("<<%s님의 예약정보>>\n", member->name);
	printf("|=행=|=열=|\n");

	for (index = 0; index < SEAT_LIMIT; index++)
	{
		if ((member->infor_check[index].row > 0 && member->infor_check[index].row < 11) && (member->infor_check[index].column > 0 && member->infor_check[index].column < 11))
			printf("|%4d|%4d|\n", member->infor_check[index].row, member->infor_check[index].column);
		else
			continue; //범위를 벗어나는 값은 필요없으므로 출력안함
	}
	printf("=================================================\n");
}

char *inputString(const char *mode, const unsigned int size)
{
	char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
#ifdef DEBUG
	printf("debug >> inputString buffer allocate : %p \n", buffer);
#endif

	getchar(); //입력버퍼를 비운다.
	do 
	{
		printf("%s를(을) 입력하세요(%d자 이내): ", mode, size);
		scanf_s(" %s", buffer, size);
	} while ((unsigned)(strlen(buffer)) > size - 1); //제한길이보다 작으면 통과

	return buffer; //문자열을 반환
}

BIRTH *inputBirth(void)
{
	BIRTH *buffer = (BIRTH *)malloc(sizeof(BIRTH)); //버퍼
#ifdef DEBUG
	printf("debug >> inputBirth buffer allocate : %p \n", buffer);
#endif
	int year, month, date; //연도, 월, 일 버퍼

	do
	{
		printf("> 태어난 연도를 입력하세요: ");
		scanf_s("%d", &year);
	} while (year > 2017 || year < 1900); //연도 제한
	buffer->year = year; //버퍼에 저장

	while (1) //무한루프
	{
		printf("> 태어난 달을 입력하세요: ");
		scanf_s("%d", &month);

		if (month <= 0 || month > 12) //달 제한
			continue;

		printf("> 태어난 일을 입력하세요: ");
		scanf_s("%d", &date);

		if (date < 0 || date > 31) //일 제한
		{
			printf("일을 초과하는 범위를 입력하였습니다!\n");
			continue;
		}
		else
		{
			if (month == 2) //2월이면
			{
				if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && (date > 29))
				{
					printf("2월의 일수를 확인해주세요! \n");
					continue;
				}
			}

			if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) //4월, 6월, 9월, 11월에서 일 제한
			{
				printf("일을 초과하는 범위를 입력하였습니다!\n");
				continue;
			}
		}
		buffer->month = month;
		buffer->date = date; //버퍼에 저장
		break; //위 if문에 걸리지 않으면 break!
	}

	return buffer;
}