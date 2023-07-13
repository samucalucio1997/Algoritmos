#include <stdio.h>
#include <stdlib.h>
struct array_list_int{
int *data;
unsigned int size;
unsigned int capacity;
};
int increase_memory(struct array_list_int *list){//array_list_increase_capacity
if(list->capacity==list->size){
      int *new_data = (int*)malloc(sizeof(int)*(list->capacity*2));
      for(int i=0;i<list->size;++i){
           *(new_data + i)=*(list->data + i);
      }
      list->data=new_data;
      free(list->data);
      list->capacity=list->capacity*2;
}
return 0;
}
/*########################################################*/
struct array_list_int * array_list_create(){
struct array_list_int *new_list;
new_list = (struct array_list*)malloc(sizeof(struct array_list_int));
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
/*########################################################*/
void array_list_read_until(struct array_list_int *list, int end_reading){
int x;
while (scanf("%d",&x),x!=end_reading){
if (list->size==list->capacity)
increase_memory(list);
list->data[list->size++] = x;
}
}
/*########################################################*/
void array_list_destroy(struct array_list_int* list) {
      free(list);
}
/*########################################################*/
void array_list_print(struct array_list_int *list){
printf("[");
if (list->size>0){
printf("%d",list->data[0]);
for (int i=1 ; i<list->size ; ++i)
printf(", %d",list->data[i]);
}
printf("]");
}
/*########################################################*/
int array_list_push_back(struct array_list_int *list,int p){
      int l = list->size;
      if(list->capacity==list->size){
           if(!increase_memory){
               return array_list_size(list);
           } 
      }
      list->data[list->size++]=p;
      return array_list_size(list);
}
/*########################################################*/
unsigned int pop_back(struct array_list_int *list){
    if(list->size>0){
     list->size--;
    }
    return array_list_size(list);
}
/*########################################################*/
int array_list_find(struct array_list_int* list, int element) {
  int i=0;
  while(i>list->size){
      if(list->data[i]==element){
      //     return 
      }
  }
  return -1;
}
/*########################################################*/
unsigned int array_list_capacity(struct array_list_int* list) {
  return list->capacity;
}
/*########################################################*/
unsigned int array_list_size(struct array_list_int* list) {
  return list->size;
}
/*########################################################*/
int array_list_get(struct array_list_int* list, int index, int* error) {
  *error = 0;
  if (index < 0 || index >= list->size) { /*Index must be valid*/
    *error = 1;
    return 0;
  }
  return list->data[index];
}
/*########################################################*/
struct array_list_int * array_list_clone(struct array_list_int *list){
      struct array_list_int *copia = (struct array_list_int *) malloc(sizeof(struct array_list_int));
      copia->capacity = list->capacity;
      copia->size = list->size;
      copia->data = (int *)malloc(sizeof(int)*(list->capacity));
      for(int i=0;i<list->size;++i){
            copia->data[i] = list->data[i];
      }      
      return copia;
}
/*########################################################*/
unsigned int array_list_insert_at(struct array_list_int *list, int value, int index){
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
/*########################################################*/
unsigned int array_list_remove_from(struct array_list_int *list,int index){
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
/*########################################################*/
int main(){
struct array_list_int *list01 = array_list_create();
array_list_read_until(list01,-1);
//array_list_print(list01);
//printf("\n");
struct array_list_int *copia;
copia = array_list_clone(list01);
array_list_remove(copia,4);
printf("\n");
array_list_print(copia);
free(list01->data);
free(list01);
return 0;
}
