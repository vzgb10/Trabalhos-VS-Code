#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {
    float notas[100] = {8.5, 4.5, 9.0, 7.5, 6.5};
    int nNotas = 5;
    // digite o porteiro do arquivo
    //file * arq
    FILE *arq;

    // abrir arquivo para operações
    arq = fopen("notasWRITE001.txt", "w");

    // gravar dados no arquivo
    for (int pos = 0; pos < nNotas; pos++) {
        //printf("%.2f\n", notas[pos]);
        //ESCREVER NO ARQUIVO O VALOR DA NOTA
        fprintf(arq, "%.2f\n", notas[pos]);
    }
    fprintf(arq, "%.2f\n", notas[nNotas-1]);

    // fechar o arquivo
    fclose(arq);
}