#include <stdio.h>
#include <stdlib.h>
struct Aluno
{
  long long matricula;
  int *notas;
  int *pesos;
  int qtd_notas;
};
void inserir(int peso, struct Aluno *Aluno,int nota,int con){
  Aluno->notas[con] = nota;
  Aluno->pesos[con] = peso;
  con++; 
}
void print_array_struct(struct Aluno *aluno, int qtd){
     printf("%d\n",&aluno->matricula);
     for(int c=0;c<qtd;c++){
        printf("%d ",(aluno->notas[c])*(aluno->pesos[c]));
     }
}
int media_alun(struct Aluno *aluno, int qtd){
    
}
int main(){
  int qtd,nota,peso;
  struct Aluno *aluno,*gamb;
  int al;
  scanf("%d",&al);
  aluno  = (struct Aluno *) malloc(sizeof(struct Aluno)*al);
  for(int c=0;c<al;c++){
    scanf("%d",&qtd);
    for(int i=0;i<qtd;i++){
      aluno->notas = (int *) malloc(sizeof(int)*qtd);
      aluno->pesos = (int *) malloc(sizeof(int)*qtd);
      // scanf("%lld",aluno->matricula);
      scanf("%d %d",&nota,&peso);
      inserir(peso,aluno+c,nota,i);
    }
  }
  print_array_struct(aluno,qtd);
}

