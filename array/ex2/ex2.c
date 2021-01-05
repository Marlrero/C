/*
	1차원 배열을 세번 씀
	2차원 배열 버전: int grade[STUDENTS][3]으로 하여 열끼리 계산해서 과목의 합을 구하고, 모든 항의 합으로 모든 과목점수의 합을 구할 수 있다.
	1차원 배열을 하나만 쓰는 버전: 1) 중첩반복으로 바깥쪽 반복3번, 안쪽 반복 5번하면 됨(중첩반복에 쓰일 루프제어변수 2개 선언)
								   2) 함수의 인자를 배열포인터로, 함수 호출 ex> void processGrade(int arr[](or int *arr), int size) <- 호출 processGrade(arr, STUDENTS) 
*/

#include <stdio.h>
#define STUDENTS 5
int main(void)
{
	int korean[STUDENTS], english[STUDENTS], math[STUDENTS]; //성적을 저장할 1차원 int형 배열 선언
	
	double KoreanSum, EnglishSum, MathSum; //합을 저장할 double형 변수 선언
	int i; //배열의 인덱스를 세기 위한 변수 선언

	KoreanSum = EnglishSum = MathSum = 0.0; //초기화

	for (i=0; i<STUDENTS; i++) //배열의 크기만큼 반복
	{
		printf("학생%d의 국어성적: ", i+1);
		scanf("%d", &korean[i]); //국어성적 입력
	}

	printf("==========================\n");
	for (i=0; i<STUDENTS; i++) //배열의 크기만큼 반복
	{
		printf("학생%d의 수학성적: ", i+1);
		scanf("%d", &math[i]); //수학성적 입력
	}

	printf("==========================\n");
	for (i=0; i<STUDENTS; i++) //배열의 크기만큼 반복
	{
		printf("학생%d의 영어성적: ", i+1);
		scanf("%d", &english[i]); //영어성적 입력
	}

	for (i=0; i<5; i++) //배열의 크기만큼 반복
	{
		KoreanSum = KoreanSum + (double)korean[i]; //국어 성적의 합을 반복해서 저장
		MathSum = MathSum + (double)math[i]; //수학 성적의 합을 반복해서 저장
		EnglishSum = EnglishSum + (double)english[i]; //영어 성적의 합을 반복해서 저장
	}

	printf("==========================\n");
	printf("국어 성적 평균=%lf \n", KoreanSum / (double)STUDENTS);
	printf("수학 성적 평균=%lf \n", MathSum / (double)STUDENTS);
	printf("영어 성적 평균=%lf \n", EnglishSum / (double)STUDENTS);
	printf("전체 성적 합계=%lf \n", KoreanSum + MathSum + EnglishSum);
	printf("총 성적 평균=%lf \n", (KoreanSum + MathSum + EnglishSum) / ((double)STUDENTS * 3.0)); //평균 출력

	return 0;
}