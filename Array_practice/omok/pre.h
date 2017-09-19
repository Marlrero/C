//��ó��
#define ROW 10 //�� define�� ����
#define COLUMN 10 //�� define�� ����
#define CHECK 4 //���Ἲ�� ������(10*10�̹Ƿ� ���� ���Ἲ(4�� ����)�� ������

//typedef����
typedef char BOARD[][COLUMN]; //���� �迭�� typedef�� ����
typedef struct {
	int x;
	int y;
} POINT; //��ǥ ����ü�� typedef�� ����

//�Լ� ����
//+ board.c
void init_board(BOARD arr); //�ʱ�ȭ �Լ�
int get_player_move(int player, BOARD arr, char user); //���� ���� �Լ�
void disp_board(BOARD arr); //��� �Լ�

//+ check.c
int check_win(BOARD arr, char str); //���� �˻� �Լ�
int check1_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend); //�밢������ �˻� �Լ�1 (��)
int check2_diagonal(BOARD arr, char str, int rstart, int rend, int cstart, int cend); //�밢������ �˻� �Լ�2 (��)