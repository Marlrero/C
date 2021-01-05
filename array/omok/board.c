#include <stdio.h>
#include "pre.h"

void init_board(BOARD arr) //�ʱ�ȭ �Լ� ����
{
	int row, column; //��� ���� ���� ���� ���� ����

	for (row = 0; row < ROW; row++) //�� �ݺ�
		for (column = 0; column < COLUMN; column++) //�� �ݺ�
			arr[row][column] = ' '; //�ʱ�ȭ
}

int get_player_move(int player, BOARD arr) //���� ���� �Լ� ����
{
	POINT input; //����ü ���� ����

	while (1) //���ѷ���
	{
		printf("(x, y)��ǥ�� �Է�(����: -1, -1): ");
		scanf("%d %d", &input.x, &input.y);

		if (input.x - 1 == -1 && input.y - 1 == -1) //���� �����̸�
			return 1; //���ѷ����� ���߰� ������ ����

		if ((input.x < 1 || input.x > ROW) || (input.y < 1 || input.y > COLUMN)) //�ε��� ������ ����� �Է��ϸ�
		{
			printf("�߸��� ��ġ�Դϴ�. �ٽ� �Է��ϼ���! \n");
			continue; //���ǽ����� ���ư�
		}

		if (arr[input.x - 1][input.y - 1] == ' ') //�Է��� ��ǥ�� ����̸�
			break; //���ѷ����� ��������
		else //�Է��� ��ǥ�� �̹� �Էµ� ���̸�
			printf("�̹� �Էµ� ��ġ�Դϴ�. �ٽ� �Է��ϼ���! \n"); //���ǽ����� ���ư�
	}
	//�� 2��° if������ break�Ǹ�
	if (player == 0) //����ڰ� 0�̸�
		arr[input.x - 1][input.y - 1] = 'X'; //X�� ä��
	else //����ڰ� 1�̸�
		arr[input.x - 1][input.y - 1] = 'O'; //O�� ä��

	return 0; //�� if~else���� ����Ǹ� ���� ����
}

void disp_board(BOARD arr) //��� �Լ� ����
{
	int row, column; //��� ���� ���� ���� ���� ����

	printf("  | 1 | 2 | 3 | 4 | 5 |\n");
	printf("   ---|---|---|---|---\n");
	for (row = 0; row < ROW; row++) //�� �ݺ�
	{
		printf(" %d|", row + 1);
		for (column = 0; column < COLUMN; column++) //�� �ݺ�
		{
			printf(" %c", arr[row][column]); //���
			printf(" |");
		}
		printf("\n  |---|---|---|---|---\n");
	}
}