/* �� ���α׷��� 10*10 ������ ���� ���� */
#include <stdio.h>
#include <stdlib.h>
#include "pre.h"

int main(void)
{
	char arr[ROW][COLUMN]; //���带 char�� �迭�� ����

	init_board(arr); //�ʱ�ȭ �Լ��� ȣ��

	while (1) //���ѷ���
	{
		disp_board(arr); //���带 ����ϴ� �Լ��� ȣ��
		if (get_player_move(0, arr, 'X')) //������ �����ϴ� �Լ��� ȣ���Ͽ� 1�� ��ȯ�ϸ�
			break; //���ѷ����� �����.
		if (check_win(arr, 'X')) //���� �˻� �Լ��� ȣ���Ͽ� 1�� ��ȯ�ϸ�
		{
			printf("�����X�� �̰���ϴ�! \n");
			break; //���ѷ����� �����.
		}

		disp_board(arr); //���带 ����ϴ� �Լ��� ��ȣ��
		if (get_player_move(1, arr, 'O')) //������ �����ϴ� �Լ��� ȣ���Ͽ� 1�� ��ȯ�ϸ�
			break; //���ѷ����� �����.
		if (check_win(arr, 'O')) //���� �˻� �Լ��� ȣ���Ͽ� 1�� ��ȯ�ϸ�
		{
			printf("�����O�� �̰���ϴ�! \n");
			break; //���ѷ����� �����.
		}
	}

	disp_board(arr); //��� ȣ��
	return 0;
}