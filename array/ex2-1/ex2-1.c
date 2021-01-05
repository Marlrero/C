#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3

int main(void)
{
	int	grade[STUDENTS]; //성적을 저장할 1차원 int형 배열 선언
	char *string; //과목 문자열을 저장할 포인터 변수 선언
	double sum = 0.0, outsum = 0.0; //합을 저장할 double형 변수 선언
	int out, index; //배열의 인덱스를 세기 위한 변수 선언

	for (out=0; out<SUBJECTS; out++)
	{
		if (out == 0) string="국어";
		else if (out == 1) string="수학";
		else string="영어"; //외부 반복하면서 과목 문자열이 바뀐다.

		for (index=0; index<STUDENTS; index++)
		{
			printf("학생 %d의 %s성적 입력: ", index+1, string);
			scanf("%d", &grade[index]); //성적을 입력한다.
		}

		sum = 0.0; //합 초기화
		for (index=0; index<STUDENTS; index++)
			sum = sum + (double)grade[index]; //합을 계산한다.

		printf("%s 성적 평균=%lf \n", string, sum / (double)STUDENTS);
		outsum = outsum + sum;
	}

	printf("총점 평균=%lf \n", outsum / ((double)STUDENTS*3.0));

	return 0;
}