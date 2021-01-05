#include <stdio.h>
#include "proheader.h"

int bookSeats(int arr[][COLUMN]) //�¼��� �����ϴ� �Լ��� ����
{
	int row, column; //��� ���� �����ϱ� ���� ���� ����
	int loop, person; //�ݺ��� ���� ���� ����, ��� ���� ������ ���� ����
	int rest; //���� �ڸ��� �����ϴ� ���� ����
	
	printf("\n==================== ���� ======================\n");
	printf("�� ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &person);
	
	if (person < 1 || person > ROW * COLUMN) //�¼� ���� �ʰ��ϰų� ���� �Է��ϸ�
	{
		printf("���� �ο��� �߸��Է��Ͽ����ϴ�!\n");
		return 1; //���� ����
	}

	rest = freqSeats(arr); //�¼��� ���� ���� �Լ��� ȣ��
	if (rest < person) //�¼��� ���� �Է��� ������ ������
	{
		printf("���� �¼��� ���� %d���Դϴ�. ������ �� �����ϴ�! \n", rest);
		return 1; //���� ����
	}


	for (loop = 0; loop < person; loop++)
	{
		printf("�մ�%d - ���° �¼��� �����Ͻðڽ��ϱ�(~��~��)? : ", loop + 1);
		scanf("%d %d", &row, &column);

		if (checkInput(row, column))
			return 1; //���� ����

		if (arr[row-1][column-1] == 0) //������� ���� �¼��̸�
		{
			arr[row-1][column-1] = 1; //�����Ѵ�.
			printf("����Ǿ����ϴ�! \n");
		}
		else //�̹� ������ �¼��̸�
		{
			printf("�̹� ����� �ڸ��Դϴ�! %d�� ����Ǿ����ϴ�! \n", loop);
			return 1; //���� ����
		}
	}

	printSeats(arr); //�¼��� ������
	return 0; //��������
}

int cancleSeats(int arr[][COLUMN]) //�¼��� ����ϴ� �Լ��� ����
{
	int row, column; //��� ���� �����ϱ� ���� ���� ����

	while (1)
	{
		printf("\n==================== ��� ======================\n");
		printf("���° �¼��� ����Ͻðڽ��ϱ�(~��~��)? : ");
		scanf("%d %d", &row, &column);

		if (checkInput(row, column))
			return 1; //��� ����

		if (arr[row-1][column-1] == 1) //����� �¼��̸��̸�
		{
			arr[row-1][column-1] = 0; //����Ѵ�.
			printf("��ҵǾ����ϴ�! \n");
			break;
		}
		else //����� �ʿ䰡 ���� �¼��̸�
		{
			printf("����� �� ���� �ڸ��Դϴ�! \n");
			return 1; //��� ����
		}
	}

	printSeats(arr); //�¼��� ������
	return 0; //��������
}

int changeSeats(int arr[][COLUMN]) //������ �����ϴ� �Լ��� ����
{
	int row, column; //��� ���� �����ϱ� ���� ���� ����

	printf("\n==================== ���� ======================\n");
	if (cancleSeats(arr)) //����ϴ� �Լ� ȣ���Ͽ� �߸� ����Ǹ�
		return 1; //���� ����

	while (1) //���ѷ���
	{
		 //����ϴ� �Լ��� ���� ����Ǿ�����
		printf("������ �¼��� �Է��ϼ���(~�� ~��): ");
		scanf("%d %d", &row, &column);

		if (checkInput(row, column))
			return 1; //���� ����

		if (arr[row-1][column-1] == 0) //������� ���� �¼��̸�
		{
			arr[row-1][column-1] = 1; //�����Ѵ�.
			printf("����Ǿ����ϴ�! \n");
			break;
		}
		else //�̹� ������ �¼��̸�
		{
			printf("�̹� ����� �ڸ��Դϴ�! \n");
			continue; //�ٽ� ���ǽ����� ���ư� ���
		}
	}

	return 0; //�� ���Ϲ��� �ȸ����� ���� ����
}