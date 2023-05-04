#include <stdio.h>
#include <stdlib.h>
struct no_lig {
    int value;
    struct no_lig *next;
}
struct lig{
    struct no_lig *begin,*last;
}
typedef struct lig * lig;

void inserir_final(lig li,int valor){
struct no_lig *pro= (struct no_lig *)malloc(sizeof(struct no_lig));
pro->value=valor;
pro->next=0;
if(li->first==0){
    l->first=pro;
}else{
li->last->next=pro;
}
li->last=pro;
}
void inserir_indexado(lig li,int po,int valor){
  int con=0;
  struct no_lig *per=li->first;
  struct no_lig *pro= (struct no_lig *)malloc(sizeof(struct no_lig));
  pro->value = valor;
  while(con!=po-1){
    per = per->next;
  }
  per->next = pro;
}

int main(){

}