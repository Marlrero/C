#include "preheader.h"

int find_customer_main(void) //고객을 찾는 함수의 원형
{
	int select; //메뉴함수를 호출하여 반환값을 저장하는 변수 선언
	int FuncRetu; //각각의 함수를 종료시킬 수 있는 값을 저장하는 변수 선언

	if (select = findMenuCusto()) //비정상종료하면
		return 1; //비정상종료값 반환
	
	//위 if문이 실행되지 않으면
	if (select == 1) //1번을 선택하면
	{
		while (1) // 무한루프
		{
			if (FuncRetu = find_customer_num()) //회원번호로 찾는 함수 호출하여 비정상종료하면
				continue; //다시 반복
			else if (FuncRetu == -1) //종료시키는 값 -1을 입력하면
				break; //루프를 빠져나감
			else //정상종료하면
				break; //루프를 빠져나감
		}
	}
	else if (select == 2) //2번을 선택하면
	{
		while (1) //무한루프
		{
			if (FuncRetu = find_customer_name()) //회원이름으로 찾는 함수 호출하여 비정상종료하면
				continue; //다시 반복
			else if (FuncRetu == -1) //종료시키는 값 -1을 입력하면
				break; //루프를 빠져나감
			else //정상종료하면
				break; //루프를 빠져나감
		}
	}
	else if (select == 3) //3번을 선택하면
	{
		while (1) //무한루프
		{
			if (FuncRetu = find_customer_hand()) //회원휴대폰번호로 찾는 함수 호출하여 비정상종료하면
				continue; //다시 반복
			else if (FuncRetu == -1) //종료시키는 값 -1을 입력하면
				break; //루프를 빠져나감
			else //정상종료하면
				break; //루프를 빠져나감
		}
	}
	else //잘못된 값을 입력하면
	{
		printf("메뉴를 잘못선택하였습니다! \n");
		return 1; //비정상종료
	}

	//위 else문이 실행되지 않으면
	return 0; //정상종료
}

int find_customer_num(void) //고객번호를 찾는 함수의 원형
{
	int input, index; //고객번호를 저장하는 변수, 배열의 인덱스를 세기 위한 변수 선언

	printf("회원번호 입력: ");
	scanf("%d", &input); //회원번호 입력

	//구조체 배열을 검사
	for (index = 0; index < PEOPLE; index++)
	{
		if (cusarr[index].num == input) //루프를 돌려 회원번호를 찾으면
			return index
	}
}

int find_customer_name(void) //고객이름을 찾는 함수의 원형
{

}

int find_customer_hand(void)//고객 핸드폰번호를 찾는 함수의 원형
{

}