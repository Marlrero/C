#define ROW 10
#define COLUMN 10

/* 
   �¼��� ���������� ����ϸ� ���ڷ� �迭�� ������ �ʿ�� ����
   void bookSeats(int answer);

   �� ���α׷��� ����� �迭�� �����͸� �̿���
*/

//print.c
int printMenus(void); //�޴��� ����ϴ� �Լ��� ����
void printSeats(int arr[][COLUMN]); //�¼��� ������¸� ����ϴ� �Լ��� ����
//reservation.c
int bookSeats(int arr[][COLUMN]); //�¼��� �����ϴ� �Լ��� ����
int cancleSeats(int arr[][COLUMN]); //�¼��� ����ϴ� �Լ��� ����
int changeSeats(int arr[][COLUMN]); //������ �����ϴ� �Լ��� ����
//check.c
int freqSeats(int arr[][COLUMN]); //�¼��� ���� ���� �Լ��� ����
int checkInput(int row, int column); //����ڰ� �Է��� ���� �˻��ϴ� �Լ��� ����