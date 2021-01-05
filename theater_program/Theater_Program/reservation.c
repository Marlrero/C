#include <stdio.h>
#include <stdlib.h> //free()
#include "data.h"
#include "check.h"
#include "io.h"
#include "customer.h"
#include "reservation.h"

int bookSeats(int(*arr)[COLUMN], CUSINFO *member) //�¼��� �����ϴ� �Լ�
{
	int row, column; //��� ���� �����ϱ� ���� ���� ����
	int loop, person, check; //�ݺ��� ���� ���� ����, ��� ���� ������ ���� ����
	int rest; //���� �ڸ��� �����ϴ� ����

	printf("\n==================== ���� ======================\n");
	printf("�� ���� �����Ͻðڽ��ϱ�?: ");
	scanf_s("%d", &person);

	if (person < 1 || person > ROW * COLUMN) //�¼� ���� �ʰ��ϰų� ���� �Է��ϸ�
	{
		printf("���� �ο��� �߸��Է��Ͽ����ϴ�!\n");
		return 1; //���� ����
	}

	if (person > SEAT_LIMIT - (member->seat_count)) //ȸ���� �����¼��� �ʰ��ϸ�
	{
		printf("ȸ������ ������ �¼��� �ʰ��Ͽ����ϴ�.(���� �����¼�: %d) \n", member->seat_count);
		return 1; //���� ����
	}

	rest = freqSeats(arr); //�¼��� ���� ���� �Լ��� ȣ��
	if (rest < person) //�¼��� ���� �Է��� ������ ������
	{
		printf("���� �¼��� ���� %d���Դϴ�. ������ �� �����ϴ�! \n", rest);
		return 1; //���� ����
	}

	for (loop = 0; loop < person; loop++)
	{
		printf("�մ�%d - ���° �¼��� �����Ͻðڽ��ϱ�(~��~��)? : ", loop + 1);
		scanf_s("%d %d", &row, &column);

		if (checkInput(row, column))
			return 0; //���� ����

		if (*(*(arr + (row - 1)) + (column - 1)) == 0) //������� ���� �¼��̸�
		{
			*(*(arr + (row - 1)) + (column - 1)) = 1; //�����Ѵ�.

			if (check = addCustomSeats(member, row, column)) //ȸ���� �¼��� �˻��Ͽ� ȸ�������� ����
			{
				printf("ȸ������ ������ �¼��� �ʰ��Ͽ����ϴ�.(���� �����¼�: %d) \n", member->seat_count);
				return 1; //���� ����
			}
			else
				printf("����Ǿ����ϴ�! \n");
		}
		else //�̹� ������ �¼��̸�
		{
			printf("�̹� ����� �ڸ��Դϴ�! %d�� ����Ǿ����ϴ�! \n", loop);
			return 1; //���� ����
		}
	}

	printSeats(arr); //�¼��� ������
	return 0; //��������
}

int cancleSeats(int(*arr)[COLUMN], CUSINFO *member) //�¼��� ����ϴ� �Լ�
{
	int row, column, check; //��� ���� �����ϱ� ���� ���� ����

	while (1)
	{
		printf("\n==================== ��� ======================\n");
		printf("���° �¼��� ����Ͻðڽ��ϱ�(~��~��)? : ");
		scanf_s("%d %d", &row, &column);

		if (checkInput(row, column))
			return 1; //��� ����

		check = deleteCustomSeats(member, row, column);
		if (check == -1)
		{
			printf("ȸ������ �¼��� �����Ͽ��ּ���!\n");
			return 1; //��� ����
		}
		else if (check == 1)
		{
#ifdef DEBUG
			printf("���α׷� �� ���� �߻�! \n");
#endif
			return 1; //��� ����
		}
		else
		{
			if (*(*(arr + (row - 1)) + (column - 1)) == 1) //����� �¼��̸��̸�
			{
				*(*(arr + (row - 1)) + (column - 1)) = 0; //����Ѵ�.

				printf("��ҵǾ����ϴ�! \n");
				printSeats(arr); //�¼��� ������
				return 0;
			}
			else //����� �ʿ䰡 ���� �¼��̸�
			{
				printf("����� �� ���� �ڸ��Դϴ�! \n");
				return 1; //��� ����
			}
		}
	}
}

