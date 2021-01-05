#include "preheader.h"

int printMenus(void) //�޴��� ����ϴ� �Լ��� ����
{
	int select; //�޴���ȣ�� �����ϱ� ���� ���� ����

	printf("\n==================== MENU ======================\n");
	printf("1. �����ϱ�\n");
	printf("2. ����ϱ�\n");
	printf("3. �����ϱ�\n");
	printf("4. �¼�����\n");
	printf("5. ȸ������\n");
	printf("6. �����ϱ�\n");
	printf("�޴��� �����Ͻÿ�: ");
	scanf("%d", &select); //�޴� ����

	if (select < 1 || select > 4) //�޴��� �߸������ϸ�
		return 0;

	return select;
}

void printSeats(int arr[][COLUMN]) //�¼��� ������¸� ����ϴ� �Լ��� ����
{
	int row, column; //�迭�� ��� ���� ���� ���� ���� ����

	printf("\n==================== �¼� ======================\n");
	printf("       1�� 2�� 3�� 4�� 5�� 6�� 7�� 8�� 9�� 10�� \n");
	printf("================================================\n");

	for (row = 0; row < ROW; row++)
	{
		printf("%3d��", row + 1);
		for (column = 0; column < COLUMN; column++)
			printf(" %3d", arr[row][column]);
		printf("\n");
	}

	printf("================================================\n");
}

int findMenuCusto(void) //���� ã�� �� �޴��� ����ϴ� �Լ��� ����
{
	int input; //���� ã�� �� �Է��ϴ� ���� ������ ���� ����

	printf("\n================== ȸ��ã�� ====================\n");
	printf("1. ȸ����ȣ�� ã�� \n");
	printf("2. �̸����� ã�� \n");
	printf("3. �ڵ�����ȣ�� ã�� \n");
	printf("�޴��� �����Ͻÿ�: ");
	scanf("%d", &input); //�޴� ����

	if (input < 1 || input > 3) //�޴��� �߸������ϸ�
		return 0; //����������

	return input; //���������ϸ� �޴������� ���� ��ȯ
}
