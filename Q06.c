#include <stdio.h>
int con(int g, int mul,int con){
    if(g%mul==0){
       con++;
    }
    return con;
}
int main(){
    int qtd,mul,cont=0;
    scanf("%d %d", &mul, &qtd);
    int p[qtd];
    for(int c=0;c<qtd;c++){
        scanf("%d ",&p[c]);
        cont = con(p[c],mul,cont);
    }
    printf("%d",cont);
    return 0;
}
