#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){
  int test = open("text.txt", O_RDWR | O_APPEND);
  printf("open result: %d \n", test);
  int test2 = open("test.txt", O_RDWR);
  printf("open error: %d \n", test2);

  char *stored= malloc(20);
  int rtest = read(test, stored, 6);
  printf("read result: %s \n", stored);

  char *stored2 = malloc(20);
  char *stored3 = malloc(20);
  strcat(stored2,"skeleton");
  int wtest = write(test, stored2, strlen(stored2));
  int test3 = open("text.txt", O_RDWR | O_APPEND);
  int atest = read(test3, stored2, 14);
  printf("read result after write: %s \n", stored2);

  int ctest = close(test);
  printf("close result: %d \n", ctest);
  int ctest2 = close(rtest);
  printf("close error: %d \n", ctest2);
}
