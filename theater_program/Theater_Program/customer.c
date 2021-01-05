#include <stdio.h> //IO
#include <stdlib.h> //malloc() free()
#include <string.h> //strcmp()
#include "data.h"
#include "reservation.h"
#include "customer.h"
#include "io.h"
#include "file.h"

void createMembership(CUSINFO **linked)
{
	char *buffer1 = NULL, *buffer2 = NULL; //문자열 저장 버퍼
	BIRTH *buffer3 = NULL; //생년월일 정보 저장 버퍼
	CUSINFO *check = NULL; //회원찾기에서 얻어온 정보 저장
	CUSINFO *member = (CUSINFO *)malloc(sizeof(CUSINFO)); //노드 생성
	CUSINFO *last = getLastNode(*linked); //맨 뒤에 있는 노드의 포인터

	printf("=====================회원가입====================\n");;
	buffer1 = inputString("이름", NAME_LENGTH);
	strcpy_s(member->name, NAME_LENGTH, buffer1); //복사
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer1);
#endif
	FREE(buffer1); //버퍼 해제

	while (1) //무한루프
	{
		buffer1 = inputString("아이디", ID_LENGTH);
		check = searchMembership(1, buffer1, NULL, *linked);
		if (check == NULL) //아이디 중복검사 함수 실행
			printf("이미 사용중인 아이디입니다! \n");
		else //중복검사에서 중복되지 않으면
			break; //무한루프 빠져나감
	}
	strcpy_s(member->id, ID_LENGTH, buffer1); //복사
	FREE(buffer1); //버퍼 해제
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer1);
#endif

	while (1) //무한루프
	{
		buffer1 = inputString("비밀번호", PWD_LENGTH);
		buffer2 = inputString("비밀번호 확인", PWD_LENGTH);
		if ( strcmp(buffer1, buffer2) == 0 ) //비밀번호가 두 개가 모두 같으면
		{
			strcpy_s(member->password, PWD_LENGTH, buffer1); //복사
			break; //무한루프 빠져나감
		}
		else
			printf("비밀번호와 비밀번호 확인이 맞지 않습니다. 다시 입력해주세요. \n");
	}
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer1);
	printf("debug >> buffer free : %p \n", buffer2);
#endif
	FREE(buffer1); //버퍼 해제
	FREE(buffer2); //버퍼 해제

	buffer3 = inputBirth(); //함수를 호출하여 생년월일을 입력한다.
	member->birth.year = buffer3->year;
	member->birth.month = buffer3->month;
	member->birth.date = buffer3->date; //복사
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer3);
#endif
	FREE(buffer3); //버퍼 해제

	member->seat_count = 0;
	member->infor_check[0].row = -1;
	member->infor_check[0].column = -1;
	member->infor_check[1].row = -1;
	member->infor_check[1].column = -1; //좌석 초기화

	member->next = NULL; //맨 뒤에 넣으므로 다음은 없음
	if (*linked == NULL) //처음 생성이면
	{
		member->pre = NULL; //처음 생성한 노드의 앞은 없다.
		*linked = member; //헤드포인터와 생성한 노드를 연결한다.
	}
	else //처음 생성이 아니면
	{
		last->next = member; //맨 뒤에 있었던 노드 다음에는 현재 생성한 노드와 연결된다.
		member->pre = last; //현재 생성한 노드의 이전 노드는 그 전에 맨 뒤에 있었던 노드이다.
	}

	getchar();
#ifdef DEBUG
	printf("debug >> allocate member %p %s\n", member, member->id);
#endif
	printf("=================================================\n");
}

CUSINFO *loginMembership(CUSINFO *linked) //로그인하는 함수
{
	char *inputid = NULL;
	char *inputpassword = NULL; //아이디, 패스워드 버퍼
	CUSINFO *findmember = NULL; //찾은 멤버를 저장
	CUSINFO *last = getLastNode(linked); //맨 뒤에 있는 노드의 포인터

	printf("\n=====================로그인======================\n");
	inputid = inputString("아이디", ID_LENGTH);
	inputpassword = inputString("비밀번호", PWD_LENGTH);

	if ( (findmember = searchMembership(2, inputid, inputpassword, linked)) == NULL ) //회원정보가 없으면
	{
		printf("회원정보가 없습니다!\n");
		return NULL; //없으면 NULL을 반환!
	}

#ifdef DEBUG
	printf("debug >> buffer inputid inputpwd free : %s %s \n", inputid, inputpassword);
#endif
	FREE(inputid);
	FREE(inputpassword); //메모리 해제

	printf("=================================================\n");
	return findmember; //찾으면 찾은 구조체를 참조하고 있는 주소값 반환!
}

