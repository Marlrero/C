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
	char *buffer1 = NULL, *buffer2 = NULL; //���ڿ� ���� ����
	BIRTH *buffer3 = NULL; //������� ���� ���� ����
	CUSINFO *check = NULL; //ȸ��ã�⿡�� ���� ���� ����
	CUSINFO *member = (CUSINFO *)malloc(sizeof(CUSINFO)); //��� ����
	CUSINFO *last = getLastNode(*linked); //�� �ڿ� �ִ� ����� ������

	printf("=====================ȸ������====================\n");;
	buffer1 = inputString("�̸�", NAME_LENGTH);
	strcpy_s(member->name, NAME_LENGTH, buffer1); //����
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer1);
#endif
	FREE(buffer1); //���� ����

	while (1) //���ѷ���
	{
		buffer1 = inputString("���̵�", ID_LENGTH);
		check = searchMembership(1, buffer1, NULL, *linked);
		if (check == NULL) //���̵� �ߺ��˻� �Լ� ����
			printf("�̹� ������� ���̵��Դϴ�! \n");
		else //�ߺ��˻翡�� �ߺ����� ������
			break; //���ѷ��� ��������
	}
	strcpy_s(member->id, ID_LENGTH, buffer1); //����
	FREE(buffer1); //���� ����
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer1);
#endif

	while (1) //���ѷ���
	{
		buffer1 = inputString("��й�ȣ", PWD_LENGTH);
		buffer2 = inputString("��й�ȣ Ȯ��", PWD_LENGTH);
		if ( strcmp(buffer1, buffer2) == 0 ) //��й�ȣ�� �� ���� ��� ������
		{
			strcpy_s(member->password, PWD_LENGTH, buffer1); //����
			break; //���ѷ��� ��������
		}
		else
			printf("��й�ȣ�� ��й�ȣ Ȯ���� ���� �ʽ��ϴ�. �ٽ� �Է����ּ���. \n");
	}
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer1);
	printf("debug >> buffer free : %p \n", buffer2);
#endif
	FREE(buffer1); //���� ����
	FREE(buffer2); //���� ����

	buffer3 = inputBirth(); //�Լ��� ȣ���Ͽ� ��������� �Է��Ѵ�.
	member->birth.year = buffer3->year;
	member->birth.month = buffer3->month;
	member->birth.date = buffer3->date; //����
#ifdef DEBUG
	printf("debug >> buffer free : %p \n", buffer3);
#endif
	FREE(buffer3); //���� ����

	member->seat_count = 0;
	member->infor_check[0].row = -1;
	member->infor_check[0].column = -1;
	member->infor_check[1].row = -1;
	member->infor_check[1].column = -1; //�¼� �ʱ�ȭ

	member->next = NULL; //�� �ڿ� �����Ƿ� ������ ����
	if (*linked == NULL) //ó�� �����̸�
	{
		member->pre = NULL; //ó�� ������ ����� ���� ����.
		*linked = member; //��������Ϳ� ������ ��带 �����Ѵ�.
	}
	else //ó�� ������ �ƴϸ�
	{
		last->next = member; //�� �ڿ� �־��� ��� �������� ���� ������ ���� ����ȴ�.
		member->pre = last; //���� ������ ����� ���� ���� �� ���� �� �ڿ� �־��� ����̴�.
	}

	getchar();
#ifdef DEBUG
	printf("debug >> allocate member %p %s\n", member, member->id);
#endif
	printf("=================================================\n");
}

CUSINFO *loginMembership(CUSINFO *linked) //�α����ϴ� �Լ�
{
	char *inputid = NULL;
	char *inputpassword = NULL; //���̵�, �н����� ����
	CUSINFO *findmember = NULL; //ã�� ����� ����
	CUSINFO *last = getLastNode(linked); //�� �ڿ� �ִ� ����� ������

	printf("\n=====================�α���======================\n");
	inputid = inputString("���̵�", ID_LENGTH);
	inputpassword = inputString("��й�ȣ", PWD_LENGTH);

	if ( (findmember = searchMembership(2, inputid, inputpassword, linked)) == NULL ) //ȸ�������� ������
	{
		printf("ȸ�������� �����ϴ�!\n");
		return NULL; //������ NULL�� ��ȯ!
	}

#ifdef DEBUG
	printf("debug >> buffer inputid inputpwd free : %s %s \n", inputid, inputpassword);
#endif
	FREE(inputid);
	FREE(inputpassword); //�޸� ����

	printf("=================================================\n");
	return findmember; //ã���� ã�� ����ü�� �����ϰ� �ִ� �ּҰ� ��ȯ!
}

