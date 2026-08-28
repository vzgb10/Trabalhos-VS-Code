#include <stdio.h>

int main() {
    int notas[10] = {7,8,2,3,10};
    int nvalores = 5;
    float media;
    float soma = 0;

    for(int pos = 0; pos < nvalores; pos++) {
        printf("\n[%d]: %d", pos, notas[pos]);
        soma += notas[pos];
    }
    media = soma / nvalores;
    printf("\nMedia: %.2f", media);
    return 0;
}