#include <stdio.h> //FILE IO
#include <stdlib.h> //malloc() free() exit()
#include "data.h"
#include "file.h"

char DATA_LOCATE[LOCA_SIZE] = "H:\\대학교\\2017년 2학기 - 1학년\\2017-2 고급C프로그래밍 프로그래밍 파일\\Theater_Program\\database.bin";
char SEAT_LOCATE[LOCA_SIZE] = "H:\\대학교\\2017년 2학기 - 1학년\\2017-2 고급C프로그래밍 프로그래밍 파일\\Theater_Program\\seatdata.bin"; //파일의 위치 경로


FILE *checkFile(const char *locate, FILE **fp, const char *mode) //파일을 열때 체크하는 함수
{
	if ((*fp = fopen(locate, mode)) == NULL) //파일을 열었는데 NULL이면 오류임을 의미
	{
		fprintf(stderr, "파일 위치: %s에서 읽어들이지 못했습니다! \n", locate);
		exit(1); //비정상종료
	}

	return *fp;
}

void loadSeats(int(*arr)[COLUMN], FILE **seatdata) //좌석파일을 읽어서 배열로 불러오는 함수
{
	*seatdata = checkFile(SEAT_LOCATE, seatdata, "rb"); //읽기 모드로 파일을 연다.

	fread((void *)arr, sizeof(int), ROW * COLUMN, *seatdata); //배열을 한꺼번에 읽어서 매개변수 배열 arr에 저장

	fclose(*seatdata); //파일을 닫는다.
}

void loadCustom(CUSINFO **linked, FILE **database)
{
	*database = checkFile(DATA_LOCATE, database, "rb"); //읽기 모드로 파일을 연다.
	CUSINFO *now = NULL; //현재 노드
	CUSINFO *top = NULL; //링크드 리스트에 맨 끝

	while (1) //무한루프
	{
		now = (CUSINFO *)malloc(sizeof(CUSINFO)); //메모리 동적할당 -> 나중에 순회하면서 FREE해줘야 함
		fread((void *)now, sizeof(CUSINFO), 1, *database); //sizeof(tmp)를 한 이유는 한 회원에서 찾아야 하기 때문이다.
		if (feof(*database)) //읽어왔는데 파일의 끝이라면 --> 두 번 반복하는 일이 생김(http://me.tistory.com/380)
		{
#ifdef DEBUG
			printf("debug >> database END OF FILE \n");
#endif
			FREE(now); //현재 노드를 괜히 생성한 것이므로 FREE!
			break; //무한루프를 빠져나감
		}

#ifdef DEBUG
		printf("debug file Loading... memory allocate... \n");
		printf("debug now >> %s %s %s \n", now->id, now->password, now->name);
		printf("debug now >> %d %d %d \n", now->birth.year, now->birth.month, now->birth.date);
		printf("debug now >> %d %d %d %d %d \n", now->seat_count, now->infor_check[0].row, now->infor_check[0].column, now->infor_check[1].row, now->infor_check[1].column);
#endif
		now->next = NULL; //생성된 노드의 다음은 없다.
		if (*linked == NULL) //처음 노드 연결일 때에는
		{
			now->pre = NULL; //생성된 노드의 앞은 없다.
			*linked = now; //헤드 포인터는 처음 생성한 노드이다.
		}
		else //처음을 제외한 노드 연결일 때에는
		{
			top = getLastNode(*linked); //제일 마지막에 있는 노드를 가져온다.
			top->next = now; //제일 마지막에 있는 노드의 다음은 현재 생성한 노드이다.
			now->pre = top; //생성된 노드의 이전은 제일 마지막에 있는 노드이다.
		}
	}

	fclose(*database); //파일을 닫는다.
}

void saveSeats(int(*arr)[COLUMN], FILE **seatdata)
{
	*seatdata = checkFile(SEAT_LOCATE, seatdata, "wb"); //쓰기 모드로 파일을 연다.

	rewind(*seatdata); //파일 위치 지시자를 맨 앞으로 옮긴다.
	fflush(stdin); //입력 버퍼를 비운다.

	fwrite((void *)arr, sizeof(int), ROW * COLUMN, *seatdata); //파일에서 읽어온 데이터를 배열에 저장

	fclose(*seatdata); //파일을 닫는다.
}

void saveCustom(CUSINFO **linked, FILE **database) //동적할당한 메모리를 모두 반납해야 함
{
	*database = checkFile(DATA_LOCATE, database, "wb"); //쓰기 모드로 파일을 연다.
	CUSINFO *remove = NULL; //삭제할 노드를 임시로 저장할 포인터

	if (*linked == NULL)
	{
		printf("회원정보가 프로그램에 저장되어 있지 않습니다. \n");
		return;
	}

	remove = *linked;
	rewind(*database); //맨 앞으로 파일 위치 지시자를 옮긴다.
	while (1) //무한루프(연결리스트를 순차적으로 파일에 저장)
	{
#ifdef DEBUG
		printf("debug Loading... file write... \n");
		printf("debug now >> %s %s %s \n", remove->id, remove->password, remove->name);
		printf("debug now >> %d %d %d \n", remove->birth.year, remove->birth.month, remove->birth.date);
		printf("debug now >> %d %d %d %d %d \n", remove->seat_count, remove->infor_check[0].row, remove->infor_check[0].column, remove->infor_check[1].row, remove->infor_check[1].column);
#endif
		fwrite((void *)remove, sizeof(CUSINFO), 1, *database); //파일에 현재 노드를 쓴다
		remove = remove->next; //다음노드로 이동
		if (remove == NULL) //현재 탐색한 노드의 뒤가 없다면
			break; //종료조건
	}

	remove = NULL;
	while (1) //무한루프(메모리 순차해제)
	{
		remove = *linked; //삭제할 노드의 헤드포인터가 저장된다.
		*linked = (*linked)->next; //헤드포인터의 다음으로 이동한다.
#ifdef DEBUG
		printf("debug >> member memory free %s \n", remove->id);
#endif
		FREE(remove); //삭제할 노드를 메모리 해제한다.

		if (*linked == NULL) //헤드포인터가 NULL이면 다음 노드는 없다는 의미이다. (종료조건)
		{
			FREE(*linked);
			*linked = NULL;
			break; //무한루프를 빠져나간다.
		}

		(*linked)->pre = NULL; //헤드포인터 앞에는 아무것도 없다.
	}

	fclose(*database); //파일을 닫는다.
}