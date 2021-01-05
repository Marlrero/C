#ifndef __FILE_H__
#define __FILE_H__

#define FREE(X) free(X); X = NULL;
#define LOCA_SIZE 300

//#define DEBUG

FILE *checkFile(const char *locate, FILE **fp, const char *mode); //������ ���� üũ�ϴ� �Լ�
void loadSeats(int(*arr)[COLUMN], FILE **seatdata); //�¼������� �о �迭�� �ҷ����� �Լ�
void loadCustom(CUSINFO **linked, FILE **database);
void saveSeats(int(*arr)[COLUMN], FILE **seatdata);
void saveCustom(CUSINFO **linked, FILE **database); //�����Ҵ��� �޸𸮸� ��� �ݳ��ؾ� ��
CUSINFO *getLastNode(CUSINFO *linked);

#endif