#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char numero[10][20]
char buffer[1000]

int main() {
    FILE *arq;
    int x;

    arq = fopen(IMAGEM001.txt,"r")

    strcpy (buffer,"guarany");

    //ler os dados -linha por linha
    while (buffer[0]!='9') {
        //ler uma linha
        fgets(buffer, 300, arq);

        //substituir o /n por /0
        buffer[strlen(buffer)-1]='\0'; //strlen(buffer) = tamanho do buffer n# caracteres

        if (buffer[0]!='$') {
            //armazenar buffer em numero-linha por linha
            strcpy(numero[nlinhas], buffer);
            nlinhas++
        }
    }
    fclose(arq);
}