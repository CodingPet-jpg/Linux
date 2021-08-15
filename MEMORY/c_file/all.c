# include <stdlib.h>
# include <stdio.h>

int main()
{
 int * p =  (int *)malloc(16);
 *(p+15) = 11;
 printf("%d\n",*(p+11));
}
