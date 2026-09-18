#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct dados {
    int id;
    int tipo;
    char label[30];
    char descricao[1000];
    int codigo;
    float valor;
};

struct dados vetor[100];

int cont = 0;

void lancamento() {
    struct dados lancamento;

    lancamento.id = cont + 1;
    printf("\nO ID da Operacao e %d", lancamento.id);

    printf("\nTipo de Operacao: \t0 - Retirada / Pagamento \t1 - Deposito / Entrada de Valores\n");
    scanf("%d", &lancamento.tipo);
    if(lancamento.tipo == 0 || lancamento.tipo == 1) {
        printf("\nOpcao %d selecionada com sucesso!", lancamento.tipo);
    }
    else {
        printf("\nEssa opcao nao esta disponivel!");
        return;
    }

    printf("\n\nLabel da Operacao: ");
    scanf(" %[^\n]", lancamento.label);

    printf("\n\nDescricao da Operacao: ");
    scanf(" %[^\n]", lancamento.descricao);

    printf("\n\nCodigo da Operacao: \t0 - Despesas obrigatorias \t1 - Depositos \t2 - Pagamentos por Despesas nao Obrigatorias");
    scanf("%d", &lancamento.codigo);
    if(lancamento.codigo == 0 || lancamento.codigo == 1 || lancamento.codigo == 2) {
        printf("\nOpcao %d selecionada com sucesso!", lancamento.codigo);
    }
    else {
        printf("\nEssa opcao nao esta disponivel!");
        return;
    }

    printf("Valor da Operacao: ");
    scanf("%.2f", lancamento.valor);

    vetor[cont] = lancamento;
    cont++;
}

void consultarSaldo() {
    struct dados consultarSaldo;
    float saldo = 0;

    for(consultarSaldo.id == 0; consultarSaldo.id < cont; consultarSaldo.id++) {
        if(vetor[consultarSaldo.id].tipo == 1) {
            saldo += vetor[consultarSaldo.id].valor;
        }
        else if(vetor[consultarSaldo.id].tipo == 0) {
            saldo -= vetor[consultarSaldo.id].valor;
        }
        else {
            printf("Não foi encontrado nada no arquivo...");
        }
    }
    printf("\nO saldo atual e de: R$%.2f.", saldo);
}

void listarTodas() {
    printf("\n======= LISTAGEM DE TODAS AS OPERACOES =======");
    for(int x = 0; x < cont; x++) {
        printf("\nID:        %d", vetor[x].id);
        printf("\nTipo:      %d", vetor[x].tipo);
        printf("\nLabel:     %s", vetor[x].label);
        printf("\nDescricao: %s", vetor[x].descricao);
        printf("\nCodigo:    %d", vetor[x].codigo);
        printf("\nValor:     R$%.2f", vetor[x].valor);
        printf("\n---------------------------------");
    }
}

void listarTipo() {
    int tipoConsulta;
    int encontrou = 0;

    printf("Digite o tipo de operacao para listar: \t1 - Deposito ou retirada de valores \t0 - Retirada ou pagamento  \n");
    scanf("%d", &tipoConsulta);

    printf("\n======= LISTAGEM DE OPERACOES PELO TIPO =======");
    for(int x = 0; x < cont; x++) {
        if(vetor[x].tipo == tipoConsulta) {
            printf("\nID:        %d", vetor[x].id);
            printf("\nTipo:      %d", vetor[x].tipo);
            printf("\nLabel:     %s", vetor[x].label);
            printf("\nDescricao: %s", vetor[x].descricao);
            printf("\nCodigo:    %d", vetor[x].codigo);
            printf("\nValor:     R$%.2f", vetor[x].valor);
            printf("\n---------------------------------");
            encontrou = 1;
        }
    }
    if(encontrou == 0) {
        printf("Nenhuma operacao encontrada para o tipo '%d'.\n", tipoConsulta);
    }
}

void listarCodigo() {
    int codigoConsulta;
    int encontrou = 0;

    printf("Digite o tipo de operacao para listar: \t0 - Despesas obrigatorias \t1 - Depositos \t2 - Pagamentos por Despesas nao Obrigatorias");
    scanf("%d", &codigoConsulta);

        printf("\n======= LISTAGEM DE OPERACOES PELO CODIGO =======");
    for(int x = 0; x < cont; x++) {
        if(vetor[x].tipo == codigoConsulta) {
            printf("\nID:        %d", vetor[x].id);
            printf("\nTipo:      %d", vetor[x].tipo);
            printf("\nLabel:     %s", vetor[x].label);
            printf("\nDescricao: %s", vetor[x].descricao);
            printf("\nCodigo:    %d", vetor[x].codigo);
            printf("\nValor:     R$%.2f", vetor[x].valor);
            printf("\n---------------------------------");
            encontrou = 1;
        }
    }
    if(encontrou == 0) {
        printf("Nenhuma operacao encontrada para o tipo '%d'.\n", codigoConsulta);
    }
}

