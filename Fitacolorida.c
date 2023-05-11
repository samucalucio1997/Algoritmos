#include <stdio.h>

int main(){
int n,indiceZero=0,p=1;
scanf("%d",&n);
int array[n],arr[n];
for(int u=0;u<n;++u)
   scanf("%d",&array[u]);
for(int i=0;i<n;++i){
  if(array[i]==0){
     for(int y=(i-indiceZero)/2;y<i;++y){
         int k=y;
         arr[y]=k--;
     }
     indiceZero = i;
     p=1;
  }
  else{
    arr[i]=p++;
  }
}
for(int i =0 ;i<n;++i){
   printf("%d ",arr[i]);

}

}

