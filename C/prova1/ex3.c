#include <stdio.h>

int main() {
    int bilhete, idade, filhos, escolaridade, somaD;
    float custo, bruto, descontoI, descontoF, descontoE, total, dinheiro, troco;

    printf("\nQUANTIDADE DE BILHETES COMPRADOS: ");
    scanf("%d", &bilhete);
    printf("\nCUSTO DO BILHETE: ");
    scanf("%f", &custo);
    bruto = custo * bilhete;

    printf("\nIDADE DO COMPRADOR: ");
    scanf("%d", &idade);
    if (idade < 16) {
        descontoI = 0.1;
    }
    else if (idade > 60) {
        descontoI = 0.5;
    }
    else {
        descontoI = 0;
        printf("\nESSA IDADE NAO POSSUI DESCONTO.");
    }

    printf("\nNUMERO DE FILHOS: ");
    scanf("%d", &filhos);
    descontoF = filhos * 0.1;

    printf("\nQUANTIDADE DE ANOS DE ESCOLIRADADE: ");
    scanf("%d", &escolaridade);
    descontoE = escolaridade * 0.01;

    total = bruto * (1 - descontoI - descontoF - descontoE);
    somaD = (descontoE + descontoF + descontoI) * 100;

    printf("\nVALOR TOTAL: R$%.2f", total);

    while (1) {
        printf("\nQUANTO DESEJA ENTREGAR AO CAIXA?  R$");
        scanf("%f", &dinheiro);
        if (dinheiro >= total) {
            troco = dinheiro - total;
            break;
        }
        printf("\nERRO...");
        printf("\nDIGITE UM VALOR MAIOR OU IGUAL AO TOTAL.\n");
    }

    printf("\n********************************************\n");
    printf("\nCUSTO DO BILHETE:  R$%.2f", custo);
    printf("\nVALOR BRUTO:       R$%.2f", bruto);
    printf("\nDESCONTO APLICADO: %d%%", somaD);
    printf("\nVALOR TOTAL:       R$%.2f", total);
    printf("\nVALOR PAGO:        $%.2f", dinheiro);
    printf("\nTROCO:             R$%.2f", troco);

    return 0;
}