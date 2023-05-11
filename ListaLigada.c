#include <stdio.h>
#include <stdlib.h>
struct no_lig {
    int value;
    struct no_lig *next;
};
struct lig{
    struct no_lig *first,*last;
};
typedef struct lig * lig;

void inserir_final(lig li,int valor){
struct no_lig *pro= (struct no_lig *)malloc(sizeof(struct no_lig));
pro->value=valor;
pro->next=0;
if(li->first==0){
    li->first=pro;
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
void ll_write(lig li){
    struct no_lig * po=li->first;
    printf("[");
    while(po!=0){
        printf(" %d ",po->value);
        po=po->next;
    }
    printf("]");
}
void ll_push_front(lig li,int value){
  struct no_lig *new_node=(struct no_lig *)malloc(sizeof(struct no_lig));
  new_node->value=value;
  if(li->first==0){
      new_node->next=0;
      li->last=new_node;
  }else{
    new_node->next=li->first;
  }
  li->first=new_node;
}

void destroy(lig li){
  struct no_lig *no = li->first;
  while(no->next!=0){
      struct no_lig *d  = no;
      no=no->next;
      free(d);  
  }
}

int ll_pop_begin(lig li){
   struct no_lig *lixo = li->first;
   li->first=li->first->next;
   free(lixo);
   if(li->first!=lixo){
    return 1;
   }else{
    return 0;
   }
}

int ll_pop_final(lig li){
   struct no_lig *cursor = li->first;
   while(cursor->next!=li->last){
    cursor=cursor->next;
   }
   cursor->next=0;
   free(li->last);
   li->last=cursor;
   return 1;
}

struct lig * ll_create(){
struct lig * new_list;
new_list = (struct lig*)malloc(sizeof(struct lig));
if (new_list != 0){
new_list->first=0;
new_list->last=0;
}
return new_list;
}
int main(){
struct lig *list = ll_create();
int x,k;
scanf("%d",&x);
   ll_push_front(list,x);
scanf("%d",&x);
while (x!=0){
  inserir_final(list,x);
  scanf("%d",&x);
}
ll_write(list);
ll_pop_begin(list);
printf("\n");
ll_write(list);
return 0;
}