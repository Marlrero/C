#ifndef __FILE_H__
#define __FILE_H__

#define FREE(X) free(X); X = NULL;
#define LOCA_SIZE 300

//#define DEBUG

FILE *checkFile(const char *locate, FILE **fp, const char *mode); //파일을 열때 체크하는 함수
void loadSeats(int(*arr)[COLUMN], FILE **seatdata); //좌석파일을 읽어서 배열로 불러오는 함수
void loadCustom(CUSINFO **linked, FILE **database);
void saveSeats(int(*arr)[COLUMN], FILE **seatdata);
void saveCustom(CUSINFO **linked, FILE **database); //동적할당한 메모리를 모두 반납해야 함
CUSINFO *getLastNode(CUSINFO *linked);

#endif