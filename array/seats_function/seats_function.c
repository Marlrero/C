#include <stdio.h>
#define SIZE 10

/* 
   �¼��� ���������� ����ϸ� ���ڷ� �迭�� ������ �ʿ�� ����
   void printSeats(void);
   void bookSeats(int answer);
*/

//�Ʒ��� ����� �迭�� �����͸� �̿��� ���
int printMenus(void); //�޴��� ����ϴ� �Լ��� ����
void printSeats(int arr[]); //�¼��� ������¸� ����ϴ� �Լ��� ����
int bookSeats(int arr[]); //�¼��� �����ϴ� �Լ��� ����
int cancleSeats(int arr[]); //�¼��� ����ϴ� �Լ��� ����

int main(void)
{
	int menu; //�޴��� ������ ����
	int seats[SIZE] = {0}; //���� �¼� ���´� 0
	
	while (1) //���ѷ���
	{	
		menu = printMenus(); //�޴� ���

		if (menu == 1) //�����ϱ�
		{
			printSeats(seats);
			if (bookSeats(seats)) //�Լ��� �߸� ����Ǹ�
				continue; //�ٽ� ���� ����
			printSeats(seats); //������ ���������� �Ǿ����� ���
		}
		else if (menu == 2) //����ϱ�
		{
			printSeats(seats);
			if (cancleSeats(seats)) //�Լ��� �߸� ����Ǹ�
				continue; //�ٽ� ���� ����
			printSeats(seats); //��Ұ� ���������� �Ǿ����� ���
		}
		else if (menu == 3) //�����ϱ�
		{
			printSeats(seats); //���� �� �¼� ��Ȳ ���
			printf("���α׷��� ����˴ϴ�!\n");
			return 0; //���α׷� ����
		}
		else //�߸� �޴��� �Է��� ���
		{
			printf("�޴� ������ �ٽ��ϼ���!\n");
			continue;
		}
	}

	return 0;
}

int printMenus(void) //�޴��� ����ϴ� �Լ��� ����
{
	int select; //�޴���ȣ�� �����ϱ� ���� ���� ����

	printf("============== MENU ============\n");
	printf("1. �����ϱ�\n");
	printf("2. ����ϱ�\n");
	printf("3. �����ϱ�\n");
	printf("�޴��� �����Ͻÿ�: ");
	scanf("%d", &select); //�޴� ����
	printf("================================\n");

	if (select < 1 || select > 3) //�޴��� �߸������ϸ�
		return 0;

	return select;
}

void printSeats(int arr[]) //�¼��� ������¸� ����ϴ� �Լ��� ����
{
	int index; //�迭�� �ε����� ���� ���� ���� ����

	printf("============= �¼� =============\n");
	printf("  1  2  3  4  5  6  7  8  9  10 \n");
	printf("================================\n");

	for (index = 0; index < SIZE; index++)
		printf("  %d", arr[index]);

	printf("\n");
	printf("================================\n");
}

int bookSeats(int arr[]) //�¼��� �����ϴ� �Լ��� ����
{
	int answer; //�¼���ȣ�� �����ϴ� ���� ����
	int loop, person; //�ݺ��� ���� ���� ����, ��� ���� ������ ���� ����
				
	printf("�� ���� �����Ͻðڽ��ϱ�?: ");
	scanf("%d", &person);
	
	if (person < 1 || person > SIZE) //�¼� ���� �ʰ��ϰų� ���� �Է��ϸ�
	{
		printf("���� �ο��� �߸��Է��Ͽ����ϴ�!\n");
		return 1; //���� ����
	}

	for (loop = 0; loop < person; loop++)
	{
		printf("�մ�%d - ���° �¼��� �����Ͻðڽ��ϱ�? : ", loop + 1);
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //���� ������ �ʰ��� ���� �Է��ϸ�
		{
			printf("1���� 10������ ���ڸ� �Է��ϼ���! \n");
			continue;
		}

		if (arr[answer-1] == 0) //������� ���� �¼��̸�
		{
			arr[answer-1] = 1; //�����Ѵ�.
			printf("����Ǿ����ϴ�! \n");
		}
		else //�̹� ������ �¼��̸�
		{
			printf("�̹� ����� �ڸ��Դϴ�! \n");
			return 1; //���� ����
		}
	}

	return 0; //��������
}

int cancleSeats(int arr[]) //�¼��� ����ϴ� �Լ��� ���� --> ����Լ��� ���ѷ����� ���� �ʿ䰡 ������??
{
	int answer; //�¼���ȣ�� �����ϴ� ���� ����

	while (1) //���ѷ���
	{
		printf("���° �¼��� ����Ͻðڽ��ϱ�? : ");
		scanf("%d", &answer);

		if (answer <= 0 || answer > SIZE) //���� ������ �ʰ��� ���� �Է��ϸ�
		{
			printf("1���� 10������ ���ڸ� �Է��ϼ���! \n");
			continue;
		}

		if (arr[answer-1] == 1) //����� �¼��̸��̸�
		{
			arr[answer-1] = 0; //����Ѵ�.
			printf("��ҵǾ����ϴ�! \n");
			break; //��Ұ� �Ϸ�Ǹ� ���ѷ����� ���
		}
		else //����� �ʿ䰡 ���� �¼��̸�
		{
			printf("����� �� ���� �ڸ��Դϴ�! \n");
			return 1; //��� ����
		}
	}
	return 0; //��������
}