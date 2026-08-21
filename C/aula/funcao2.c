#include <stdio.h>

int digitos(int numero) {
    int digito, cont = 0;
    do {
        digito = numero % 10;
        cont++;
    } while (numero>0);
    return cont;
}

int soma(int numero) {
    int digito, soma = 0;
    do {
        digito = numero % 10;
        soma += digito;
        numero = numero / 10;
    } while (numero>0);
    return soma;
}

int produto(int numero) {
    int digito, produto = 1;
    do {
        digito = numero % 10;
        produto *= digito;
        numero = numero / 10;
    } while (numero>0);
    return produto;
}

int main() {
    int resultado;
    resultado = produto(123456);
    printf("\nDIGITOS: %d", resultado);
    return 0;
}