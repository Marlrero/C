#define SIZE 10

/* 
   �¼��� ���������� ����ϸ� ���ڷ� �迭�� ������ �ʿ�� ����
   void bookSeats(int answer);

   �� ���α׷��� ����� �迭�� �����͸� �̿���
*/

//print.c
int printMenus(void); //�޴��� ����ϴ� �Լ��� ����
void printSeats(int arr[]); //�¼��� ������¸� ����ϴ� �Լ��� ����
//reservation.c
int bookSeats(int arr[]); //�¼��� �����ϴ� �Լ��� ����
int cancleSeats(int arr[]); //�¼��� ����ϴ� �Լ��� ����
int changeSeats(int arr[]); //������ �����ϴ� �Լ��� ����
//freq.c
int freqSeats(int arr[]); //�¼��� ���� ���� �Լ��� ����