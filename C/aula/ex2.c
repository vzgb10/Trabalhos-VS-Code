#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    rand();
    int numerocomput;
    int palpite;
    int tentativas = 0;

    srand(time(NULL));
    numerocomput = rand()%100;

    printf("\nDIGITE UM NUMERO: ");
    scanf("%d", &palpite);
    tentativas++;

    while (palpite != numerocomput) {

        if (palpite > numerocomput) {
            printf("\nSEU NUMERO É MAIOR");
        }
        if (palpite < numerocomput) {
            printf("\nSEU NUMERO É MENOR");
        }
        
        printf("\nDIGITE UM NUMERO: ");
        scanf("%d", &palpite);
        tentativas++;
    }
    
    printf("\nPARABENS VOCE ACERTOU O NUMERO!");
    printf("\nNUMERO ESCOLHIDO: %d", numerocomput);
    printf("\nVOCE ACERTOU EM %d TENTATIVAS", tentativas);
    return 0;
}