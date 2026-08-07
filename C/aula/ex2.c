#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void main() {
    rand();
    int numerocomput;
    int palpite;

    srand(time(NULL));
    numerocomput = rand()%100;

    printf("\nDIGITE UM NUMERO: ");
    scanf("%d", &palpite);

    if (palpite > numerocomput) {
        printf("\nSEU NUMERO É MAIOR");
    }
    if (palpite < numerocomput) {
        printf("\nSEU NUMERO É MENOR");
    }
    if (palpite == numerocomput) {
        printf("\nPARABENS VOCE ACERTOU O NUMERO");
    }
    printf("\nNUMERO ESCOLHIDO: %d", numerocomput);
}