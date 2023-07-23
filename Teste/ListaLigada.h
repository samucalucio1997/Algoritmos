#include <stdio.h>
#include <stdlib.h>
struct no_lig
{
  int value;
  struct no_lig *next;
  struct no_lig *prev;
};
struct array_list_int
{
  struct no_lig *first, *last;
  unsigned int size;
};
typedef struct array_list_int *array_list_int;

int array_list_push_back(array_list_int li, int valor)
{
  struct no_lig *pro = (struct no_lig *)malloc(sizeof(struct no_lig));
  pro->value = valor;
  pro->next = 0;
  if (li->first == 0)
  {
    li->first = pro;
    li->first->prev = 0;
    li->first->next = 0;
    li->size = 0;
  }
  else
  {
    pro->prev = li->last;
    li->last->next = pro;
  }
  li->last = pro;
  li->size++;
  return li->size;
}
unsigned int ll_push_index(array_list_int li, int index, int valor)
{
  int con = 0;
  struct no_lig *per = li->first;
  struct no_lig *pro = (struct no_lig *)malloc(sizeof(struct no_lig));
  pro->value = valor;
  while (con != index)
  {
    per = per->next;
    con++;
  }
  pro->prev = per->prev;
  per->prev = pro;
  pro->next = per;
  return ++li->size;
  // while(con!=po-1){
  //   per = per->next;
  // }
  // per->next = pro;
}

unsigned int array_list_size(array_list_int li){
       return li->size;
}

void ll_write(array_list_int li)
{ // write the elements
  struct no_lig *po = li->first;
  printf("[");
  printf("%d ", po->value);
  po = po->next;
  while (po != 0)
  {
    printf(", %d", po->value);
    po = po->next;
  }
  printf("]");
}
void ll_push_front(array_list_int li, int value)
{
  struct no_lig *new_node = (struct no_lig *)malloc(sizeof(struct no_lig));
  new_node->value = value;
  if (li->first == 0)
  {
    new_node->prev = 0;
    new_node->next = 0;
    li->first = new_node;
    li->last = new_node;
    li->size = 0;
  }
  else
  {
    new_node->prev = 0;
    li->first->prev = new_node;
    new_node->next = li->first;
    li->first = new_node;
  }
  li->first = new_node;
  li->size++;
}
int array_list_get(array_list_int li, int index)
{
  if(index<0||index>li->size){
    int erro=1;
    return erro;
  }else{
  int con = 0;
  struct no_lig *node = li->first;
  while (con != index)
  {
    node = node->next;
    con++;
  }
  return node->value;
  }
}
void destroy(array_list_int li)
{
  struct no_lig *no = li->first;
  li->size=0;
  while (no->next != 0)
  {
    struct no_lig *d = no;
    no = no->next;
    free(d);
  }
}
unsigned int array_list_find(array_list_int li,int element){
       unsigned int con=0;
       struct no_lig *node = li->first;
       while (con!=li->size)
       {
         if(node->value==element){
             break;
         }
         node=node->next;
         con++;
       }
      return con;   
}

int ll_pop_begin(array_list_int li)
{
  struct no_lig *lixo = li->first;
  li->first = li->first->next;
  free(lixo);
  li->first->prev = 0;
  if (li->first != lixo)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int ll_pop_final(array_list_int li)
{ if(li->first==0){
    return 0;
}else{
  struct no_lig *lixo = li->last;
  li->last = lixo->prev;
  li->last->next = 0;
  free(lixo);
  if (li->last != lixo)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
}

int ll_pop_ind(array_list_int li, int index){  
    int con=0;
    struct no_lig *trash = li->first;
    while(con!=index){
      trash = trash->next;  
    }
    trash->next->prev=trash->prev;
    trash->prev->next=trash->next;
    free(trash);
    li->size--;
    if(trash->value!=0){
        return 0;  
    }else{
      return 1;
    }
}

struct array_list_int* array_list_create()
{
  struct array_list_int *new_list;
  new_list = (struct array_list_int *)malloc(sizeof(struct array_list_int));
  if (new_list != 0)
  {
    new_list->first = 0;
    new_list->last = 0;
  }
  return new_list;
}

// int main()
// {
//   struct array_list_int *list = array_list_create();
//   int y;
//   scanf("%d", &y);
//   while (y != 0)
//   {
//     array_list_push_back(list, y);
//     scanf("%d", &y);
//   }
//   ll_write(list);
//   ll_pop_begin(list);
//   printf("\n %d", array_list_size(list));
//   printf("\n");
//   printf("%d\n", array_list_get(list, 3));
//   ll_write(list);
//   printf("\n");
//   return 0;
// }
