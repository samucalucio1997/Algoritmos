#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct carga{
 int peso;
 float value;
};
float Mochila_bk(struct carga *carga,int tam,int peso,float value){
float a=0,b=0;
if(tam==0||peso==0.00){
   return 0.00;
}
if(peso-carga[tam-1].peso>0.00){
  a=carga[tam-1].value+Mochila_bk(carga,tam-1,peso-carga[tam-1].peso,value);
}
b=Mochila_bk(carga,tam-1,peso,value);
float r = a > b ? a : b;
return r;
}

int main(){
    int n,m;
    cin>>n>>m;
struct carga *carga=new struct carga[n];
for(int i=0;i<n;++i){
  cin>>carga[i].peso>>carga[i].value;
}
float resp =Mochila_bk(carga,n,m,0);
float k=round(resp * 100) / 100;
cout<<k<<endl;
}