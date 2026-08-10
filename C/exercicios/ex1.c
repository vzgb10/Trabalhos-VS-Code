#include <stdio.h>

int main()
{
    float valor_inicial;
    float aporte_mensal;
    float taxa;
    float total_aplicado;
    int tempo;
    int x = 0;
    int contmeses = 0;
    float ano = 0;
    float valor_aposentadoria;
    
    printf("\nDigite o valor inicial: ");
    scanf("%f",&valor_inicial);
    printf("\nDigite o aporte mensal: ");
    scanf("%f",&aporte_mensal);
    printf("\nDigite a taxa mensal: ");
    scanf("%f",&taxa);
    printf("\nTempo em meses que irá depositar: ");
    scanf("%d",&tempo);
    
    for (x; x <= tempo; x++) {
        printf("\nMês: %d --> Valor: R$%.2f", x, valor_inicial);
        valor_inicial = valor_inicial + (valor_inicial*taxa/100) + aporte_mensal;
        total_aplicado = valor_inicial;
    }
    
    printf("\nDigite o valor da sua aposentadoria: ");
    scanf("%f",&valor_aposentadoria);
    
    while ((total_aplicado)&&(contmeses<1200)) {
        total_aplicado = total_aplicado + (total_aplicado*taxa)/100 - valor_aposentadoria;
        contmeses++;
    }
    ano = contmeses/12;
    
    printf("\nVocê poderá viver por %.1f anos com R$%.2f de renda por mês", ano, total_aplicado);
    
    return 0;
}