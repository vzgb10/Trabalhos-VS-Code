#include <stdio.h>

int main() {
    int numero, digito, soma;
    int cont = 0;

    printf("\nDIGITE O NUMERO DESEJADO: ");
    scanf("%d", &numero);
    do {
        printf("\nNUMERO EM ANALISE: %d", numero);
        soma = 0;
        do {
            digito = numero %10;
            soma += digito;
            numero = numero /10;
            printf("\n  NUMERO: %d ---  SOMA: %d", numero, soma);
        }
        while (numero != 0);
            cont += 1;
            printf("\n  NUMERO: %d --- DIGITO: %d --- SOMA: %d", numero, digito, soma);
            numero = soma;
    }
    while (numero != 1 && cont<10);

    if (numero == 1) {
        printf("\nESSE NUMERO E FELIZ!");
    }
    else {
        printf("\nESSE NUMERO E TRISTE...");
    }

    return 0;
}