void consultarLabel() {
    char labelConsulta[30];
    int encontrou = 0;

    printf("\nDigite o Label que dejesa consultar: ");
    scanf(" %[^\n]", labelConsulta);

    printf("\n=========== CONSULTA DE OPERACOES POR LABEL ===========\n");
    for(int x = 0; x < cont; x++) {
        if(strcmp(vetor[x].label, labelConsulta) == 0) {
            printf("ID:        %d\n", vetor[x].id);
            printf("Tipo:      %d\n", vetor[x].tipo);
            printf("Label:     %s\n", vetor[x].label);
            printf("Descricao: %s\n", vetor[x].descricao);
            printf("Codigo:    %d\n", vetor[x].codigo);
            printf("Valor:     %.2f\n", vetor[x].valor);
            printf("--------------------\n");
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhuma operacao encontrada com o label '%s'.\n", labelConsulta);
    }
}

void alterarOperacao() {
    int idOperacao;
    int encontrou = 0;

    printf("Digite o ID da operacao que deseja alterar: ");
    scanf("%d", &idOperacao);

    for(int x = 0; x < cont; x++) {
        if(vetor[x].id == idOperacao) {
            printf("Digite o novo label (titulo) da operacao: ");
            scanf(" %[^\n]", vetor[x].label);

            printf("Digite a nova descricao da operacao: ");
            scanf(" %[^\n]", vetor[x].descricao);

            printf("Digite o novo codigo da operacao (0, 1 ou 2): ");
            scanf("%d", &vetor[x].codigo);

            printf("Digite o novo valor da operacao: ");
            scanf("%f", &vetor[x].valor);

            encontrou = 1;
            printf("Operacao alterada com sucesso!\n");
            return;
        }
    }
    if (encontrou == 0) {
        printf("Nenhuma operacao encontrada com o ID '%d'.\n", idOperacao);
    }
}

void gravarDados() {
    FILE *arq = fopen("lancamentos.txt","w");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo...");
    }

    for(int x = 0; x < cont; x++) {
        printf("\nGravando informacoes do ID %d", vetor[x].id);
        fprintf(arq, "%d\n", vetor[x].id);
        fprintf(arq, "%d\n", vetor[x].tipo);
        fprintf(arq, "%s\n", vetor[x].label);
        fprintf(arq, "%s\n", vetor[x].descricao);
        fprintf(arq, "%f\n", vetor[x].codigo);
        fprintf(arq, "%f\n", vetor[x].valor);
    }
    fclose(arq);
    printf("\nInformacoes gravadas com sucesso!");
}

void lerDados() {
    FILE *arq = fopen("lancamentos.txt","r");

    if(arq == NULL) {
        printf("Erro ao ler arquivo...");
    }
    cont = 0;

    while(scanf("arq, %d %d  %29[^\n]  %999[^\n] %d %f",
        vetor[cont].id,
        vetor[cont].tipo,
        vetor[cont].label,
        vetor[cont].descricao,
        vetor[cont].codigo,
        vetor[cont].valor)
        == 6) {
        printf("\nOperacao %d carregada!", vetor[cont].id);
        cont++;
        }
    fclose(arq);
    printf("\nTotal de operacoes lidas: %d", cont);
}

int menu() {
    int opcao;

    printf("\n=========== MENU ===========\n");
    printf("1 - Lancar Operacao\n");
    printf("2 - Consultar Saldo\n");
    printf("3 - Listar Todas Operacoes\n");
    printf("4 - Listar Operacoes por Tipo\n");
    printf("5 - Listar Operacoes por Codigo\n");
    printf("6 - Consultar por Label\n");
    printf("7 - Alterar Operacao\n");
    printf("8 - Gravar Arquivo\n");
    printf("9 - Ler Arquivo\n");
    printf("10 - Sair\n");

    printf("Escolha: ");
    scanf("%d",&opcao);

    return opcao;
}

int main() {
    int opcao;

    do {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            lancamento();
            break;
        case 2:
            consultarSaldo();
            break;
        case 3:
            listarTodas();
            break;
        case 4:
            listarTipo();
            break;
        case 5:
            listarCodigo();
            break;
        case 6:
            consultarLabel();
            break;
        case 7:
            alterarOperacao();
            break;
        case 8:
            gravarDados();
            break;
        case 9:
            lerDados();
            break;
        case 10:
            printf("\nSaindo do programa...");
            break;
        default:
            printf("\nOpcao invalida... Tente de novo.");
        }
    }   while(opcao != 10);

    return 0;
}