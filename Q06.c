#include <stdio.h>
#include <stdlib.h>
struct array_list{
int *data;
unsigned int size;
unsigned int capacity;
};
void array_list_increase_capacity(struct array_list *list){
if(list->capacity==list->size){
      int *new_data = (int*)malloc(sizeof(int)*(list->capacity+10));
      for(int i=0;i<list->size;++i){
           *(new_data + i)=*(list->data + i);
      }
      list->data=new_data;
      free(list->data);
      list->capacity=list->capacity+10;
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
      list->data[list->size++]=p;
}
void pop(struct array_list *list){
    list->size--;
}
struct array_list * array_list_clone(struct array_list *list){
      struct array_list *copia = (struct array_list *) malloc(sizeof(struct array_list));
      copia->capacity = list->capacity;
      copia->size = list->size;
      copia->data = (int *)malloc(sizeof(int)*(list->capacity));
      for(int i=0;i<list->size;++i){
            copia->data[i] = list->data[i];
      }      
      return copia;
}
unsigned int array_list_insert(struct array_list *list, int value, int index){
       int y=0,x=0;
      for(int i=index;i<list->size+1;++i){
       if(i==index){
        y=list->data[i];
        list->data[i]=value;
        continue;
       }else{
        x=list->data[i];
        list->data[i]=y;
        y=x;
       }
      }
      return list->size++;
}
unsigned int array_list_remove(struct array_list *list,int index){
    int x=0,y=0;
    for(int i=list->size-1;i>=index;--i){
         if(i==list->size-1){
              y=list->data[i];
              list->data[i]=0;
              continue;
         }else{
            x=list->data[i];
            list->data[i]=y;
            y=x;
         }
    }
    return list->size--;
}
int main(){
struct array_list *list01 = array_list_create();
array_list_read_until(list01,-1);
//array_list_print(list01);
//printf("\n");
struct array_list *copia;
copia = array_list_clone(list01);
array_list_remove(copia,4);
printf("\n");
array_list_print(copia);
free(list01->data);
free(list01);
return 0;
}
