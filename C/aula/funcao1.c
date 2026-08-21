#include <stdio.h>

float media(float nota1,float nota2) {
    float soma, auxmedia;
    soma = nota1 + nota2;
    auxmedia = soma / 2;
    return auxmedia;
}

int main() {
    float resultado;
    resultado = media(9,7);
    printf("\nMEDIA: %7.2f", resultado);
}