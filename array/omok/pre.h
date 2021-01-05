//��ó��
#define ROW 5 //�� define�� ����
#define COLUMN 5 //�� define�� ����
#define CHECK 5

//typedef����
typedef char BOARD[][COLUMN]; //���� �迭�� typedef�� ����
typedef struct 
{
	int x;
	int y;
} POINT; //��ǥ ����ü�� typedef�� ����

//�Լ� ����
//+ board.c
void init_board(BOARD arr); //�ʱ�ȭ �Լ�
int get_player_move(int player, BOARD arr); //���� ���� �Լ�
void disp_board(BOARD arr); //��� �Լ�
//+ check.c
int check_win(BOARD arr, char str); //���� �˻� �Լ