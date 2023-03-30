#include <stdio.h>
int fr(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*fr(n-1);
    }
}
int fator(int num){
     return fr(2*num)/fr(num);
}
int main(){  
    printf("%d ", fator(3));
    return 0;
}