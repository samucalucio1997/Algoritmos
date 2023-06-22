#include <iostream>
using namespace std;
int Labin_bk(int (*A)[20], int linha,
int colunas,int x,int y){
  if(x==-1||y==-1||x==colunas||y==linha||A[x][y]!=0){
      return 0;
  }
  if(x==colunas-1&&y==linha-1){
    return 1;
  }
  int ans = 0;
  ans=Labin_bk(A,linha,colunas,x,y+1);
  if(ans==0){
     ans=Labin_bk(A,linha,colunas,x+1,y);
  }
  if(ans==0){
    ans = Labin_bk(A,linha,colunas,x-1,y);
  }
  if(ans==0){
    ans=Labin_bk(A,linha,colunas,x,y-1);
  }
  A[x][y]=0;
  return ans;
}

int main(){
    int k,m;
    cin>>k>>m;
    int (*A)[m] = new int[k][m];
    for(int i=0;i<k;++i){
        for(int p=0;p<m;++p){
            cin>>A[i][p];
        }
    }
    cout<<Labin_bk(A,k,m,0,0)<<endl;
}