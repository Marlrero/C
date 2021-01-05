#ifndef __PRINT_H__
#define __PRINT_H__

#include "data.h"

#define BUFFER_SIZE 100

 int  printMenus(void); //�޴��� ����ϴ� �Լ�
void  printSeats(const int(*arr)[COLUMN]); //�¼��� ������¸� ����ϴ� �Լ�
void  printMemberList(CUSINFO *linked); //ȸ�� ����� ����ϴ� �Լ�
void  printMemberSeatList(const CUSINFO *member); //ȸ���� �¼��� ����ϴ� �Լ�
char* inputString(const char *mode, const unsigned int size); //���ڿ��� �Է��ϴ� �Լ�
BIRTH*inputBirth(void);


#endif