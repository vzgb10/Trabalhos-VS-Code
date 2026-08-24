#include <stdio.h>

int main() {
    int meses, montadora = 6000, concorrente = 80000, mesesN = 0;
    int previsaoM = 0, previsaoC = 0;

    previsaoM = montadora;
    previsaoC = concorrente;

    printf("\nQUANIDADE DE MESES PARA A PREVISAO: ");
    scanf("%d", &meses);

    for (int x = 0; x < meses; x++) {
    previsaoM *= 1.05;
    previsaoC *= 0.98;
    }

    printf("\nPREVISAO DA MONTADORA:   %d VEICULOS VENDIDOS EM %d MESES.", previsaoM, meses);
    printf("\nPREVISAO DA CONCORRENTE: %d VEICULOS VENDIDOS EM %d MESES.", previsaoC, meses);

    
    while (previsaoM < previsaoC) {
        previsaoM *= 1.05;
        previsaoC *= (1 - 0.02);
        mesesN++;
    }
    
    if (mesesN == 0) {
        printf("\nPARABENS! VOCE ULTRAPASSOU O CONCORRENTE!");
    }
    else {
        
        printf("\nFALTAM %d MESES PARA ULTRAPASSAR O CONCORRENTE.", mesesN);
    }
    return 0;
}