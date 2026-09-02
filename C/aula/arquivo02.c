#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {
    int idade[100];
    int nidade = 0;

    printf("\nDIGITAR O NUMERO DE CADASTROS: ");
    scanf("%d", &nidade);
    
    for (int i = 0; i < nidade; i++) {
        printf("Digite a idade[%d+1]: ", i);
        scanf("%f", &idade[i]);

        FILE *arq;
        arq = fopen("idadesWRITE001.txt", "w");

        for (int pos = 0; pos < nidade; pos++) {
            fprintf(arq, "%.2f\n", idade[pos]);
        }
        fprintf(arq, "%.2f\n", idade[nidade-1]);

        fclose(arq);
    }
}