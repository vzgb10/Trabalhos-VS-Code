#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct DADOSALUNOS {
    char nomeAluno[200];
    int codigoCurso;
    float cr;
    int semestreCorrente;
    int disciplinasCursadas;
    int disciplinasDP;
};

int main() {
    //DECLARAR UMA VARIAVEL DO TIPO DADOSALUNOS
    struct DADOSALUNOS aluno;
    
    //COMO ATRIBUIR VALORES
    strcpy(aluno.nomeAluno, "Joao da Silva");
    aluno.codigoCurso = 123;
    aluno.cr = 0.45;
    aluno.semestreCorrente = 2;
    aluno.disciplinasCursadas = 11;
    aluno.disciplinasDP = 3;

    //COMO IMPRIMIR OS VALORES
    printf("\nNome do Aluno:             %-20s", aluno.nomeAluno);
    printf("\nCodigo do Curso:           %4d", aluno.codigoCurso);
    printf("\nCoeficiente de Rendimento: %4.2f", aluno.cr);
    printf("\nSemestre Corrente:         %4d", aluno.semestreCorrente);
    printf("\nDisciplinas Cursadas:      %4d", aluno.disciplinasCursadas);
    printf("\nDisciplinas com DP:        %4d", aluno.disciplinasDP);


    printf("\NOBRIGADO POR UTILIZAR O SOTFWARE TABAJARA");

    return 0;
}