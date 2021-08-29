# include<stdio.h>
#include<stdlib.h>
int main()
{
  printf("开始");
  char* d = (char*)malloc(4096-8);
  char* c = d;
  for(int i = 1;i < 12096;i++){
    *d = 1;
    ++d;
  }
  printf("%d",*(d-1));
}