int changeSeats(int(*arr)[COLUMN], CUSINFO *member) //������ �����ϴ� �Լ�
{
	int row, column, check; //��� ���� �����ϱ� ���� ���� ����
	CUSINFO *findkey = NULL; //������� �� ��� �ε��� ����

	printf("\n==================== ���� ======================\n");
	if ( cancleSeats(arr, member) ) //����ϴ� �Լ� ȣ���Ͽ� �߸� ����Ǹ�
		return 1; //���� ����

	while (1) //���ѷ���
	{
		//����ϴ� �Լ��� ���� ����Ǿ�����
		printf("������ �¼��� �Է��ϼ���(~�� ~��): ");
		scanf_s("%d %d", &row, &column);

		if ( checkInput(row, column) ) //�Է°��� �߸��Է��ϸ�
			return 1; //���� ����

		if ( *(*(arr + (row - 1)) + (column - 1)) == 0 ) //������� ���� �¼��̸�
		{
			*(*(arr + (row - 1)) + (column - 1)) = 1; //�����Ѵ�.

			if ( check = addCustomSeats(member, row, column) ) //ȸ���� �¼��� �˻��Ͽ� ȸ�������� ����
			{
				printf("ȸ������ ������ �¼��� �ʰ��Ͽ����ϴ�.(���� �����¼�: %d) \n", member->seat_count);
				return 1; //���� ����
			}
			else
			{
				printf("����Ǿ����ϴ�! \n");
				break;
			}

		}
		else //�̹� ������ �¼��̸�
		{
			printf("�̹� ����� �ڸ��Դϴ�! \n");
			continue; //�ٽ� ���ǽ����� ���ư� ���
		}
	}

	return 0; //�� ���Ϲ��� �ȸ����� ���� ����
}

CUSINFO *getLastNode(CUSINFO *linked)
{
	CUSINFO *last = linked;

	if (linked == NULL)
		return NULL;

#ifdef DEBUG
	printf("debug >> linked %s \n", linked->id);
#endif
	while (1) //���� ��尡 NULL�̸� ��� ��ȯ�� ���̴�.
	{
#ifdef DEBUG
		printf("debug >> last %s \n", last->id);
#endif
		if (last->next == NULL) //���� ��尡 ������
		{
#ifdef DEBUG
			printf("debug >> if last->next == NULL then %s \n", last->id);
#endif
			return last; //���� ��带 ��ȯ�Ѵ�. (��������)
		}
		last = last->next;
	}
}

void removeNode(CUSINFO *member, CUSINFO **linked)
{
	CUSINFO *pre = member->pre;
	CUSINFO *next = member->next;

	if (pre == NULL && next == NULL) //�� ���� ��常 �ִ� ���
	{
		*linked = NULL; //��������Ϳ� ������ ����
	}
	else if (pre == NULL) //�� �� ����� ���
	{
		next->pre = NULL; //������ ����� ���� ���� ������ ���´�.
		*linked = next; //�����ϸ� ������尡 �� �տ� ��尡 �ȴ�.
	}
	else if (next == NULL) //�� �� ����� ���
	{
		pre->next = NULL; //������ ����� �� ���� ������ ���´�.
	}
	else //�߰� ����� ���
	{
		pre->next = next; //������ ����� �� ���� ������ ����� �� ���� �����Ѵ�.
		next->pre = pre; //������ ����� �� ���� ������ ����� �� ���� �����Ѵ�.
	}

#ifdef DEBUG
	printf("debug >> %s memory free!! \n", member->id);
#endif
	FREE(member);
}