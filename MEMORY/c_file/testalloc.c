#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<stdint.h>
int main()
{
  int c = 0;
  char *p = (char *)malloc(4096*40-8);
  memset(p,7,4096*40-8);

  printf("打印正数4096*40个字节\n");
  for(int i = 0;i < 4096*40;++i)
  {
    printf("mmap'ed起始地址:%p  终止值:%d\n",p+i,*(p+i)); 
    if(*(p+i) == 7)
    {
      c++;
    }
  }

  printf("共计%d个7\n",c);
  printf("起始地址%p\n",p);
  printf("size:%ld\n",*((size_t*)(p-8)));
}
