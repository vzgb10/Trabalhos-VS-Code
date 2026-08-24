#include <stdio.h>

int main() {
    int numero, digito;
    int soma = 0; /*questao 10*/

    printf("\nNUMERO INTEIRO: ");
    scanf("%d", &numero);
;

    printf("\nDIGITOS: ");

    while (numero > 0) {
    digito = numero % 10;
    numero = numero / 10;
    soma += digito;
    printf("\n%d", digito);
    }
    printf("\n SOMA DOS DIGITOS: %d", soma);

    return 0;
}