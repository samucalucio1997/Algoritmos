#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hiperf(int hk){
     if(hk==1){
        return 1;
     }else{
         return pow(hk,hk)*hiperf(hk-1);
     }
}

int main(){
    printf("%d", hiperf(4));
}