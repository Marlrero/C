#include <stdio.h>
#include "pre.h"

int check_win(BOARD arr, char str) //���� �˻� �Լ� ����
{
	int row, column; //��, �� ���� ����
	int count = 0; //ī��Ʈ ���� ����

	//���ΰ˻�
	for (row = 0; row < ROW; row++) //������
	{
		count = 0;
		for (column = 0; column < COLUMN; column++) //������
		{
			if (arr[row][column] == str) //������ ���� str�� ������
				count++; //ī��Ʈ �ϳ� ����
		}
		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}

	//���ΰ˻�
	for (column = 0; column < COLUMN; column++) //������
	{
		count = 0;
		for (row = 0; row < ROW; row++) //������
		{
			if (arr[row][column] == str) //������ ���� str�� ������
				count++; //ī��Ʈ �ϳ� ����
		}

		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}
	//�밢���˻�1 (��)
	count = 0;
	for (row = 0, column = 0; row < ROW && column < COLUMN; row++, column++) //��� ���� ���� ����
	{
		if (arr[row][column] == str) //������ ���� str�� ������
			count++; //ī��Ʈ �ϳ� ����

		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}
	//�밢���˻�2 (��)
	count = 0;
	for (row = 0, column = COLUMN-1; row < ROW && column >= 0; row++, column--) //������, ������
	{
		if (arr[row][column] == str) //������ ���� str�� ������
			count++; //ī��Ʈ �ϳ� ����

		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}
	//���� ����� ������ ������
	return 0;
}

/* ���࿡ 5x5���� 3���� �Ѵٸ� � ������ �߰��ؾ� �ұ�? */