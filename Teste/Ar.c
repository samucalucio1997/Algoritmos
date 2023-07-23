#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=1000;//modfique o valor da entrada aqui
    printf("%d\n",n);
    // printf("%d\n", RAND_MAX);
     for (int i = 1; i <= n-1; i++)
    {
        printf("%d ", rand());
    }
    printf("%d",-50);
    return 0;
}