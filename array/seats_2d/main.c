#include <stdio.h>
#include "proheader.h"

int main(void)
{
	int menu; //�޴��� ������ ����
	int seats[ROW][COLUMN] = {0}; //���� �¼� ���´� 0
	
	while (1) //���ѷ���
	{	
		menu = printMenus(); //�޴� ���

		if (menu == 1) //�����ϱ�
		{
			printSeats(seats);
			if (bookSeats(seats)) //�Լ��� �߸� ����Ǹ�
				continue; //�ٽ� ���� ����
		}
		else if (menu == 2) //����ϱ�
		{
			printSeats(seats);
			if (cancleSeats(seats)) //�Լ��� �߸� ����Ǹ�
				continue; //�ٽ� ���� ����
		}
		else if (menu == 3) //�����ϱ�
		{
			printSeats(seats);
			if (changeSeats(seats)) //�Լ��� �߸� ����Ǹ�
				continue; //�ٽ� ���� ����
		}
		else if (menu == 4) //�¼� ����
		{
			printSeats(seats);
			continue; //�ٽ� ���� ����
		}
		else if (menu == 5) //�����ϱ�
		{
			printf("���α׷��� ����˴ϴ�!\n");
			return 0; //���α׷� ����
		}
		else //�߸� �޴��� �Է��� ���
		{
			printf("�޴� ������ �ٽ��ϼ���!\n");
			continue; //�ٽ� ���
		}
	}

	return 0;
}