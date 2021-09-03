#define MODULE MAIN
#define HAVE_TUNABLES 1 
#include <stdio.h>
#include"dl-tunables.h"
#include<stdint.h>

int main()
{
  TUNABLE_NAME_S(1,2,3);
  TUNABLE_GET(glibc, mem, tagging, size32_t, NULL); 
  printf("return:%d\n",i);
}
