#include <stdio.h> //FILE IO
#include <stdlib.h> //malloc() free() exit()
#include "data.h"
#include "file.h"

char DATA_LOCATE[LOCA_SIZE] = "H:\\���б�\\2017�� 2�б� - 1�г�\\2017-2 ���C���α׷��� ���α׷��� ����\\Theater_Program\\database.bin";
char SEAT_LOCATE[LOCA_SIZE] = "H:\\���б�\\2017�� 2�б� - 1�г�\\2017-2 ���C���α׷��� ���α׷��� ����\\Theater_Program\\seatdata.bin"; //������ ��ġ ���


FILE *checkFile(const char *locate, FILE **fp, const char *mode) //������ ���� üũ�ϴ� �Լ�
{
	if ((*fp = fopen(locate, mode)) == NULL) //������ �����µ� NULL�̸� �������� �ǹ�
	{
		fprintf(stderr, "���� ��ġ: %s���� �о������ ���߽��ϴ�! \n", locate);
		exit(1); //����������
	}

	return *fp;
}

void loadSeats(int(*arr)[COLUMN], FILE **seatdata) //�¼������� �о �迭�� �ҷ����� �Լ�
{
	*seatdata = checkFile(SEAT_LOCATE, seatdata, "rb"); //�б� ���� ������ ����.

	fread((void *)arr, sizeof(int), ROW * COLUMN, *seatdata); //�迭�� �Ѳ����� �о �Ű����� �迭 arr�� ����

	fclose(*seatdata); //������ �ݴ´�.
}

void loadCustom(CUSINFO **linked, FILE **database)
{
	*database = checkFile(DATA_LOCATE, database, "rb"); //�б� ���� ������ ����.
	CUSINFO *now = NULL; //���� ���
	CUSINFO *top = NULL; //��ũ�� ����Ʈ�� �� ��

	while (1) //���ѷ���
	{
		now = (CUSINFO *)malloc(sizeof(CUSINFO)); //�޸� �����Ҵ� -> ���߿� ��ȸ�ϸ鼭 FREE����� ��
		fread((void *)now, sizeof(CUSINFO), 1, *database); //sizeof(tmp)�� �� ������ �� ȸ������ ã�ƾ� �ϱ� �����̴�.
		if (feof(*database)) //�о�Դµ� ������ ���̶�� --> �� �� �ݺ��ϴ� ���� ����(http://me.tistory.com/380)
		{
#ifdef DEBUG
			printf("debug >> database END OF FILE \n");
#endif
			FREE(now); //���� ��带 ���� ������ ���̹Ƿ� FREE!
			break; //���ѷ����� ��������
		}

#ifdef DEBUG
		printf("debug file Loading... memory allocate... \n");
		printf("debug now >> %s %s %s \n", now->id, now->password, now->name);
		printf("debug now >> %d %d %d \n", now->birth.year, now->birth.month, now->birth.date);
		printf("debug now >> %d %d %d %d %d \n", now->seat_count, now->infor_check[0].row, now->infor_check[0].column, now->infor_check[1].row, now->infor_check[1].column);
#endif
		now->next = NULL; //������ ����� ������ ����.
		if (*linked == NULL) //ó�� ��� ������ ������
		{
			now->pre = NULL; //������ ����� ���� ����.
			*linked = now; //��� �����ʹ� ó�� ������ ����̴�.
		}
		else //ó���� ������ ��� ������ ������
		{
			top = getLastNode(*linked); //���� �������� �ִ� ��带 �����´�.
			top->next = now; //���� �������� �ִ� ����� ������ ���� ������ ����̴�.
			now->pre = top; //������ ����� ������ ���� �������� �ִ� ����̴�.
		}
	}

	fclose(*database); //������ �ݴ´�.
}

void saveSeats(int(*arr)[COLUMN], FILE **seatdata)
{
	*seatdata = checkFile(SEAT_LOCATE, seatdata, "wb"); //���� ���� ������ ����.

	rewind(*seatdata); //���� ��ġ �����ڸ� �� ������ �ű��.
	fflush(stdin); //�Է� ���۸� ����.

	fwrite((void *)arr, sizeof(int), ROW * COLUMN, *seatdata); //���Ͽ��� �о�� �����͸� �迭�� ����

	fclose(*seatdata); //������ �ݴ´�.
}

void saveCustom(CUSINFO **linked, FILE **database) //�����Ҵ��� �޸𸮸� ��� �ݳ��ؾ� ��
{
	*database = checkFile(DATA_LOCATE, database, "wb"); //���� ���� ������ ����.
	CUSINFO *remove = NULL; //������ ��带 �ӽ÷� ������ ������

	if (*linked == NULL)
	{
		printf("ȸ�������� ���α׷��� ����Ǿ� ���� �ʽ��ϴ�. \n");
		return;
	}

	remove = *linked;
	rewind(*database); //�� ������ ���� ��ġ �����ڸ� �ű��.
	while (1) //���ѷ���(���Ḯ��Ʈ�� ���������� ���Ͽ� ����)
	{
#ifdef DEBUG
		printf("debug Loading... file write... \n");
		printf("debug now >> %s %s %s \n", remove->id, remove->password, remove->name);
		printf("debug now >> %d %d %d \n", remove->birth.year, remove->birth.month, remove->birth.date);
		printf("debug now >> %d %d %d %d %d \n", remove->seat_count, remove->infor_check[0].row, remove->infor_check[0].column, remove->infor_check[1].row, remove->infor_check[1].column);
#endif
		fwrite((void *)remove, sizeof(CUSINFO), 1, *database); //���Ͽ� ���� ��带 ����
		remove = remove->next; //�������� �̵�
		if (remove == NULL) //���� Ž���� ����� �ڰ� ���ٸ�
			break; //��������
	}

	remove = NULL;
	while (1) //���ѷ���(�޸� ��������)
	{
		remove = *linked; //������ ����� ��������Ͱ� ����ȴ�.
		*linked = (*linked)->next; //����������� �������� �̵��Ѵ�.
#ifdef DEBUG
		printf("debug >> member memory free %s \n", remove->id);
#endif
		FREE(remove); //������ ��带 �޸� �����Ѵ�.

		if (*linked == NULL) //��������Ͱ� NULL�̸� ���� ���� ���ٴ� �ǹ��̴�. (��������)
		{
			FREE(*linked);
			*linked = NULL;
			break; //���ѷ����� ����������.
		}

		(*linked)->pre = NULL; //��������� �տ��� �ƹ��͵� ����.
	}

	fclose(*database); //������ �ݴ´�.
}