#include <stdio.h>
#include <stdlib.h> //free()
#include "data.h"
#include "check.h"
#include "io.h"
#include "customer.h"
#include "reservation.h"

int bookSeats(int(*arr)[COLUMN], CUSINFO *member) //좌석을 예약하는 함수
{
	int row, column; //행과 열을 저장하기 위한 변수 선언
	int loop, person, check; //반복을 세기 위한 변수, 사람 수를 저장할 변수 선언
	int rest; //남은 자리를 저장하는 변수

	printf("\n==================== 예약 ======================\n");
	printf("몇 명을 예약하시겠습니까?: ");
	scanf_s("%d", &person);

	if (person < 1 || person > ROW * COLUMN) //좌석 수를 초과하거나 적게 입력하면
	{
		printf("예약 인원을 잘못입력하였습니다!\n");
		return 1; //예약 실패
	}

	if (person > SEAT_LIMIT - (member->seat_count)) //회원당 예약좌석을 초과하면
	{
		printf("회원님이 예약한 좌석을 초과하였습니다.(현재 예약좌석: %d) \n", member->seat_count);
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
		printf("손님%d - 몇번째 좌석을 예약하시겠습니까(~행~열)? : ", loop + 1);
		scanf_s("%d %d", &row, &column);

		if (checkInput(row, column))
			return 0; //예약 실패

		if (*(*(arr + (row - 1)) + (column - 1)) == 0) //예약되지 않은 좌석이면
		{
			*(*(arr + (row - 1)) + (column - 1)) = 1; //예약한다.

			if (check = addCustomSeats(member, row, column)) //회원의 좌석을 검사하여 회원데이터 변경
			{
				printf("회원님이 예약한 좌석을 초과하였습니다.(현재 예약좌석: %d) \n", member->seat_count);
				return 1; //예약 실패
			}
			else
				printf("예약되었습니다! \n");
		}
		else //이미 예약한 좌석이면
		{
			printf("이미 예약된 자리입니다! %d명만 예약되었습니다! \n", loop);
			return 1; //예약 실패
		}
	}

	printSeats(arr); //좌석을 보여줌
	return 0; //정상종료
}

int cancleSeats(int(*arr)[COLUMN], CUSINFO *member) //좌석을 취소하는 함수
{
	int row, column, check; //행과 열을 저장하기 위한 변수 선언

	while (1)
	{
		printf("\n==================== 취소 ======================\n");
		printf("몇번째 좌석을 취소하시겠습니까(~행~열)? : ");
		scanf_s("%d %d", &row, &column);

		if (checkInput(row, column))
			return 1; //취소 실패

		check = deleteCustomSeats(member, row, column);
		if (check == -1)
		{
			printf("회원님의 좌석을 선택하여주세요!\n");
			return 1; //취소 실패
		}
		else if (check == 1)
		{
#ifdef DEBUG
			printf("프로그램 논리 오류 발생! \n");
#endif
			return 1; //취소 실패
		}
		else
		{
			if (*(*(arr + (row - 1)) + (column - 1)) == 1) //예약된 좌석이면이면
			{
				*(*(arr + (row - 1)) + (column - 1)) = 0; //취소한다.

				printf("취소되었습니다! \n");
				printSeats(arr); //좌석을 보여줌
				return 0;
			}
			else //취소할 필요가 없는 좌석이면
			{
				printf("취소할 수 없는 자리입니다! \n");
				return 1; //취소 실패
			}
		}
	}
}

int changeSeats(int(*arr)[COLUMN], CUSINFO *member) //예약을 변경하는 함수
{
	int row, column, check; //행과 열을 저장하기 위한 변수 선언
	CUSINFO *findkey = NULL; //취소했을 때 썼던 인덱스 저장

	printf("\n==================== 변경 ======================\n");
	if ( cancleSeats(arr, member) ) //취소하는 함수 호출하여 잘못 실행되면
		return 1; //변경 실패

	while (1) //무한루프
	{
		//취소하는 함수가 정상 실행되었으면
		printf("예약할 좌석을 입력하세요(~행 ~열): ");
		scanf_s("%d %d", &row, &column);

		if ( checkInput(row, column) ) //입력값을 잘못입력하면
			return 1; //예약 실패

		if ( *(*(arr + (row - 1)) + (column - 1)) == 0 ) //예약되지 않은 좌석이면
		{
			*(*(arr + (row - 1)) + (column - 1)) = 1; //예약한다.

			if ( check = addCustomSeats(member, row, column) ) //회원의 좌석을 검사하여 회원데이터 변경
			{
				printf("회원님이 예약한 좌석을 초과하였습니다.(현재 예약좌석: %d) \n", member->seat_count);
				return 1; //예약 실패
			}
			else
			{
				printf("예약되었습니다! \n");
				break;
			}

		}
		else //이미 예약한 좌석이면
		{
			printf("이미 예약된 자리입니다! \n");
			continue; //다시 조건식으로 돌아가 물어봄
		}
	}

	return 0; //위 리턴문을 안만나면 정상 종료
}

CUSINFO *getLastNode(CUSINFO *linked)
{
	CUSINFO *last = linked;

	if (linked == NULL)
		return NULL;

#ifdef DEBUG
	printf("debug >> linked %s \n", linked->id);
#endif
	while (1) //현재 노드가 NULL이면 모두 순환한 것이다.
	{
#ifdef DEBUG
		printf("debug >> last %s \n", last->id);
#endif
		if (last->next == NULL) //다음 노드가 없으면
		{
#ifdef DEBUG
			printf("debug >> if last->next == NULL then %s \n", last->id);
#endif
			return last; //현재 노드를 반환한다. (종료조건)
		}
		last = last->next;
	}
}

void removeNode(CUSINFO *member, CUSINFO **linked)
{
	CUSINFO *pre = member->pre;
	CUSINFO *next = member->next;

	if (pre == NULL && next == NULL) //한 개의 노드만 있는 경우
	{
		*linked = NULL; //헤드포인터와 연결을 끊음
	}
	else if (pre == NULL) //맨 앞 노드일 경우
	{
		next->pre = NULL; //삭제할 노드의 다음 노드와 연결을 끊는다.
		*linked = next; //삭제하면 다음노드가 맨 앞에 노드가 된다.
	}
	else if (next == NULL) //맨 뒤 노드일 경우
	{
		pre->next = NULL; //삭제할 노드의 앞 노드와 연결을 끊는다.
	}
	else //중간 노드일 경우
	{
		pre->next = next; //삭제할 노드의 앞 노드는 삭제할 노드의 뒤 노드와 연결한다.
		next->pre = pre; //삭제할 노드의 뒤 노드는 삭제할 노드의 앞 노드와 연결한다.
	}

#ifdef DEBUG
	printf("debug >> %s memory free!! \n", member->id);
#endif
	FREE(member);
}