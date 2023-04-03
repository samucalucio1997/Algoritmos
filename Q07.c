#include <stdio.h>
int difer(int qtd, int si, int sp){
      int p[qtd];
      for(int i=0;i<qtd;i++){
        scanf("%d",&p[i]);
        if(p[i]%2==0){
            sp=sp+p[i];
        }else{
            si=si+p[i];  
        }
      }
    return sp-si;  
}

int main(){
    int qtd,dif,si,sp;
    si=0;
    sp=0;  
    scanf("%d",&qtd);
    dif= difer(qtd,si,sp);     
    printf("%d",dif);
    return 0;
}