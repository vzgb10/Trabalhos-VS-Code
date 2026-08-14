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

        if (parcelas == 1) {
            valortotal = valorcompra - (valorcompra * 0.2);
            valorparcela = valortotal;
        }
        else if (parcelas == 2) {
            valortotal = valorcompra + (valorcompra * 0.05);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 4) {
            valortotal = valorcompra + (valorcompra * 0.1);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 8) {
            valortotal = valorcompra + (valorcompra * 0.15);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 10) {
            valortotal = valorcompra + (valorcompra * 0.2);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 12) {
            valortotal = valorcompra + (valorcompra * 0.25);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 20) {
            valortotal = valorcompra + (valorcompra * 0.3);
            valorparcela = valortotal / parcelas;
        }
        else {
            printf("\nERRO! Nós não aceiamos essa quantidade de parcelas...");
            printf("\nDeseja refazer os calculos? (S/N) ");
            scanf(" %c", &refazer);
            
            if (refazer == 'S' || refazer == 's') {
                continue;
            }
            else {
                break;
            }
        }
    }

    printf("\n**************************************************\n");
    printf("\nValor da Compra: R$%.2f", valorcompra);
    printf("\nParcelas: %d", parcelas);
    printf("\nValor Parcela: R$%.2f", valorparcela);
    printf("\nValor Total: R$%.2f", valortotal);

    return 0;
}