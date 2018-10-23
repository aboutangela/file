#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int test = open("text.txt", O_RDWR);
  printf("open result: %d \n", test);
  int test2 = open("test.txt", O_RDWR);
  printf("open error: %d \n", test2);

  char stored[6];
  int rtest = read(test, stored, 6);
  printf("read result: %s \n", stored);

  int wtest = write(test, "result", 6);
  //char wstored[12];
  //int ntest = read(test, wstored, 12);
  //printf("read after write result: %s \n", wstored);

  int ctest = close(test);
  printf("close result: %d \n", ctest);
  int ctest2 = close(rtest);
  printf("close error: %d \n", ctest2);
}
