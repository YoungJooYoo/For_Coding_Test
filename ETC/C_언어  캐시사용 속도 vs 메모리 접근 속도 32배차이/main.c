#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(void)
{
  int Mb = 0;
  while ( malloc(1<<20))  ++Mb;
  printf("Allocated %d Mb totalIn", Mb);

  return 0;
}
*/


#define DUMBCOPY for (i = 0; i < 65536; i++) \
destination[i] = source[i]

#define SMARTCOPY memcpy (destination, source, 65536)

enum {
  STRING_SIZE = 65536,
  LOOP_SIZE = 100
};

int main (void)
{
  char source [STRING_SIZE];
  char destination [STRING_SIZE];
  int i;
  int j;

  for (j = 0; j < LOOP_SIZE; j++) {
      SMARTCOPY;
      /* DUMBCOPY; */
  }

  return 0;
}

/* 사용법

% cc -0 cache. c % time a.out
1.0 seconds user time
# DUMBCOPY로 바꾸고 재컴파일한다.
% time a.out
7.0 seconds user time
위의 프로그램을 두 가지 다른


빌드 커맨드
clang -std=c89 -Wall -pedantic-errors *.c
*/
