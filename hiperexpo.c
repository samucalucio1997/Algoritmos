#include <stdio.h>
#include <math.h>

long hiperexpo(int hj){
    if (hj==0)
    {
        return 1;
    }else{
        return pow(hj,hiperexpo(hj-1));
    }    
}

int main(){
    printf("%i",hiperexpo(2));
}