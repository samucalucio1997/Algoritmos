#include <stdio.h>
#include <stdlib.h>
struct no_lig
{
  int value;
  struct no_lig *next;
  struct no_lig *prev;
};
struct lig
{
  struct no_lig *first, *last;
  unsigned int size;
};
typedef struct lig *lig;

void ll_push_back(lig li, int valor)
{
  struct no_lig *pro = (struct no_lig *)malloc(sizeof(struct no_lig));
  pro->value = valor;
  pro->next = 0;
  if (li->first == 0)
  {
    li->first = pro;
    li->first->prev = 0;
    li->first->next = 0;
    li->size = 1;
  }
  else
  {
    pro->prev = li->last;
    li->last->next = pro;
  }
  li->last = pro;
  li->size++;
}
unsigned int ll_push_index(lig li, int index, int valor)
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
void ll_write(lig li)
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
void ll_push_front(lig li, int value)
{
  struct no_lig *new_node = (struct no_lig *)malloc(sizeof(struct no_lig));
  new_node->value = value;
  if (li->first == 0)
  {
    new_node->prev=0;
    new_node->next=0;
    li->first=new_node;
    li->last=new_node;
    li->size=0; 
  }
  else
  {
    new_node->prev=0;
    li->first->prev=new_node;
    new_node->next=li->first;
    li->first=new_node;
  }
  li->first = new_node;
  li->size++;
}
int ll_getElement_ind(lig li, int index)
{
  int con = 0;
  struct no_lig *node = li->first;
  while (con != index)
  {
    node = node->next;
    con++;
  }
  return node->value;
}
void destroy(lig li)
{
  struct no_lig *no = li->first;
  while (no->next != 0)
  {
    struct no_lig *d = no;
    no = no->next;
    free(d);
  }
}

int ll_pop_begin(lig li)
{
  struct no_lig *lixo = li->first;
  li->first = li->first->next;
  li->first->prev=0;
  free(lixo);
  if (li->first != lixo)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int ll_pop_final(lig li)
{
  struct no_lig *lixo = li->last;
  // while (cursor->next != li->last)
  // {
  //   cursor = cursor->next;
  // }
  li->last=lixo->prev;
  li->last->next=0;
  free(lixo);
  if(li->last!=lixo){
   return 1;
  }else{
    return 0;
  }
}

int ll_pop_ind(lig li, int index){

}

struct lig *ll_create()
{
  struct lig *new_list;
  new_list = (struct lig *)malloc(sizeof(struct lig));
  if (new_list != 0)
  {
    new_list->first = 0;
    new_list->last = 0;
  }
  return new_list;
}
int main()
{
  struct lig *list = ll_create();
  int x,y;
  scanf("%d",&x);
  while (y != 0){
    ll_push_back(list, y);
    scanf("%d", &y);
    }
  ll_write(list);
  ll_pop_begin(list);
  printf("\n %d", list->size);
  printf("\n");
  printf("%d\n", ll_getElement_ind(list, 3));
  ll_write(list);
  printf("\n");
  return 0;
}