#include <stdio.h>
#include <string.h>

int numerovogais(char *c) {
    int pos = 0, vogal = 0;
    while(c[pos]!='\0') {
        if (c[pos]=='A'||c[pos]=='E'||c[pos]=='I'||c[pos]=='O'||c[pos]=='U') {
            vogal++;
        }
        pos++;
    }
    return vogal;
}


int main() {
    char palavra[100] = "PINDAMONHAGABA";
    int nvogais = numerovogais(palavra);
    
    printf("\nA PALAVRA  '%s' TEM %d VOGAIS", palavra, nvogais);

    return 0;
}