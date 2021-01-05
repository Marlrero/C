#ifndef __CUSTOM_H__
#define __CUSTOM_H__

#define FREE(X) free(X); X = NULL;
#define BUFFER_SIZE 100

void createMembership(CUSINFO **linked);
CUSINFO *loginMembership(CUSINFO *linked); //로그인하는 함수
CUSINFO *searchMembership(const int mode, const char *keyid, const char *keypwd, CUSINFO *linked);
																	//회원을 찾는 함수
int addCustomSeats(CUSINFO *member, const int row, const int column); //회원의 좌석을 검사하여 회원데이터 추가
int deleteCustomSeats(CUSINFO *member, const int row, const int column); //회원의 좌석을 검사하여 회원데이터 삭제
void deleteMembership(CUSINFO *member, int(*arr)[COLUMN], CUSINFO **linked);

#endif
