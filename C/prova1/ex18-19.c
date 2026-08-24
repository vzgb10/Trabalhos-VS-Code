#include <stdio.h>

int main() {
    int bilhete, idade, assento;
    float cbu, distancia, rodado, descontoB, descontoU, acrescimo, custo;
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

        do { /*exercicio 19*/
            printf("\n1 - BASICO \n2 - PLANETARIO \n3 - ESTELAR \n4 - GALATICO \nQUAL O ASSENTO ESCOLHIDO? ");
            scanf("%d", &assento);
            switch (assento) {
            case 1:
                printf("\nASSENTO BASICO");
                acrescimo = 0;
                break;
            case 2:
                printf("\nASSENTO PLANETARIO");
                acrescimo = 1.3;
                break;
            case 3:
                printf("\nASSENTO ESTELAR");
                acrescimo = 1.6;
                break;
            case 4:
                printf("\nASSENTO GALATICO");
                acrescimo = 2;
                break;
            default:
                printf("\nERRO...");
                printf("\nASSENTO NAO IDENTIFICADO.");
                break;
            }
        }
        while (assento < 1 || assento > 4);

        custo = cbu * (1 - descontoB - descontoU) * (1 + acrescimo);
        total += custo;
    }
    
    printf("\n****************************************\n");
    printf("\nCBU:                   R$%.2f", cbu);
    printf("\nDESCONTO POR BILHETE:  %.2f", descontoB);
    printf("\nACRESCIMO POR BILHETE: %.2f", acrescimo);
    printf("\nVALOR TOTAL:           R$%.2f", total);

    return 0;
}