#include<stdio.h>
#include<stdlib.h>

int main()
{
  char *v = getenv("author_name");
  printf("作者是：%s\n",v);
}
