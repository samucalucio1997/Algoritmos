#include <stdio.h>
int Somasub(int A[],int tam){
   int k=0,maior=0;
   for(int i=0;i<tam;++i){
    if(A[i]>maior){
        maior = A[i];
    }
   }
   for(int j=0;j<tam;++j){
    k+=A[j];
    for(int p=j+1;p<tam;++p){
       k+=A[p];
    if(k>maior){
        maior=k;
    }
    }
    k=0;
   }
   return maior;
}
int main(){
     int tam;
     scanf("%d\n",&tam); 
     int A[tam];
     for(int i=0;i<tam;++i){
        scanf("%d",&A[i]);
     }
     printf("%d\n",Somasub(A,tam));
    return 0; 
}