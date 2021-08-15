/* Per thread arena example. */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void* threadFunc(void* arg) {
        printf("Before malloc in thread 1\n");
        getchar();
        char* addr = (char*) malloc(1000);
        printf("After malloc and before free in thread 1\n");
        getchar();
        free(addr);
        printf("After free in thread 1\n");
        getchar();
}
char o = 'B';
double *addr[100];

int main() {
        pthread_t t1;
        void* s;
        int ret;
        printf("Welcome to per thread arena example::%d\n",getpid());
        printf("Before malloc in main thread\n");
        printf("current loc:%p\n",sbrk(0));
        getchar();
        for(int i = 0;i<100;i++){ 
          addr[i] = malloc(4096);
        }
        printf("address%p\n",addr);
        printf("after loc%p:\n",sbrk(0));
        int i;
        printf("After malloc and before free in main thread\n");
        printf("after init%p\n",sbrk(0));
        getchar();
        free(addr-1000);
        printf("After free in main thread\n");
        getchar();
        ret = pthread_create(&t1, NULL, threadFunc, NULL);
        if(ret)
        {
                printf("Thread creation error\n");
                return -1;
        }
        ret = pthread_join(t1, &s);
        if(ret)
        {
                printf("Thread join error\n");
                return -1;
        }
        return 0;
}
