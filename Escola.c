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
     printf("%d\n",aluno->matricula);
     for(int c=0;c<qtd;c++){
        printf("%d ",(aluno->notas[c])*(aluno->pesos[c]));
     }
}
int main(){
  int qtd,nota,peso;
  struct Aluno *aluno;
  scanf("%d",&qtd);
  aluno->notas = (int *) malloc(sizeof(int)*qtd);
  aluno->pesos = (int *) malloc(sizeof(int)*qtd);
  scanf("%i", aluno->matricula);
  for(int i=0;i<qtd;i++){
    scanf("%d %d",&nota,&peso);
    inserir(peso,aluno,nota,i);
  }
  print_array_struct(aluno,qtd);
}

