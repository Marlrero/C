//전처리
#define ROW 10 //행 define문 정의
#define COLUMN 10 //열 define문 정의
#define CHECK 4 //연결성을 봐야함(10*10이므로 오목에 연결성(4번 연결)을 봐야함

//typedef선언
typedef char BOARD[][COLUMN]; //보드 배열을 typedef로 선언
typedef struct {
	int x;
	int y;
} POINT; //좌표 구조체를 typedef로 선언

//함수 원형
//+ board.c
void init_board(BOARD arr); //초기화 함수
int get_player_move(int player, BOARD arr, char user); //유저 선택 함수
void disp_board(BOARD arr); //출력 함수

//+ check.c
int check_win(BOARD arr, char str); //승패 검사 함수
int check1_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend); //대각선방향 검사 함수1 (↘)
int check2_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend); //대각선방향 검사 함수2 (↙)