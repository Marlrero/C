#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#define FREE(X) free(X); X = NULL;
#define BUFFER_SIZE 100

void createMembership(CUSINFO **linked);
CUSINFO *loginMembership(CUSINFO *linked); //�α����ϴ� �Լ�
CUSINFO *searchMembership(const int mode, const char *keyid, const char *keypwd, CUSINFO *linked);
																	//ȸ���� ã�� �Լ�
int addCustomSeats(CUSINFO *member, const int row, const int column); //ȸ���� �¼��� �˻��Ͽ� ȸ�������� �߰�
int deleteCustomSeats(CUSINFO *member, const int row, const int column); //ȸ���� �¼��� �˻��Ͽ� ȸ�������� ����
void deleteMembership(CUSINFO *member, int(*arr)[COLUMN], CUSINFO **linked);

#endif
