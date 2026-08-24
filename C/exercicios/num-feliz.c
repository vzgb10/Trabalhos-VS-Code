#include <stdio.h>

int main() {
    int numero, original = 0, digito = 0, cont = 0;

    printf("\nDIGITE O NUMERO ESCOLHIDO: ");
    scanf("%d", &numero);
    original = numero;

    do {
        int soma = 0;

        while (numero > 0) {
            digito = numero % 10;
            soma += digito * digito;
            numero = numero / 10;
        }

        printf("Soma = %d\n", soma);

        numero = soma;
        cont++;

    } while (numero != 1 && cont < 50);

    if (numero == 1) {
        printf("O NUMERO %d E FELIZ!", original);
    }
    else {
        printf("\nO NUMERO %d E TRISTE", original);
    }
    return 0;
}