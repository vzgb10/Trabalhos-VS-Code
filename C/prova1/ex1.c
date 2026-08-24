#include <stdio.h>

int main () {
    int eleitores = 0, voto, cand1 = 0, cand2 = 0, cand3 = 0, vencedor = 1, maior = cand1;
    char continuar = 'S', nome[10];

    while (continuar == 'S' || continuar == 's') {
        printf("\n NOME DO ELEITOR: ");
        scanf("%s", &nome);
        printf("\n1 - CANDIDATO 1 \n2 - CANDIDATO 2 \n3 - CANDIDATO 3 \n QUAL O SEU VOTO? ");
        scanf("%d", &voto);
        eleitores++;

        switch (voto) {
        case 1:
            cand1++;
            break;
        case 2:
            cand2++;
            break;
        case 3:
            cand3++;
            break;
        default:
            printf("\nCANDIDATO NAO IDENTIFICADO.");
            break;
        }
        printf("\nDESEJA CONTINUAR A VOTACAO? (S/N) ");
        scanf(" %c", &continuar);
    }
    if (cand2 > maior) {
    maior = cand2;
    vencedor = 2;
    }
    if (cand3 > maior) {
    maior = cand3;
    vencedor = 3;
    }

    printf("\n  *** RESULTADO ***");
    printf("\nELEITORES QUE VOTARAM: %d", eleitores);
    printf("\nCANDIDATO 1: %d VOTOS", cand1);
    printf("\nCANDIDATO 2: %d VOTOS", cand2);
    printf("\nCANDIDATO 3: %d VOTOS", cand3);
    printf("\nVENCEDOR: %d", vencedor);

    return 0;
}