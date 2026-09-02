#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main() {

    FILE *arq;

    char nomealuno[100], buffer[1000], nomeProcurado[100];
    int idadealuno, auxtam;

    printf("\nDIGITAR NOME PROCURADO: ");
    fgets(nomeProcurado, 100, stdin);
    auxtam=strlen(nomeProcurado);
    nomeProcurado[auxtam-1]='\0'; //Remover o caractere de nova linha
    printf("\nNOME PROCUDARO: %s", nomeProcurado);

    //abrir arquivo para operações
    arq=fopen("ALUNOS.txt", "rt");

    //ler dados do arquivo
    while(!feof(arq)) {
        //ler nome
        fgets(buffer,100,arq);
        int auxtam=strlen(buffer);
        buffer[auxtam-1]='\0'; // Remover o caractere de nova linha
        strcpy(nomealuno,buffer);
        //ler idade
        fgets(buffer,100,arq);
        idadealuno=atoi(buffer);

        if (strcmp(nomeProcurado,nomealuno) == 0) {
            printf("\nENCONTROU: %s\tIDADE: %d", nomealuno, idadealuno);
        }
    }
    fclose(arq);
}
