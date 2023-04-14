#include <stdio.h>
#include <stdlib.h>
int main(){
    int l;
    long long n=0,ind;
    scanf("%d",&l);
    for(int c=0;c<l;c++){
        long long g,*p,dif;
        scanf("%lld",&g);
        p = (long long *) malloc(g*sizeof(long long));
        for(int i=0;i<g;i++){
            scanf("%lld",&dif);
            ind = i-1;
            for(int c=0;c<g;)
        }  
        for(int t=0;t<g;t++){
               if(p[t]!=0)
                 n++;
         }
        printf("%lld \n",n);
        n=0;
        g=0;
        free(p);          
    }
}       