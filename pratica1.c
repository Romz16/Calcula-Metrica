#include "aluno.h"
#include "aluno.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
  char nome[11];
  char curso[11];
  float nota;
};

struct turma {
  // vetor de ponteiro de alunos
  // inteiro com o tamanho da turma
  TAluno **pAluno;  
  int qtd;
  
};

// Manter como especificado
void lerInfos(int *qtd, char *option) { 
  scanf("%c %d",option, qtd); 
}

// Manter como especificado
void alocaAluno(TAluno **pAluno) { 
  *pAluno = malloc(sizeof(TAluno));
}

// Manter como especificado
void alocaTurma(TTurma **pTurma, int qtd) { 
  // Use a funcao alocaAluno aqui
  
  *pTurma = malloc(sizeof(TTurma)); 
  (*pTurma)->qtd = qtd;
  
  (*pTurma)->pAluno =  malloc(qtd * sizeof(TAluno*));
  for (int i = 0; i < qtd; i++)
  {
    alocaAluno(&(*pTurma)->pAluno[i]);/* code */
  }
      
  }


// Manter como especificado
void desalocaAluno(TAluno **pAluno) {
  free(*pAluno);
}

// Manter como especificado
void desalocaTurma(TTurma **pTurma) { 
  // Use a funcao desalocaTurma
  for (int i = 0; i < pTurma[i]->qtd; i++)
  {
    desalocaAluno(&(*pTurma)->pAluno[i]);
  }
  free (*pTurma);
}

// Manter como especificado
void lerTurma(TTurma *pTurma) {
  for (int  i = 0; i < pTurma->qtd; i++)
  {
  
    scanf("%s",pTurma->pAluno[i]->nome);
    
    scanf("%s",pTurma->pAluno[i]->curso);
   
    scanf("%f",&pTurma->pAluno[i]->nota);
  }
  
}

// Manter como especificado
float calcularMetrica(TTurma *pTurma, char* curso, char option) {
  float resultado =0.0, cont =0;
  if (option == 'S')
    {
        for (int  i = 0; i < pTurma->qtd; i++){
            if (strcmp(pTurma->pAluno[i]->curso,curso) == 0){
                resultado = resultado + pTurma->pAluno[i]->nota;
            }
            }
      return resultado;
    }
    else 
    {
      for (int  i = 0; i < pTurma->qtd; i++){
            if (strcmp(pTurma->pAluno[i]->curso,curso) == 0){
                resultado = resultado + pTurma->pAluno[i]->nota;
                cont++;
            }
      }
      resultado = resultado /cont;
      return resultado;
    }

    
}


// Manter como especificado
void printMetrica(char* curso, float metrica, char option) {
  printf("A %s no curso de %s eh %.1f\n", option == 'S' ? "soma" : "media", curso, metrica);
}


int main() {
    char option;
    int qtd;
    float resultado;

    TTurma *pTurma;

    lerInfos(&qtd, &option);

    alocaTurma(&pTurma, qtd);

    lerTurma(pTurma);

    resultado = calcularMetrica(pTurma, "computacao", option);
    printMetrica("computacao", resultado, option);

    resultado = calcularMetrica(pTurma, "direito", option);
    printMetrica("direito", resultado, option);

    resultado = calcularMetrica(pTurma, "nutricao", option);
    printMetrica("nutricao", resultado, option);

    return 0;
}