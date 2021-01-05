//������� ����
#include <stdio.h>
#include <string.h> //���ڿ� ó�� �Լ��� ���ǵ� ������� ����

//��ȣ��� ����
#define ROW 10
#define COLUMN 10
#define PEOPLE 100

//typedef ����
//windows���� �޸𸮴� 4byte������ ����
typedef struct
{
	int num; //ȸ����ȣ(����ü �迭�� �ε���)���
	int seat_row; //�¼��� �� ���
	int seat_column; //�¼��� �� ���
	int age; //���� ���
	char name[10]; //���̸� ���
	char handnum[15]; //�޴�����ȣ ���
} CUSINFO; //�� ����ü�� typedef�� ����

//�������� ����
CUSINFO cusarr[PEOPLE]; //���������� ����ü�迭 ����(�ε����� ȸ����ȣ)
static int cus_num = 0; //ȸ����ȣ�� �������������� ����(ȸ����ȣ�� ���ʴ�� �Ҵ�)

/* 
   �¼��� ���������� ����ϸ� ���ڷ� �迭�� ������ �ʿ�� ����
   void bookSeats(int answer);

   �� ���α׷��� ����� �迭�� �����͸� �̿���
*/

//�Լ����� ����
//print.c
int printMenus(void); //�޴��� ����ϴ� �Լ��� ����
void printSeats(int arr[][COLUMN]); //�¼��� ������¸� ����ϴ� �Լ��� ����
int findMenuCusto(void); //���� ã�� �� �޴��� ����ϴ� �Լ��� ����
//reservation.c
int bookSeats(int arr[][COLUMN]); //�¼��� �����ϴ� �Լ��� ����
int cancleSeats(int arr[][COLUMN]); //�¼��� ����ϴ� �Լ��� ����
int changeSeats(int arr[][COLUMN]); //������ �����ϴ� �Լ��� ����
//check.c
int freqSeats(int arr[][COLUMN]); //�¼��� ���� ���� �Լ��� ����
int checkInput(int row, int column); //����ڰ� �Է��� ���� �˻��ϴ� �Լ��� ����
//find.c
int find_customer_main(void); //���� ã�� �Լ��� ����
int find_customer_num(void); //����ȣ�� ã�� �Լ��� ����
int find_customer_name(void); //���̸��� ã�� �Լ��� ����
int find_customer_hand(void); //�� �ڵ�����ȣ�� ã�� �Լ��� ����