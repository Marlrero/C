#ifndef __DATA_H__
#define __DATA_H__

//#define DEBUG

#define ROW 10
#define COLUMN 10

#define ID_LENGTH 15
#define PWD_LENGTH 20
#define NAME_LENGTH 10
#define SEAT_LIMIT 2

typedef struct
{
	int year; //������ ����(4�ڸ�)
	int month; //���� ����(1�ڸ�)
	int date; //���� ����(1�ڸ�)
} BIRTH; //��������� ������ ����ü�� typedef�� ����

typedef struct RESER_SEAT
{
	int row; //�¼� ���� ����
	int column; //�¼� ���� ����
} RESER_SEAT; //�¼� ������ ������ ����ü�� typedef�� ����

typedef struct CUSINFO
{
	struct CUSINFO *pre; //�������
	char id[ID_LENGTH]; //���̵� ����
	char password[PWD_LENGTH]; //�н����带 ����
	char name[NAME_LENGTH]; //�̸��� ����
	BIRTH birth; //��������� ����
	int seat_count; //���� ������ �¼��� ��
	RESER_SEAT infor_check[SEAT_LIMIT]; //���� ������ ����
	struct CUSINFO *next; //�������
} CUSINFO; //�� ����ü�� typedef�� ���� ->85 -> 4byte ��� * 22 = 88byte(3byte)

#endif