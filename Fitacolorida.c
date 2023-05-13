#include <stdio.h>
int main(){
int n,indiceZero=0,p=1,k=0;
scanf("%d",&n);
int array[n],arr[n];
for(int u=0;u<n;++u)
   scanf("%d",&array[u]);
for(int i=0;i<n;++i){
  if(array[i]==0){
   if(indiceZero!=0){
     for(int y=(i-indiceZero)/2 + indiceZero+1;y<i;++y){
         if(((i-indiceZero)/2 + indiceZero+1)%2==0&&y==((i-indiceZero)/2 + indiceZero+1)){
          k=arr[y-1];
         }else{
          k=arr[y];
         }
         if(array[y]!=0){
           arr[y]=--k;
         }
         else{
            arr[y]=0;
         }  
     }
     indiceZero = i;
     p=1;
     arr[i]=0;
   }else{
      int l=i;
      for(int u=0;u<i;++u){
         arr[u]=l--;
      }
     indiceZero = i;
     p=1;
     arr[i]=0;
   }
  }
  else{
    arr[i]=p++;
  }
}
for(int i =0 ;i<n;++i){
   if(i<n-1){
   printf("%d ",arr[i]);
   }else{
      printf("%d",arr[i]);
   }
}

}
