#include <iostream>
#include <algorithm>
#define INF =1000
using namespace std;
int Labin_bk(int A[20][20], int linha,
int colunas,int x,int y){
   int con=0;
  if(x==-1||y==-1||x==linha||y==colunas||A[x][y]!=0){
      return 1000;
  }
  if(x==linha-1&&y==colunas-1){
    return 1;
  }
  int con1=Labin_bk(A,linha,colunas,x,y+1);
  int con2=Labin_bk(A,linha,colunas,x+1,y);
  int con3=Labin_bk(A,linha,colunas,x-1,y);
  int con4=Labin_bk(A,linha,colunas,x,y-1);
  return 1+min(min(con1,con2),min(con3,con4));
}


int main(){
    int k,l;
    cin>>k>>l;
    int P[31][31];
    for(int i =0;i<k;++i){
        for(int p=0;p<l;++p){
            P[i][p];
        }
    } 
}