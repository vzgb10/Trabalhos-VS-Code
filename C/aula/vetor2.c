#include <stdio.h>

int main() {
    float media = 0;
    float soma = 0;
    int notas[10][20] =  {
        {7,4,3},
        {5,2,1},
        {9,10,8},
        {6,5,4},
        };
    

    for(int lin = 0; lin < 4; lin++) {
        printf("\nLINHA [%2d]: ", lin);
        for(int col = 0; col < 3; col++) {
            printf("%4d",notas[lin][col]);
            soma+=notas[lin][col];
        }
        media = soma / 3;
        printf("\nMedia: %7.2f", media);
    }
    return 0;
}