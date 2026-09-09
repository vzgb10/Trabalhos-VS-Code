#include <stdio.h>
#include <stdlib.h>
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
    struct DADOSALUNOS aluno;

    int nAlunos;

    // Abrir arquivo para escrita
    FILE *arquivo = fopen("estrutura.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    printf("\nNUMERO DE ALUNOS PARA CADASTRO: ");
    scanf("%d", &nAlunos);

    for (int pos = 1; pos <= nAlunos; pos++) {

        printf("\n--- CADASTRO DO ALUNO %d ---\n", pos);

        printf("Nome do Aluno: ");
        scanf(" %[^\n]", aluno.nomeAluno);

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

        // Gravar no arquivo
        fprintf(arquivo, "%s\n", aluno.nomeAluno);
        fprintf(arquivo, "%d\n", aluno.codigoCurso);
        fprintf(arquivo, "%.2f\n", aluno.cr);
        fprintf(arquivo, "%d\n", aluno.semestreCorrente);
        fprintf(arquivo, "%d\n", aluno.disciplinasCursadas);
        fprintf(arquivo, "%d\n", aluno.disciplinasDP);
        fprintf(arquivo, "--------------------\n");
    }

    fclose(arquivo);

    printf("\nDados salvos com sucesso!\n");

    return 0;
}
