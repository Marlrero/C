#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3

int main(void)
{
	int	grade[STUDENTS]; //������ ������ 1���� int�� �迭 ����
	char *string; //���� ���ڿ��� ������ ������ ���� ����
	double sum = 0.0, outsum = 0.0; //���� ������ double�� ���� ����
	int out, index; //�迭�� �ε����� ���� ���� ���� ����

	for (out=0; out<SUBJECTS; out++)
	{
		if (out == 0) string="����";
		else if (out == 1) string="����";
		else string="����"; //�ܺ� �ݺ��ϸ鼭 ���� ���ڿ��� �ٲ��.

		for (index=0; index<STUDENTS; index++)
		{
			printf("�л� %d�� %s���� �Է�: ", index+1, string);
			scanf("%d", &grade[index]); //������ �Է��Ѵ�.
		}

		sum = 0.0; //�� �ʱ�ȭ
		for (index=0; index<STUDENTS; index++)
			sum = sum + (double)grade[index]; //���� ����Ѵ�.

		printf("%s ���� ���=%lf \n", string, sum / (double)STUDENTS);
		outsum = outsum + sum;
	}

	printf("���� ���=%lf \n", outsum / ((double)STUDENTS*3.0));

	return 0;
}