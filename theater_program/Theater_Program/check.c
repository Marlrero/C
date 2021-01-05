#include <stdio.h> //IO
#include "data.h"
#include "check.h"

int freqSeats(const int(*arr)[COLUMN]) //�¼��� ���� ���� �Լ� ����
{
	int freq = 0; //�¼��� ���� ���� ���� ����(�ʱ�ȭ 0)
	int row, column; //��� ���� ���� ���� ����

	for (row = 0; row < ROW; row++)
	{
		for (column = 0; column < COLUMN; column++)
		{
			if (*(*(arr + row) + column) == 0) //���¼��̸�
				freq++; //�¼��� ���� 1����
		}
	}

	return freq; //�¼��� ���� ��ȯ
}

int checkInput(const int row, const int column) //�¼� �Է� �˻� �Լ� ����
{
	if (row <= 0 || row > ROW) //���� ������ �ʰ��� ���� �Է��ϸ�
	{
		printf("�� ����! 1���� %d������ ���ڸ� �Է��ϼ���! \n", ROW);
		return 1; //������ ����
	}
	if (column <= 0 || column > COLUMN) //���� ������ �ʰ��� ���� �Է��ϸ�
	{
		printf("�� ����! 1���� %d������ ���ڸ� �Է��ϼ���! \n", COLUMN);
		return 1; //������ ����
	}

	return 0; //���� ����
}