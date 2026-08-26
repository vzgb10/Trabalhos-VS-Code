#include <stdio.h>

int contnumero(int numero) {
    int pos = 0;
    int digito = numero;

    do {
        digito = digito / 10;
        pos++;
    } while (digito != 0);

    return pos;
}

int main() {
    int numero = 12345;
    int digitos = contnumero(numero);

    printf("Quantidade de digitos: %d\n", digitos);

    return 0;
}