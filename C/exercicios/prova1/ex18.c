#include <stdio.h>

int main() {
    int bilhete, idade;
    float cbu, distancia, rodado, descontoB, descontoU, custo;
    float total = 0;

    printf("\nDISTANCIA PERCORRIDA EM KM: ");
    scanf("%f", &distancia);
    printf("\nCUSTO POR KM RODADO: ");
    scanf("%f", &rodado);

    cbu = distancia * rodado;

    printf("\nQUANTIDADE DE BILHETES COMPRADOS: ");
    scanf("%d", &bilhete);

    if (bilhete == 1) {
        descontoB = 0;
    }
    else if (bilhete >= 2 && bilhete <= 5) {
        descontoB = 0.05;
    }
    else if (bilhete >= 6 && bilhete <= 10) {
        descontoB = 0.15;
    }
    else if (bilhete >= 11) {
        descontoB = 0.3;
    }
    else {
        printf("\nQUANTIDADE DE BILHETES INVALIDOS.");
        descontoB = 0;
    }

    for (int x=1; x<=bilhete; x++) {
        printf("\nIDADE DA PESSOA %d: ", x);
        scanf("%d", &idade);

        if (idade >= 0 && idade <= 5) {
            descontoU = 0.2;
        }
        else if (idade >= 6 && idade <= 10) {
            descontoU = 0.15;
        }
        else if (idade >= 11 && idade <= 16) {
            descontoU = 0.1;
        }
        else if (idade >= 60) {
            descontoU = 0.3;
        }
        else {
            descontoU = 0;
        }
        printf("\nDESCONTO IDADE DA PESSOA %d: %.2f\n", x, descontoU);

        custo = cbu * (1 - descontoB + descontoU);
        total += custo;
    }
    printf("\n****************************************\n");
    printf("\nCBU: R$%.2f", cbu);
    printf("\nDESCONTO POR BILHETE: %.2f", descontoB);
    printf("\nVALOR TOTAL: R$%.2f", total);

    return 0;
}