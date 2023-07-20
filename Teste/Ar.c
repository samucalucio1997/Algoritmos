#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=1000;
    printf("%d\n",n);
    // printf("%d\n", RAND_MAX);
     for (int i = 1; i <= n; i++)
    {
        printf("%d ", rand());
    }

    return 0;
}