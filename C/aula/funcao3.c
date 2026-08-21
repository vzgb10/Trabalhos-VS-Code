#include <stdio.h>

int semana(int dia, int mes, int ano) {
    int resto;
    int A = ((12-mes) / 10);
    int B = ano - A;
    int C = mes + (12 * A);
    int D = (B / 100);
    int E = (D/4);
    int F = 2 - D + E;
    int G = (365.25 * B);
    int H = (30.6001 * (C + 1));
    int I = ((F+G) + (H + dia) + 5);
    resto = I %7;
}

void dia(int numero) {

    switch (numero) {
    case 0:
        printf("SABADO"); 
        break;
    case 1:
        printf("DOMINGO"); 
        break;
    case 2:
        printf("SEGUNDA"); 
        break;
    case 3:
        printf("TERCA"); 
        break;
    case 4:
        printf("QUARTA"); 
        break;
    case 5:
        printf("QUINTA"); 
        break;
    case 6:
        printf("SEXTA"); 
        break;
    }
}



int main() {
    int dia, mes, ano;
    printf("\nDIGITE O DIA: ");
    scanf("%d", &dia);
    printf("\nDIGITE O MES: ");
    scanf("%d", &mes);
    printf("\nDIGITE UM ANO: ");
    scanf("%d", &ano);

    printf("\nO DIA DA SEMANA E: ");
    dia(semana(dia, mes ano));
}