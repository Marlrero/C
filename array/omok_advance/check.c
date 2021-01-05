#include <stdio.h>
#include "pre.h"

int check_win(BOARD arr, char str) //���� �˻� �Լ� ����
{
	int rstart, cstart, rend, cend; //��� ���� �ʱ�ȭ�ϱ� ���� ���� ����
	int row, column; //��� ���� ���� ���� ���� ����
	int count = 0; //ī��Ʈ ���� ����

				   //���ΰ˻�
	for (row = 0; row < ROW - 1; row++) //������
	{
		count = 0;
		for (column = 0; column < COLUMN - 1; column++) //������
		{
			if (arr[row][column] == str && arr[row][column + 1] == str) //������ ���� str�� ������
				count++; //ī��Ʈ �ϳ� ����
		}
		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}

	//���ΰ˻�
	for (column = 0; column < COLUMN - 1; column++) //������
	{
		count = 0;
		for (row = 0; row < ROW - 1; row++) //������
		{
			if (arr[row][column] == str && arr[row + 1][column] == str) //������ ���� str�� ������
				count++; //ī��Ʈ �ϳ� ����
		}

		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}

	//�Ʒ��� '�밢���˻� �ʱ�ȭ'�� '�밢������ �˻� �Լ�'�� ��� ���� ���۰��� ������ �����մϴ�.
	//�밢���˻� �ʱ�ȭ (��)(��)
	for (rstart = 0, cend = COLUMN - 1; rstart < ROW - CHECK && cend > CHECK; rstart++, cend--)
		if (check1_diagonal(arr, str, rstart, ROW, 0, cend)) //�� �Լ��� ��ȯ�� ���� 1�̸�
			return 1; //���� ����

	//�밢���˻� �ʱ�ȭ (��)(��)
	for (cstart = 0, rend = ROW - 1; cstart < COLUMN - CHECK, rend > CHECK; cstart++, rend--)
		if (check1_diagonal(arr, str, 0, rend, cstart, COLUMN - 1)) //�� �Լ��� ��ȯ�� ���� 1�̸�
			return 1; //���� ����

	//�밢���˻� �ʱ�ȭ (��)(��)
	for (cstart = COLUMN - 1, rend = ROW - 1; cstart > CHECK, rend > CHECK; cstart--, rend--) //����, ������
		if (check2_diagonal(arr, str, 0, rend, cstart, 0)) //�� �Լ��� ��ȯ�� ���� 1�̸�
			return 1; //���� ����

	 //�밢���˻� �ʱ�ȭ (��)(��)
	for (rstart = 0, cend = 0; rstart < ROW - CHECK && cend < COLUMN - CHECK; rstart++, cend++)
		if (check2_diagonal(arr, str, rstart, ROW, COLUMN - 1, cend)) //�� �Լ��� ��ȯ�� ���� 1�̸�
			return 1; //���� ����

	//���� ������: ��� �ٿ� ������ �ι� �˻��ϰ� �� --> �ӵ� ����
	//���� ������: ���簢�� �迭������ ���� --> ���簢���� ��쿡�� �� �������...(�̰� ������ ����...)
	//���� ������: �������� ���Ⱑ �����ϴٰ� ������ --> �������� �� ���ѹ���� ������??

	//���� ����� ������ ������
	return 0;
}

//�Ʒ��� �Լ��� �ٹ������θ� �˻��ϴ� �Լ�, �׹������θ� �˻��ϴ� �Լ��� ���� ������
int check1_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend) //�밢������ �˻� �Լ�1 (��)
{
	int row, column, count = 0;

	for (row = rstart, column = cstart; row < rend && column < cend; row++, column++) //��� ���� ���� ����
	{
		if (row == ROW - 1 && column == COLUMN - 1) //�������� �˻��ϸ� �Ʒ� if���� +1�ε������� ���� �ʰ�
			return 0; //������ ����

		if (arr[row][column] == str && arr[row + 1][column + 1] == str) //������ ���� str�� ������
			count++; //ī��Ʈ �ϳ� ����

		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}

	//���� ����� ������ ������
	return 0; //������ ����
}

int check2_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend) //�밢������ �˻� �Լ�2 (��)
{
	int row, column, count = 0;

	for (row = rstart, column = cstart; row < rend && column > cend; row++, column--) //������, ������
	{
		if (row == ROW - 1 && column == 0) //�������� �˻��ϸ� �Ʒ� if���� +1�� -1�ε������� ���� �ʰ�
			return 0; //������ ����

		if (arr[row][column] == str && arr[row + 1][column - 1] == str) //������ ���� str�� ������
			count++; //ī��Ʈ �ϳ� ����

		if (count == CHECK) //�����̸�
			return 1; //���� ����
	}

	//���� ����� ������ ������
	return 0; //������ ����
}