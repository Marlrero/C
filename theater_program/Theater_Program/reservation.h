#ifndef __RESERV_H__
#define __RESERV_H__

#define MEMBER_LIMIT 10
 int bookSeats(int(*arr)[COLUMN], CUSINFO *member); //�¼��� �����ϴ� �Լ�
 int cancleSeats(int(*arr)[COLUMN], CUSINFO *member); //�¼��� ����ϴ� �Լ�
 int changeSeats(int(*arr)[COLUMN], CUSINFO *member); //������ �����ϴ� �Լ��� ����
CUSINFO *getLastNode(CUSINFO *linked);
void removeNode(CUSINFO *member, CUSINFO **linked);

#endif