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

    int nAlunos;
    printf("\nNUMERO DE ALUNOS PARA CADASTRO: ");
    scanf("%d", &nAlunos);

    for (int pos = 1; pos < nAlunos; pos++) {
        printf("\n---CADASTRO DO ALUNO %d---", pos);
        printf("\nNome do Aluno: ");
        scanf(" %[^\n]s", aluno.nomeAluno);

        printf("Codigo do Curso: ");
        scanf("%d", &aluno.codigoCurso);

        printf("Coeficiente de Rendimento: ");
        scanf("%f", &aluno.cr);

        printf("Semestre Corrente: ");
        scanf("%d", &aluno.semestreCorrente);

        printf("Disciplinas Cursadas: ");
        scanf("%d", &aluno.disciplinasCursadas);

        printf("Disciplinas com DP: ");
        scanf("%d", &aluno.disciplinasDP);

        //COMO IMPRIMIR OS VALORES
        printf("\nNome do Aluno:             %-20s", aluno.nomeAluno);
        printf("\nCodigo do Curso:           %4d", aluno.codigoCurso);
        printf("\nCoeficiente de Rendimento: %4.2f", aluno.cr);
        printf("\nSemestre Corrente:         %4d", aluno.semestreCorrente);
        printf("\nDisciplinas Cursadas:      %4d", aluno.disciplinasCursadas);
        printf("\nDisciplinas com DP:        %4d", aluno.disciplinasDP);
    }
    
    printf("\NOBRIGADO POR UTILIZAR O SOTFWARE TABAJARA");

    return 0;
}