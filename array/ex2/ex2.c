/*
	1���� �迭�� ���� ��
	2���� �迭 ����: int grade[STUDENTS][3]���� �Ͽ� ������ ����ؼ� ������ ���� ���ϰ�, ��� ���� ������ ��� ���������� ���� ���� �� �ִ�.
	1���� �迭�� �ϳ��� ���� ����: 1) ��ø�ݺ����� �ٱ��� �ݺ�3��, ���� �ݺ� 5���ϸ� ��(��ø�ݺ��� ���� ��������� 2�� ����)
								   2) �Լ��� ���ڸ� �迭�����ͷ�, �Լ� ȣ�� ex> void processGrade(int arr[](or int *arr), int size) <- ȣ�� processGrade(arr, STUDENTS) 
*/

#include <stdio.h>
#define STUDENTS 5
int main(void)
{
	int korean[STUDENTS], english[STUDENTS], math[STUDENTS]; //������ ������ 1���� int�� �迭 ����
	
	double KoreanSum, EnglishSum, MathSum; //���� ������ double�� ���� ����
	int i; //�迭�� �ε����� ���� ���� ���� ����

	KoreanSum = EnglishSum = MathSum = 0.0; //�ʱ�ȭ

	for (i=0; i<STUDENTS; i++) //�迭�� ũ�⸸ŭ �ݺ�
	{
		printf("�л�%d�� �����: ", i+1);
		scanf("%d", &korean[i]); //����� �Է�
	}

	printf("==========================\n");
	for (i=0; i<STUDENTS; i++) //�迭�� ũ�⸸ŭ �ݺ�
	{
		printf("�л�%d�� ���м���: ", i+1);
		scanf("%d", &math[i]); //���м��� �Է�
	}

	printf("==========================\n");
	for (i=0; i<STUDENTS; i++) //�迭�� ũ�⸸ŭ �ݺ�
	{
		printf("�л�%d�� �����: ", i+1);
		scanf("%d", &english[i]); //����� �Է�
	}

	for (i=0; i<5; i++) //�迭�� ũ�⸸ŭ �ݺ�
	{
		KoreanSum = KoreanSum + (double)korean[i]; //���� ������ ���� �ݺ��ؼ� ����
		MathSum = MathSum + (double)math[i]; //���� ������ ���� �ݺ��ؼ� ����
		EnglishSum = EnglishSum + (double)english[i]; //���� ������ ���� �ݺ��ؼ� ����
	}

	printf("==========================\n");
	printf("���� ���� ���=%lf \n", KoreanSum / (double)STUDENTS);
	printf("���� ���� ���=%lf \n", MathSum / (double)STUDENTS);
	printf("���� ���� ���=%lf \n", EnglishSum / (double)STUDENTS);
	printf("��ü ���� �հ�=%lf \n", KoreanSum + MathSum + EnglishSum);
	printf("�� ���� ���=%lf \n", (KoreanSum + MathSum + EnglishSum) / ((double)STUDENTS * 3.0)); //��� ���

	return 0;
}