#include "preheader.h"

int find_customer_main(void) //���� ã�� �Լ��� ����
{
	int select; //�޴��Լ��� ȣ���Ͽ� ��ȯ���� �����ϴ� ���� ����
	int FuncRetu; //������ �Լ��� �����ų �� �ִ� ���� �����ϴ� ���� ����

	if (select = findMenuCusto()) //�����������ϸ�
		return 1; //���������ᰪ ��ȯ
	
	//�� if���� ������� ������
	if (select == 1) //1���� �����ϸ�
	{
		while (1) // ���ѷ���
		{
			if (FuncRetu = find_customer_num()) //ȸ����ȣ�� ã�� �Լ� ȣ���Ͽ� �����������ϸ�
				continue; //�ٽ� �ݺ�
			else if (FuncRetu == -1) //�����Ű�� �� -1�� �Է��ϸ�
				break; //������ ��������
			else //���������ϸ�
				break; //������ ��������
		}
	}
	else if (select == 2) //2���� �����ϸ�
	{
		while (1) //���ѷ���
		{
			if (FuncRetu = find_customer_name()) //ȸ���̸����� ã�� �Լ� ȣ���Ͽ� �����������ϸ�
				continue; //�ٽ� �ݺ�
			else if (FuncRetu == -1) //�����Ű�� �� -1�� �Է��ϸ�
				break; //������ ��������
			else //���������ϸ�
				break; //������ ��������
		}
	}
	else if (select == 3) //3���� �����ϸ�
	{
		while (1) //���ѷ���
		{
			if (FuncRetu = find_customer_hand()) //ȸ���޴�����ȣ�� ã�� �Լ� ȣ���Ͽ� �����������ϸ�
				continue; //�ٽ� �ݺ�
			else if (FuncRetu == -1) //�����Ű�� �� -1�� �Է��ϸ�
				break; //������ ��������
			else //���������ϸ�
				break; //������ ��������
		}
	}
	else //�߸��� ���� �Է��ϸ�
	{
		printf("�޴��� �߸������Ͽ����ϴ�! \n");
		return 1; //����������
	}

	//�� else���� ������� ������
	return 0; //��������
}

int find_customer_num(void) //����ȣ�� ã�� �Լ��� ����
{
	int input, index; //����ȣ�� �����ϴ� ����, �迭�� �ε����� ���� ���� ���� ����

	printf("ȸ����ȣ �Է�: ");
	scanf("%d", &input); //ȸ����ȣ �Է�

	//����ü �迭�� �˻�
	for (index = 0; index < PEOPLE; index++)
	{
		if (cusarr[index].num == input) //������ ���� ȸ����ȣ�� ã����
			return index
	}
}

int find_customer_name(void) //���̸��� ã�� �Լ��� ����
{

}

int find_customer_hand(void)//�� �ڵ�����ȣ�� ã�� �Լ��� ����
{

}