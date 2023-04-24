#include <stdio.h>
#include <stdlib.h>
struct array_list{
int *data;
unsigned int size;
unsigned int capacity;
};
void array_list_increase_capacity(struct array_list *list){
if(list->capacity==list->size){
      list->capacity=list->capacity+10;
      struct array_list *new_list = (struct array_list *) malloc(sizeof(struct array_list)*list->capacity);
      struct array_list *antigo; 
      antigo =list;
      for(int i=0;i<list->size;++i){
           *(new_list->data + i)=*(list->data + i);
      }
      list=new_list;
      free(antigo);
}
fprintf(stderr,"Error on memory allocation.\n");
exit(-1);
}
struct array_list * array_list_create(){
struct array_list *new_list;
new_list = (struct array_list*)malloc(sizeof(struct array_list));
if (new_list==0){ /* Error */
fprintf(stderr,"Error on memory allocation.\n");
exit(-1);
}
new_list->capacity = 10;
new_list->size = 0;
new_list->data = (int*)malloc(sizeof(int)*new_list->capacity);
if (new_list->data==0){ /* Error */
fprintf(stderr,"Error on memory allocation.\n");
exit(-1);
}
return new_list;
}
void array_list_read_until(struct array_list *list, int end_reading){
int x;
while (scanf("%d",&x),x!=end_reading){
if (list->size==list->capacity)
array_list_increase_capacity(list);
list->data[list->size++] = x;
}
}
void array_list_print(struct array_list *list){
printf("[");
if (list->size>0){
printf("%d",list->data[0]);
for (int i=1 ; i<list->size ; ++i)
printf(", %d",list->data[i]);
}
printf("]");
}
void array_list_append(struct array_list *list,int p){
      int l = list->size;
      if(list->capacity==list->size){
            array_list_increase_capacity(list);
      }
      int i=0;
      list->data[list->size++]=p;
}
int main(){
struct array_list *list01 = array_list_create();
array_list_read_until(list01,-1);
int k;
scanf("%d",&k);
array_list_append(list01,k);
array_list_print(list01);
printf("\n");
free(list01->data);
free(list01);
return 0;
}
