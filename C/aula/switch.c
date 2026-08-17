#include <stdio.h>

int main() {
    int parcela;
    float desconto;

    parcela = 8;

    switch(parcela) {
        case 2:
            desconto = 20;
            break;
        case 4:
            desconto = 15;
            break;
        case 8:
            desconto = 5;
            break;
        case 10:
            desconto = 1;
            break;
    }
}

// case = if/elif
// default = else