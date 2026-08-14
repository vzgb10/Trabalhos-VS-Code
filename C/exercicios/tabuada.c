#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    rand();
    int v1, v2, resposta, resultado;
    int acertos = 0;
    int erros = 0;
    int tentativas = 0;
    char continuar = 'S';

    srand(time(NULL));

    while (continuar == 'S' || continuar == 's') {
        v1 = rand()%10;
        v2 = rand()%10;

        resultado = v1 * v2;
        for (int x = 0; x <= v1; x++) {
            printf("#");
        }
        printf(" X ");

        for (int x = 0; x <= v2; x++) {
            printf("$");
        }
        scanf("%d", &resposta);

        tentativas ++;

        if (resposta == resultado) {
            printf("\nParabéns você acertou");
        }
        else {
            printf("\nPutz... Você errou");
            printf("\nQuer tentar novamente? ");
            scanf("%s", &)

        }

    }


}