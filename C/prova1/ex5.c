# include <stdio.h>

int main() {
    int dia, mes, ano, resto;

    printf("\nDIGITE O DIA: ");
    scanf("%d", &dia);
    printf("\nDIGITE O MES: ");
    scanf("%d", &mes);
    printf("\nDIGITE UM ANO: ");
    scanf("%d", &ano);

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

    switch (resto)
    {
    case 0:
        printf("\nESSE DIA E SABADO!"); 
        break;
    case 1:
        printf("\nESSE DIA E DOMINGO!"); 
        break;
    case 2:
        printf("\nESSE DIA E SEGUNDA!"); 
        break;
    case 3:
        printf("\nESSE DIA E TERCA!"); 
        break;
    case 4:
        printf("\nESSE DIA E QUARTA!"); 
        break;
    case 5:
        printf("\nESSE DIA E QUINTA!"); 
        break;
    case 6:
        printf("\nESSE DIA E SEXTA!"); 
        break;
    }
}