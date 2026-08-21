#include <stdio.h>

int main() {
    int amostra, idade, fabricacao, idadeV, idade10, manutencao, manS, manN, somaI, somaV;
    float mediaI = 0, mediaV = 0, percS = 0, percN = 0, percV = 0;

    printf("\nNUMERO DE AMOSTRAS: ");
    scanf("%d", &amostra);

    for (int x=1; x<=amostra; x++) {
        printf("\nAMOSTRA %d\n", x);
        printf("\nIDADE DO PROPRIETARIO: ");
        scanf("%d", &idade);
        somaI += idade;

        printf("\nANO DE FABRICACAO DO VEICULO: ");
        scanf("%d", &fabricacao);
        idadeV = 2026 - fabricacao;
        somaV += idadeV;
        if (idadeV > 10) {
            idade10++;
        }

        printf("\n1 - SIM \n2 - NAO \nREALIZA MANUTENCAO PREVENTIVA? ");
        scanf("%d", &manutencao);
        if (manutencao == 1) {
            manS++;
        }
        else if (manutencao == 2) {
            manN++;
        }
        else {
            printf("\nRESPOSTA INVALIDA.");
        }
    }
    mediaI = somaI / amostra;
    mediaV = somaV / amostra;
    percS = (manS / amostra) * 100;
    percN = (manN / amostra) * 100;
    percV = (idade10 / amostra) * 100;

    printf("\n*************************************\n");
    printf("\nIDADE MEDIA DOS CONDUTORES: %.1f", mediaI);
    printf("\nIDADE MEDIA DOS VEICULOS:   %.1f", mediaV);
    printf("\nPERCENTUAL QUE REALIZAM MP:     %.1f%%", percS);
    printf("\nPERCENTUAL QUE NAO REALIZAM MP: %.1f%%", percN);
    printf("\nQUANTIDADE DE VEICULOS COM MAIS DE 10 ANOS: %d", idade10);
    printf("\nPERCENTUAL DE VEICULOS COM MAIS DE 10 ANOS: %.1f%%", percV);

    return 0;
}