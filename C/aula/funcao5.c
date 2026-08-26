#include <stdio.h>
#include <string.h>

int numerocaracteres(char *c) {
    int pos = 0;
    while(c[pos]!='\0') {
        pos++;
    }
    return pos;
}


int main() {
    char palavra[100] = "PINDAMONHAGABA";
    int ncaracteres = numerocaracteres(palavra);
    
    printf("\nA PALAVRA  '%s' TEM %d CARACTERES", palavra, ncaracteres);

    return 0;
}