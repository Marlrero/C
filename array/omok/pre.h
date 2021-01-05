//전처리
#define ROW 5 //행 define문 정의
#define COLUMN 5 //열 define문 정의
#define CHECK 5

//typedef선언
typedef char BOARD[][COLUMN]; //보드 배열을 typedef로 선언
typedef struct 
{
	int x;
	int y;
} POINT; //좌표 구조체를 typedef로 선언

//함수 원형
//+ board.c
void init_board(BOARD arr); //초기화 함수
int get_player_move(int player, BOARD arr); //유저 선택 함수
void disp_board(BOARD arr); //출력 함수
//+ check.c
int check_win(BOARD arr, char str); //승패 검사 함수