void deleteMembership(CUSINFO *member, int (*arr)[COLUMN], CUSINFO **linked)
{
	int ch;
	int drow1 = -1, dcol1 = -1, drow2 = -1, dcol2 = -1;

	printMemberSeatList(member); //���� �¼��� �����ش�.
	if (member->seat_count > 0) //Ż���� ȸ���� �����¼��� �ִٸ�
	{
		printf("������ �¼��� ��� ��ҵ˴ϴ�.");
		if (member->infor_check[0].row != -1 && member->infor_check[0].column != -1) //ù��° �����¼��� �ִٸ�
		{
			drow1 = member->infor_check[0].row;
			dcol1 = member->infor_check[0].column;
		}

		if (member->infor_check[1].row != -1 && member->infor_check[1].column != -1) //�ι��� �����¼��� �ִٸ�
		{
			drow2 = member->infor_check[1].row;
			dcol2 = member->infor_check[1].column;
		}
	}

	while (1) //���ѷ���
	{
		getchar(); //�Է¹��� ���
		printf("Ż���Ͻðڽ��ϱ�?(y, n) ");
		ch = getchar();
		if (ch == 'y') //yes�̸�
		{
			if (drow1 != -1 && dcol1 != -1)
				*(*(arr + drow1 - 1) + dcol1 - 1) = 0; //���
			if (drow2 != -1 && dcol2 != -1)
				*(*(arr + drow2 - 1) + dcol2 - 1) = 0; //���

			printSeats(arr);
			removeNode(member, linked);
			printf("Ż�� �Ϸ�Ǿ����ϴ�. \n");
			break; //����
		}
		else if (ch == 'n') //no�̸�
		{
			printf("Ż�� ����Ͽ����ϴ�. \n");
			break; //����
		}
		else
			printf("y�� n �� �ϳ��� �Է��ϼ���. \n");
	}
}

CUSINFO *searchMembership(const int mode, const char *keyid, const char *keypwd, CUSINFO *linked) //ȸ���� ã�� �Լ�
{
	CUSINFO *current = linked; //�о���� ������ �����ϱ� ���� �ӽ� ����

	if (mode == 1 && linked == NULL) //ó�� ������ �����!
		return (CUSINFO *)1; //����

	if (linked == NULL) //ȸ��DB�� ������ ������
	{
		printf("ȸ������DB�� �����Ͱ� �������� �ʽ��ϴ�. \n");
		return NULL; //����!
	}

	while (current != NULL)
	{
		if (mode == 1) //���̵� �˻� (�ߺ��˻�)
		{
			if ( strcmp(current->id, keyid) == 0 ) //���̵� ã����
				return NULL; //�ߺ������Ƿ� ����! (��������)
		}
		else //���̵�� ��й�ȣ �˻� (�α���)
		{
			if ( (strcmp(current->id, keyid) == 0) && (strcmp(current->password, keypwd) == 0) ) //���̵�� ��й�ȣ�� ��� ã����
				return current; //���� ��� ��ȯ (��������)
		}
		
		current = current->next;
	}

	if (mode == 1) //���̵� �ߺ��˻�� ã�� ���� ��쿡��
		return (CUSINFO *)1; //����!
	else //�α��ν� ã�� ���� ��쿡��
		return NULL; //����!
}

int addCustomSeats(CUSINFO *member, const int row, const int column) //ȸ���� �¼��� �˻��Ͽ� ȸ�������� �߰�
{
	if (member->infor_check[0].row == -1 || member->infor_check[0].column == -1) //�ϳ��� �¼��� �̹� -1�̸� �����̹Ƿ�
	{
		member->infor_check[0].row = row;
		member->infor_check[0].column = column; //�α����� ȸ���� ������ ����
		(member->seat_count)++; //������ �¼��� �� ����
	}
	else if (member->infor_check[1].row == -1 || member->infor_check[1].column == -1) //�ϳ��� �¼��� �̹� -1�̸� �����̹Ƿ�
	{
		member->infor_check[1].row = row;
		member->infor_check[1].column = column; //�α����� ȸ���� ������ ����
		(member->seat_count)++; //������ �¼��� �� ����
	}
	else
		return 1; //����

	return 0; //����
}

int deleteCustomSeats(CUSINFO *member, const int row, const int column) //ȸ���� �¼��� �˻��Ͽ� ȸ�������� ����
{
	int count = 0;

	if (member->infor_check[0].row == row && member->infor_check[0].column == column) //ù��° �¼��� ã����
	{
		member->infor_check[0].row = -1;
		member->infor_check[0].column = -1; //���
		(member->seat_count)--; //������ �¼��� �� ����
		count++;
	}
	
	if (member->infor_check[1].row == row && member->infor_check[1].column == column) //�ι�° �¼��� ã����
	{
		member->infor_check[1].row = -1;
		member->infor_check[1].column = -1; //���
		(member->seat_count)--; //������ �¼��� �� ����
		count++;
	}

	if (count == 2) //�� �¼��� ������ ������ �� ���� ������ ������ ����
	{
#ifdef DEBUG
		printf("debug >> ������ \n");
#endif
		return 1; //���� DEBUG
	}
	else if (count == 1) //�� ���� �¼��� ���������
		return 0; //���� (��Ұ� �� ����)
	else
		return -1; //���� (��Ұ� ���� �ʾ�����, �������� ���� �¼��� ����Ϸ� ����)
}