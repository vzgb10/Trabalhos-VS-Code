#include <stdio.h>

int main() {

    int alunos, idade;
    int velho = -999;
    int novo = 999;
    int soma = 0;
    int x = 1;
    int id1 = 0;
    int id2 = 0;
    int id3 = 0;
    int id4 = 0;
    int id5 = 0;
    float media = 0;

    printf("\nQuantidade de alunos: ");
    scanf("%d", &alunos);

    while (x<=alunos) {
        printf("\n--- ALUNO %d ---\n", x);
        printf("\nIdade do aluno %d: ", x);
        scanf("%d", &idade);
        soma += idade;

        if (idade > velho) {
            velho = idade;
        }
        else if (idade < novo) {
            novo = idade;
        }
        if (idade < 18) {
            id1 ++;
        }
        else if (idade >= 18 && idade < 20) {
            id2 ++;
        }
        else if (idade >= 20 && idade < 25) {
            id3 ++;
        }
        else if (idade >= 25 && idade < 30) {
            id4 ++;
        }
        else {
            id5 ++;
        }
        x++;
    }
    
    media = (float)soma / alunos;

    printf("\n*********************************************\n");
    printf("\nMédia das idades: %.2f anos", media);
    printf("\nMais velho:  %d anos", velho);
    printf("\nMais novo: %d anos\n", novo);
    printf("\nMenor de 18 anos: %d", id1);
    printf("\n18 a 19 anos: %d", id2);
    printf("\nEntre 20 a 24 anos: %d", id3);
    printf("\nEntre 25 a 29 anos: %d", id4);
    printf("\nMaior que 30 anos: %d", id5);

    return 0;
}