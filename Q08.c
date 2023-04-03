#include <stdio.h>
#include <stdlib.h>
char * primo(int n){
    char *p;
    p=(char *) malloc(20*sizeof(char));
    for(int c=2;c<n;c++){
        if(n%c==0){
           printf("é composto ");
           mut(n); 
           break;
        }else{
            p="é primo";
        }
    }
    return p;
     
}
void mut(int n){
    for(int c=2;c<n;c++){
        if(n%c==0 && c!=n){
           printf("%d ",c);
        }
    }
}
int main(){
    char *p;
    int n;
    while(n!=0){
      scanf("%d",&n);  
      p=primo(n); 
      printf("%d ",n);
      printf("%s",p);
    }
}


