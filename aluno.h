#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno TAluno;

typedef struct turma TTurma;

// Manter como especificado
void lerInfos(int*qnt, char*option);

// Manter como especificado
void alocaAluno(TAluno**pALuno);

// Manter como especificado
void alocaTurma(TTurma**pTurma, int qnt);

// Manter como especificado
void desalocaAluno(TAluno**pAluno);

// Manter como especificado
void desalocaTurma(TTurma**pTurma);
// Manter como especificado
void lerTurma(TTurma*pTurma);

// Manter como especificado
float calcularMetrica(TTurma*pTurma, char*curso, char option);

// Manter como especificado
void printMetrica(char* curso, float metrica, char option);

#endif // ALUNO_H