#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define SIZE    100
char *addrs[SIZE];
char dest[4096][SIZE];
int main()
{
        printf("当前进程号：%d\n",getpid());
        printf("t=%d",sizeof(size_t));
        printf("内存分配前，按ENTER分配内存\n");
        getchar();
        int i;
        for (i = 0; i < SIZE; i++) {
                addrs[i] = malloc(4096);
        } 
        // 问题：下面读取一系列malloc出来的内容时，会不会产生缺页中断从而调入物理内存？？
        for (i = 0; i < SIZE; i++) {
            // 只读addrs[i]，并不写入。
                memcpy(dest[i], addrs[i], 4096);
        }
        printf("内存已分配，按ENTER释放内存\n");
        getchar();
        free(addrs[0]);
        printf("内存已分配，按ENTER退出程序\n");
        getchar();
}
