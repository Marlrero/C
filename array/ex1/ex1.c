#include <stdio.h>

int main(void)
{
	int i; //배열의 인덱스를 세기 위한 변수 선언
	int grade[5]; //int형 1차원 배열 선언(크기 5)

	printf("5명의 정수를 입력하시오\n");

	for (i=0; i<5; i++) //배열의 크기까지만 반복함
		scanf("%d", &grade[i]); //배열 원소 입력

	for (i=0; i<5; i++) //배열의 크기까지만 반복함
		printf("grade[%d] = %d \n", i, grade[i]); //출력

	return 0;
}