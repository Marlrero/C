#include <stdio.h> //IO
#include <stdlib.h> //free() system()
//#include <windows.h> //Sleep()
#include "check.h"
#include "customer.h"
#include "data.h"
#include "file.h"
#include "io.h"
#include "reservation.h"

int main(void)
{
	int menu; //�޴��� ������ ����
	int seats[ROW][COLUMN] = { 0 }; //���� �¼� ���´� 0
	FILE *database = NULL, *seatdata = NULL; //�� ������ ������ ����, �¼��� ������ ����
	CUSINFO *linked = NULL; //
	CUSINFO *member = NULL; //���� �α����� ȸ���� ������ �����ϴ� ����ü ������

#ifdef DEBUG
	printf("debug >> struct sizeof -> %d \n", sizeof(CUSINFO));
#endif
	while (1) //���ѷ���
	{
		menu = printMenus(); //�޴� ���
		loadCustom(&linked, &database);
		loadSeats(seats, &seatdata);

		if (menu == 1) //�����ϱ�
		{
			if ((member = loginMembership(linked)) != NULL) //�α����� ����Ǹ�
			{
				printSeats(seats);

				if (bookSeats(seats, member)) //�Լ��� �߸� ����Ǹ�
					continue; //�ٽ� ���� ����
#ifdef DEBUG
				printf("debug >> seats %d %d %d %d %d \n", member->seat_count, member->infor_check[0].row, member->infor_check[0].column, member->infor_check[1].row, member->infor_check[1].column);
#endif
			}
			else
				printf("���̵�� ��й�ȣ�� ã�� �� �����ϴ�!\n");

		}
		else if (menu == 2) //����ϱ�
		{
			if ((member = loginMembership(linked)) != NULL) //�α����� ����Ǹ�
			{
				printSeats(seats);

				if (cancleSeats(seats, member)) //�Լ��� �߸� ����Ǹ�
					continue; //�ٽ� ���� ����
#ifdef DEBUG
				printf("debug >> seats %d %d %d %d %d \n", member->seat_count, member->infor_check[0].row, member->infor_check[0].column, member->infor_check[1].row, member->infor_check[1].column);
#endif
			}
			else
				printf("���̵�� ��й�ȣ�� ã�� �� �����ϴ�!\n");
		}
		else if (menu == 3) //�����ϱ�
		{
			if ((member = loginMembership(linked)) != NULL) //�α����� ����Ǹ�
			{
				printSeats(seats);

				if (changeSeats(seats, member)) //�Լ��� �߸� ����Ǹ�
					continue; //�ٽ� ���� ����
#ifdef DEBUG
				printf("debug >> seats %d %d %d %d %d \n", member->seat_count, member->infor_check[0].row, member->infor_check[0].column, member->infor_check[1].row, member->infor_check[1].column);
#endif
			}
			else
				printf("���̵�� ��й�ȣ�� ã�� �� �����ϴ�!\n");
		}
		else if (menu == 4) //�¼� ����
		{
			if ((member = loginMembership(linked)) != NULL) //�α����� ����Ǹ�
			{
				printSeats(seats);
				printMemberSeatList(member);
			}
			else
				printf("���̵�� ��й�ȣ�� ã�� �� �����ϴ�!\n");
		}
		else if (menu == 5) //ȸ������
			createMembership(&linked);
		else if (menu == 6) //ȸ��Ż��
		{
			if ((member = loginMembership(linked)) != NULL) //�α����� ����Ǹ�
			{
				deleteMembership(member, seats, &linked);
			}
			else
				printf("���̵�� ��й�ȣ�� ã�� �� �����ϴ�!\n");
		}
		else if (menu == 7) //ȸ�����
			printMemberList(linked);
		else if (menu == 8) //�¼�����
			printSeats(seats);
		else if (menu == 9) //�����ϱ�
		{
			printf("���α׷��� ����˴ϴ�!\n");
			break;
		}
		else //�߸� �޴��� �Է��� ���
		{
			printf("�޴� ������ �ٽ��ϼ���!\n");
			continue; //�ٽ� ���
		}

		member = NULL; //logout
		_sleep(1 * 1000); //1�� ������
		system("cls"); //ȭ�������
		saveSeats(seats, &seatdata);
		saveCustom(&linked, &database);
	}
	return 0; //���α׷� ����
}