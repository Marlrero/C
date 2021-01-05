#include <stdio.h> //IO
#include <stdlib.h> //malloc()
#include <string.h> //strlen()
#include "data.h"
#include "io.h"

int printMenus(void) //�޴��� ����ϴ� �Լ��� ����
{
	int select; //�޴���ȣ�� �����ϱ� ���� ���� ����

	printf("\n===================== MENU ======================\n");
	printf("1. �����ϱ�\n");
	printf("2. ����ϱ�\n");
	printf("3. �����ϱ�\n");
	printf("4. �¼�����\n");
	printf("5. ȸ������\n");
	printf("6. ȸ��Ż��\n");
	printf("7. ȸ�����\n");
	printf("8. �¼�����\n");
	printf("9. �����ϱ�\n");
	printf("�޴��� �����Ͻÿ�: ");
	scanf_s("%d", &select); //�޴� ����

	if (select < 1 || select > 9) //�޴��� �߸������ϸ�
	{
		printf("�޴��� �߸������Ͽ����ϴ�!\n");
		printf("=================================================\n");
		return 0;
	}
	printf("=================================================\n");
	return select;
}

void printSeats(const int(*arr)[COLUMN]) //�¼��� ������¸� ����ϴ� �Լ��� ����
{
	int row, column; //�迭�� ��� ���� ���� ���� ���� ����

	printf("\n===================== �¼� ======================\n");
	printf("       1�� 2�� 3�� 4�� 5�� 6�� 7�� 8�� 9�� 10�� \n");
	printf("=================================================\n");

	for (row = 0; row < ROW; row++)
	{
		printf("%3d��", row + 1);
		for (column = 0; column < COLUMN; column++)
			printf(" %3d", (int)*(*(arr + row) + column));
		printf("\n");
	}

	printf("=================================================\n");
}

void printMemberList(CUSINFO *linked) //ȸ�� ����� ����ϴ� �Լ�
{
	CUSINFO *now = linked; //���� ����Ű�� �ִ� ��� ������

	printf("=================================================\n");
	printf("|=====�̸�=====|======���̵�======|===�������===|\n");

	if (linked == NULL)
		printf("������ ȸ�������� �����ϴ�!\n");

	while (now != NULL) //���� ����Ű�� ���� NULL�̸� ��� ã�� ����
	{
		printf("|%14s|%18s|%2d��%2d��%2d��|\n", now->name, now->id, now->birth.year, now->birth.month, now->birth.date);
		now = now->next; //���� ���� ���� ��带 ����Ŵ
	}
	printf("=================================================\n");
}

void printMemberSeatList(const CUSINFO *member)
{
	int index;

	printf("=================================================\n");
	printf("<<%s���� ��������>>\n", member->name);
	printf("|=��=|=��=|\n");

	for (index = 0; index < SEAT_LIMIT; index++)
	{
		if ((member->infor_check[index].row > 0 && member->infor_check[index].row < 11) && (member->infor_check[index].column > 0 && member->infor_check[index].column < 11))
			printf("|%4d|%4d|\n", member->infor_check[index].row, member->infor_check[index].column);
		else
			continue; //������ ����� ���� �ʿ�����Ƿ� ��¾���
	}
	printf("=================================================\n");
}

char *inputString(const char *mode, const unsigned int size)
{
	char *buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
#ifdef DEBUG
	printf("debug >> inputString buffer allocate : %p \n", buffer);
#endif

	getchar(); //�Է¹��۸� ����.
	do 
	{
		printf("%s��(��) �Է��ϼ���(%d�� �̳�): ", mode, size);
		scanf_s(" %s", buffer, size);
	} while ((unsigned)(strlen(buffer)) > size - 1); //���ѱ��̺��� ������ ���

	return buffer; //���ڿ��� ��ȯ
}

BIRTH *inputBirth(void)
{
	BIRTH *buffer = (BIRTH *)malloc(sizeof(BIRTH)); //����
#ifdef DEBUG
	printf("debug >> inputBirth buffer allocate : %p \n", buffer);
#endif
	int year, month, date; //����, ��, �� ����

	do
	{
		printf("> �¾ ������ �Է��ϼ���: ");
		scanf_s("%d", &year);
	} while (year > 2017 || year < 1900); //���� ����
	buffer->year = year; //���ۿ� ����

	while (1) //���ѷ���
	{
		printf("> �¾ ���� �Է��ϼ���: ");
		scanf_s("%d", &month);

		if (month <= 0 || month > 12) //�� ����
			continue;

		printf("> �¾ ���� �Է��ϼ���: ");
		scanf_s("%d", &date);

		if (date < 0 || date > 31) //�� ����
		{
			printf("���� �ʰ��ϴ� ������ �Է��Ͽ����ϴ�!\n");
			continue;
		}
		else
		{
			if (month == 2) //2���̸�
			{
				if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && (date > 29))
				{
					printf("2���� �ϼ��� Ȯ�����ּ���! \n");
					continue;
				}
			}

			if ((month == 4 || month == 6 || month == 9 || month == 11) && date > 30) //4��, 6��, 9��, 11������ �� ����
			{
				printf("���� �ʰ��ϴ� ������ �Է��Ͽ����ϴ�!\n");
				continue;
			}
		}
		buffer->month = month;
		buffer->date = date; //���ۿ� ����
		break; //�� if���� �ɸ��� ������ break!
	}

	return buffer;
}