#include <stdio.h>

int main(void)
{
	int i; //�迭�� �ε����� ���� ���� ���� ����
	int grade[5]; //int�� 1���� �迭 ����(ũ�� 5)

	printf("5���� ������ �Է��Ͻÿ�\n");

	for (i=0; i<5; i++) //�迭�� ũ������� �ݺ���
		scanf("%d", &grade[i]); //�迭 ���� �Է�

	for (i=0; i<5; i++) //�迭�� ũ������� �ݺ���
		printf("grade[%d] = %d \n", i, grade[i]); //���

	return 0;
}