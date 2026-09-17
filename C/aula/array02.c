#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char numero[10][20];
char buffer[1000];

int main() {
    FILE *arq;
    int x;
    int linNumero = 0;

    arq = fopen("IMAGEM001.txt","r");

    while(!feof(arq)) {

        strcpy (buffer,"");
        //ler linha do arquivo enquanto
        //o caracter da posicao [0] de buffer
        //for diferente de '$'
        while (buffer[0]!='$') {
            //efetuar leitura de uma linha do arquivo
            fgets(buffer, 100, arq);

            //verificar se o caracter na posicao [0]
            //de buffer e diferente de '$'
            //se for diferente, armazenar no array numero
            if (buffer[0]!='$') {
                //remover \n
                buffer[strlen(buffer)-1]='\0';

                //copiar buffer para array numero
                //na linha linNumero
                strcpy(numero[linNumero], buffer);

                //incrementar linha para
                linNumero++;
            }
        }
        //ler ultima lihna do arquivo indicando fim do arquivo
        //"fgets(buffer, 100, arq);" --- essa linha nao e necessaria...
    }
    //imprimer linhas
    printf("\n\n");

    for (int x = 0; x < linNumero; x++) {
        printf("%s\n", numero[x]);
    }

    //filtrar linhas
    printf("\n\n");
    //selecionar a linha
    for (int lin=0; linNumero; lin++) {
        //selecionar a coluna na linha
        for (int col = 0; col < strlen(numero[lin]); col++) {
            if (numero[lin][col]=='x')
            printf("#");
            else
            printf((" "));
        }
        printf("\n");
    }


    fclose(arq);
}