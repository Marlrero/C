#include <stdio.h>
#include "proheader.h"

int printMenus(void) //�޴��� ����ϴ� �Լ��� ����
{
	int select; //�޴���ȣ�� �����ϱ� ���� ���� ����

	printf("\n============= MENU =============\n");
	printf("1. �����ϱ�\n");
	printf("2. ����ϱ�\n");
	printf("3. �����ϱ�\n");
	printf("4. �����ϱ�\n");
	printf("�޴��� �����Ͻÿ�: ");
	scanf("%d", &select); //�޴� ����

	if (select < 1 || select > 4) //�޴��� �߸������ϸ�
		return 0;

	return select;
}

void printSeats(int arr[]) //�¼��� ������¸� ����ϴ� �Լ��� ����
{
	int index; //�迭�� �ε����� ���� ���� ���� ����

	printf("\n============= �¼� =============\n");
	printf("  1  2  3  4  5  6  7  8  9  10 \n");
	printf("================================\n");

	for (index = 0; index < SIZE; index++)
		printf("  %d", arr[index]);

	printf("\n");
	printf("================================\n");
}