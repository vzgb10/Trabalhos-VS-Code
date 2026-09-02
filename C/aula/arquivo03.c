#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {

    FILE *arq;

    char nomealuno[100], buffer[1000];
    float soma, media;
    int idadealuno, nalunos;
    arq=fopen("ALUNOS.txt", "rt");

    printf("\nDIGITE QUANTOS ALUNOS DESEJA CADASTRAR: ", nalunos);
    scanf("%d", &nalunos);

    for(int i=0; i<nalunos; i++) {
        printf("\nDIGITE O NOME DO ALUNO: ");
        scanf("%s", nomealuno);
        printf("\nDIGITE A IDADE DO ALUNO: ");
        scanf("%d", &idadealuno);

        fprintf(arq, "%s\t%d\n", nomealuno, idadealuno);

        if (i < nalunos - 1) {
            fprintf(arq, "\n");
        }
    }
    fclose(arq);
}