void deleteMembership(CUSINFO *member, int (*arr)[COLUMN], CUSINFO **linked)
{
	int ch;
	int drow1 = -1, dcol1 = -1, drow2 = -1, dcol2 = -1;

	printMemberSeatList(member); //현재 좌석을 보여준다.
	if (member->seat_count > 0) //탈퇴할 회원이 예약좌석이 있다면
	{
		printf("예약한 좌석이 모두 취소됩니다.");
		if (member->infor_check[0].row != -1 && member->infor_check[0].column != -1) //첫번째 예약좌석이 있다면
		{
			drow1 = member->infor_check[0].row;
			dcol1 = member->infor_check[0].column;
		}

		if (member->infor_check[1].row != -1 && member->infor_check[1].column != -1) //두번재 예약좌석이 있다면
		{
			drow2 = member->infor_check[1].row;
			dcol2 = member->infor_check[1].column;
		}
	}

	while (1) //무한루프
	{
		getchar(); //입력버퍼 비움
		printf("탈퇴하시겠습니까?(y, n) ");
		ch = getchar();
		if (ch == 'y') //yes이면
		{
			if (drow1 != -1 && dcol1 != -1)
				*(*(arr + drow1 - 1) + dcol1 - 1) = 0; //취소
			if (drow2 != -1 && dcol2 != -1)
				*(*(arr + drow2 - 1) + dcol2 - 1) = 0; //취소

			printSeats(arr);
			removeNode(member, linked);
			printf("탈퇴가 완료되었습니다. \n");
			break; //종료
		}
		else if (ch == 'n') //no이면
		{
			printf("탈퇴를 취소하였습니다. \n");
			break; //종료
		}
		else
			printf("y와 n 중 하나를 입력하세요. \n");
	}
}

CUSINFO *searchMembership(const int mode, const char *keyid, const char *keypwd, CUSINFO *linked) //회원을 찾는 함수
{
	CUSINFO *current = linked; //읽어들일 내용을 저장하기 위한 임시 변수

	if (mode == 1 && linked == NULL) //처음 가입한 사람은!
		return (CUSINFO *)1; //성공

	if (linked == NULL) //회원DB에 정보가 없으면
	{
		printf("회원정보DB에 데이터가 존재하지 않습니다. \n");
		return NULL; //실패!
	}

	while (current != NULL)
	{
		if (mode == 1) //아이디만 검사 (중복검사)
		{
			if ( strcmp(current->id, keyid) == 0 ) //아이디를 찾으면
				return NULL; //중복했으므로 실패! (종료조건)
		}
		else //아이디와 비밀번호 검사 (로그인)
		{
			if ( (strcmp(current->id, keyid) == 0) && (strcmp(current->password, keypwd) == 0) ) //아이디와 비밀번호를 모두 찾으면
				return current; //현재 노드 반환 (종료조건)
		}
		
		current = current->next;
	}

	if (mode == 1) //아이디 중복검사시 찾지 못한 경우에는
		return (CUSINFO *)1; //성공!
	else //로그인시 찾지 못한 경우에는
		return NULL; //실패!
}

int addCustomSeats(CUSINFO *member, const int row, const int column) //회원의 좌석을 검사하여 회원데이터 추가
{
	if (member->infor_check[0].row == -1 || member->infor_check[0].column == -1) //하나의 좌석이 이미 -1이면 공석이므로
	{
		member->infor_check[0].row = row;
		member->infor_check[0].column = column; //로그인한 회원의 데이터 변경
		(member->seat_count)++; //예약한 좌석의 수 증가
	}
	else if (member->infor_check[1].row == -1 || member->infor_check[1].column == -1) //하나의 좌석이 이미 -1이면 공석이므로
	{
		member->infor_check[1].row = row;
		member->infor_check[1].column = column; //로그인한 회원의 데이터 변경
		(member->seat_count)++; //예약한 좌석의 수 증가
	}
	else
		return 1; //실패

	return 0; //성공
}

int deleteCustomSeats(CUSINFO *member, const int row, const int column) //회원의 좌석을 검사하여 회원데이터 삭제
{
	int count = 0;

	if (member->infor_check[0].row == row && member->infor_check[0].column == column) //첫번째 좌석을 찾으면
	{
		member->infor_check[0].row = -1;
		member->infor_check[0].column = -1; //취소
		(member->seat_count)--; //예약한 좌석의 수 감소
		count++;
	}
	
	if (member->infor_check[1].row == row && member->infor_check[1].column == column) //두번째 좌석을 찾으면
	{
		member->infor_check[1].row = -1;
		member->infor_check[1].column = -1; //취소
		(member->seat_count)--; //예약한 좌석의 수 감소
		count++;
	}

	if (count == 2) //두 좌석을 나란히 예약할 수 없기 때문에 논리적인 오류
	{
#ifdef DEBUG
		printf("debug >> 논리오류 \n");
#endif
		return 1; //실패 DEBUG
	}
	else if (count == 1) //한 개의 좌석을 취소했으면
		return 0; //성공 (취소가 된 것임)
	else
		return -1; //성공 (취소가 되지 않았지만, 예약하지 않은 좌석을 취소하려 했음)
}