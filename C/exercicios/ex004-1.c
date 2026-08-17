#include <stdio.h>

int main() {
    float valortotal, valorcompra, valorparcela;
    int parcelas;
    char refazer = 'S';

    while (refazer == 'S' || refazer == 's') {
        printf("\nValor Total da compra: ");
        scanf("%f", &valorcompra);
        printf("\nQuantidade de Parcelas: ");
        scanf("%d", &parcelas);

        switch(parcelas) {
            case 1:
                valortotal = valorcompra - (valorcompra * 0.2);
                valorparcela = valortotal;
                refazer = 'n';
                break;
            case 2:
                valortotal = valorcompra + (valorcompra * 0.05);
                valorparcela = valortotal / parcelas;
                refazer = 'n';
                break;
            case 4:
                valortotal = valorcompra + (valorcompra * 0.1);
                valorparcela = valortotal / parcelas;
                refazer = 'n';
                break;
            case 8:
                valortotal = valorcompra + (valorcompra * 0.15);
                valorparcela = valortotal / parcelas;
                refazer = 'n';
                break;
            case 10:
                valortotal = valorcompra + (valorcompra * 0.2);
                valorparcela = valortotal / parcelas;
                refazer = 'n';
                break;
            case 12:
                valortotal = valorcompra + (valorcompra * 0.25);
                valorparcela = valortotal / parcelas;
                refazer = 'n';
                break;
            case 20:
                valortotal = valorcompra + (valorcompra * 0.3);
                valorparcela = valortotal / parcelas;
                refazer = 'n';
                break;
            default:
            printf("\nERRO! Nós não aceiamos essa quantidade de parcelas...");
            printf("\nDeseja refazer os calculos? (S/N) ");
            scanf(" %c", &refazer);
            continue;
        }
    }
    printf("\n**************************************************\n");
    printf("\nValor da Compra: R$%.2f", valorcompra);
    printf("\nParcelas: %d", parcelas);
    printf("\nValor Parcela: R$%.2f", valorparcela);
    printf("\nValor Total: R$%.2f", valortotal);

    return 0;
}