#include <stdio.h>
#include "proheader.h"

int freqSeats(int arr[]) //�¼��� ���� ���� �Լ� ����
{
	int freq = 0; //�¼��� ���� ���� ���� ����(�ʱ�ȭ 0)
	int index; //�ε����� ���� ���� ����

	for (index = 0; index < SIZE; index++)
	{
		if (arr[index] == 0) //���¼��̸�
			freq++; //�¼��� ���� 1����
	}

	return freq; //�¼��� ���� ��ȯ
}