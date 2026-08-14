#include <stdio.h>

int main() {
    float valortotal, valorcompra, valorparcela;
    int parcelas;
    char refazer = 'S';

    printf("\nValor Total da compra: ");
    scanf("%f", &valorcompra);
    printf("\nQuantidade de Parcelas: ");
    scanf("%d", &parcelas);

    while (refazer == 'S' || refazer == 's')
        if (parcelas == 1) {
            valortotal = valorcompra - (valorcompra * 0.2);
            valorparcela = valortotal;
        }
        else if (parcelas == 2 || parcelas == 3) {
            valortotal = valorcompra + (valorcompra * 0.05);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas >= 4 && parcelas <=7) {
            valortotal = valorcompra + (valorcompra * 0.1);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 8 || parcelas == 9) {
            valortotal = valorcompra + (valorcompra * 0.15);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 10 || parcelas == 11) {
            valortotal = valorcompra + (valorcompra * 0.2);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas >= 12 && parcelas <= 19) {
            valortotal = valorcompra + (valorcompra * 0.25);
            valorparcela = valortotal / parcelas;
        }
        else if (parcelas == 20) {
            valortotal = valorcompra + (valorcompra * 0.3);
            valorparcela = valortotal / parcelas;
        }
        else {
            printf("\nERRO! Nós não aceiamos essa quantidade de parcelas...");
        }

    printf("\n**************************************************\n");
    printf("\nValor da Compra: R$%.2f", valorcompra);
    printf("\nParcelas: %d", parcelas);
    printf("\nValor Parcela: R$%.2f", valorparcela);
    printf("\nValor Total: R$%.2f", valortotal);

    return 0;
}