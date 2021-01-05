#define SIZE 10

/* 
   좌석을 전역변수로 사용하면 인자로 배열을 전달할 필요는 없음
   void bookSeats(int answer);

   이 프로그램의 방식은 배열과 포인터를 이용함
*/

//print.c
int printMenus(void); //메뉴를 출력하는 함수의 원형
void printSeats(int arr[]); //좌석의 현재상태를 출력하는 함수의 원형
//reservation.c
int bookSeats(int arr[]); //좌석을 예약하는 함수의 원형
int cancleSeats(int arr[]); //좌석을 취소하는 함수의 원형
int changeSeats(int arr[]); //예약을 수정하는 함수의 정의
//freq.c
int freqSeats(int arr[]); //좌석의 수를 세는 함수의 원형