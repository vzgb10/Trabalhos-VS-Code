#include <stdio.h>

int main() {
    int numero, digito, par = 0, impar = 0, produto = 1;

    printf("\nNUMERO INTEIRO: ");
    scanf("%d", &numero);
;

    printf("\nDIGITOS: ");

    while (numero > 0) {
        digito = numero % 10;
        numero = numero / 10;
        produto *= digito;
        printf("\n%d", digito);
        if (digito %2 == 0) {
            par++;
        }
        else {
            impar++;
        }
    }
    printf("\n PRODUTO DOS DIGITOS: %d", produto);
    printf("\nDIGITOS PARES: %d", par);
    printf("\nDIGITOS IMPARES: %d", impar);

    return 0;
}