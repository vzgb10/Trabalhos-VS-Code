#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct dados {
    int id;
    int tipo;
    char label[30];
    char descricao[1000];
    int codigo;
    float valor;
};

// Vetor global
struct dados operacoes[100];

// Variável para controlar quantas operações existem
int cont = 0;

int menu(){

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

        switch(opcao) {
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
                gravarArquivo();
                break;
            case 9:
                lerArquivo();
                break;
            case 10:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente de novo.\n");
        }
    } while(opcao != 10);

    return 0;
}

void lancamento() {
    struct dados lancamento;

    printf("Digite o ID da Operacao: ");
    scanf("%d", &lancamento.id);

    printf("Tipo do Operacao: \n1 - Deposito ou retirada de valores \n0 - Retirada ou pagamento \n");
    scanf("%d", &lancamento.tipo);
        switch (lancamento.tipo) {
            case 0:
                printf("Operacao de Retirada ou pagamento selecionada.\n");
                break;
            case 1:
                printf("Operacao de Deposito ou retirada de valores selecionada.\n");
                break;
            default:
                printf("Opcao invalida. Por favor, selecione 0 ou 1.\n");
                return;
    }

    printf("Digite o label (titulo) da Operacao: ");
    scanf(" %[^\n]", lancamento.label);

    printf("Digite a descrição da Operacao: ");
    scanf(" %[^\n]", lancamento.descricao);

    printf("Código da Operacao: \n0 - Despesas obrigatorias, \n1 - Depositos, \n2 - Pagamentos por despesas nao obrigatorias \n");
    scanf("%d", &lancamento.codigo);
        switch (lancamento.codigo) {
            case 0:
                printf("Despesas obrigatorias selecionada.\n");
                break;
            case 1:
                printf("Depositos selecionado.\n");
                break;
            case 2:
                printf("Pagamentos por despesas nao obrigatorias selecionado.\n");
                break;
            default:
                printf("Codigo invalido. Por favor, selecione entre 0, 1 ou 2.\n");
                return;
    }

    printf("Digite o valor da Operacao: ");
    scanf("%f", &lancamento.valor);

    operacoes[cont] = lancamento;
    cont++;
}

void consultarSaldo() {

    struct dados consultarSaldo;
    float saldo = 0;

    for(consultarSaldo.id = 0; consultarSaldo.id < cont; consultarSaldo.id++) {

        if(operacoes[consultarSaldo.id].tipo == 1)
            saldo += operacoes[consultarSaldo.id].valor;
        else
            saldo -= operacoes[consultarSaldo.id].valor;
    }

    printf("\nSaldo Atual: R$ %.2f\n", saldo);
}

void listarTodas() {
    printf("\n=========== LISTAGEM DE TODAS AS OPERACOES ===========\n");
    for(int i = 0; i < cont; i++) {
        printf("ID:        %d\n", operacoes[i].id);
        printf("Tipo:      %d\n", operacoes[i].tipo);
        printf("Label:     %s\n", operacoes[i].label);
        printf("Descricao: %s\n", operacoes[i].descricao);
        printf("Codigo:    %d\n", operacoes[i].codigo);
        printf("Valor:     %.2f\n", operacoes[i].valor);
        printf("--------------------\n");
    }
}

void listarTipo () {
    int tipoConsulta;
    int encontrou = 0;
    printf("Digite o tipo de operacao para listar: \n1 - Deposito ou retirada de valores \n0 - Retirada ou pagamento  \n");
    scanf("%d", &tipoConsulta);

    printf("\n=========== LISTAGEM DE OPERACOES POR TIPO ===========\n");
    for(int i = 0; i < cont; i++) {
        if(operacoes[i].tipo == tipoConsulta) {
            printf("ID:        %d\n", operacoes[i].id);
            printf("Tipo:      %d\n", operacoes[i].tipo);
            printf("Label:     %s\n", operacoes[i].label);
            printf("Descricao: %s\n", operacoes[i].descricao);
            printf("Codigo:    %d\n", operacoes[i].codigo);
            printf("Valor:     %.2f\n", operacoes[i].valor);
            printf("--------------------\n");
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhuma operacao encontrada para o tipo '%d'.\n", tipoConsulta);
    }
}

void listarCodigo () {
    int codigoConsulta;
    int encontrou = 0;
    printf("Digite o codigo de operacao para listar: \n0 - Despesas obrigatorias \n1 - Depositos \n2 - Pagamentos por despesas nao obrigatorias \n");
    scanf("%d", &codigoConsulta);

    printf("\n=========== LISTAGEM DE OPERACOES POR CODIGO ===========\n");
    for(int i = 0; i < cont; i++) {
        if(operacoes[i].codigo == codigoConsulta) {
            printf("ID:        %d\n", operacoes[i].id);
            printf("Tipo:      %d\n", operacoes[i].tipo);
            printf("Label:     %s\n", operacoes[i].label);
            printf("Descricao: %s\n", operacoes[i].descricao);
            printf("Codigo:    %d\n", operacoes[i].codigo);
            printf("Valor:     %.2f\n", operacoes[i].valor);
            printf("--------------------\n");
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhuma operacao encontrada para o codigo '%d'.\n", codigoConsulta);
    }
}

void consultarLabel() {
    char labelConsulta[30];
    int encontrou = 0;
    printf("Digite o label (titulo) da operacao para consultar: ");
    scanf(" %[^\n]", labelConsulta);

    printf("\n=========== CONSULTA DE OPERACOES POR LABEL ===========\n");
    for(int i = 0; i < cont; i++) {
        if(strcmp(operacoes[i].label, labelConsulta) == 0) {
            printf("ID:        %d\n", operacoes[i].id);
            printf("Tipo:      %d\n", operacoes[i].tipo);
            printf("Label:     %s\n", operacoes[i].label);
            printf("Descricao: %s\n", operacoes[i].descricao);
            printf("Codigo:    %d\n", operacoes[i].codigo);
            printf("Valor:     %.2f\n", operacoes[i].valor);
            printf("--------------------\n");
            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhuma operacao encontrada com o label '%s'.\n", labelConsulta);
    }
}

void alterarOperacao() {
    int idConsulta;
    int encontrou = 0;
    printf("Digite o ID da operacao que deseja alterar: ");
    scanf("%d", &idConsulta);

    for(int i = 0; i < cont; i++) {
        if(operacoes[i].id == idConsulta) {
            printf("Operacao encontrada. Digite os novos dados:\n");

            printf("Digite o novo tipo da operacao (0 ou 1): ");
            scanf("%d", &operacoes[i].tipo);

            printf("Digite o novo label (titulo) da operacao: ");
            scanf(" %[^\n]", operacoes[i].label);

            printf("Digite a nova descricao da operacao: ");
            scanf(" %[^\n]", operacoes[i].descricao);

            printf("Digite o novo codigo da operacao (0, 1 ou 2): ");
            scanf("%d", &operacoes[i].codigo);

            printf("Digite o novo valor da operacao: ");
            scanf("%f", &operacoes[i].valor);

            printf("Operacao alterada com sucesso!\n");
            return;

            encontrou = 1;
        }
    }
    if (encontrou == 0) {
        printf("Nenhuma operacao encontrada com o ID '%d'.\n", idConsulta);
    }
}

void gravarArquivo() {
    FILE *arquivo = fopen("operacoes.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita...\n");
        return;
    }

    for(int i = 0; i < cont; i++) {
        fprintf(arquivo, "%d\n", operacoes[i].id);
        fprintf(arquivo, "%d\n", operacoes[i].tipo);
        fprintf(arquivo, "%s\n", operacoes[i].label);
        fprintf(arquivo, "%s\n", operacoes[i].descricao);
        fprintf(arquivo, "%d\n", operacoes[i].codigo);
        fprintf(arquivo, "%.2f\n", operacoes[i].valor);
    }

    fclose(arquivo);
    printf("Operacoes gravadas com sucesso no arquivo!\n");
}

void lerArquivo() {
    FILE *arquivo = fopen("operacoes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura...\n");
        return;
    }

    cont = 0; // Resetar contador antes de ler
    while (fscanf(arquivo, "%d\n%d\n %[^\n]\n %[^\n]\n%d\n%f\n",
                  &operacoes[cont].id,
                  &operacoes[cont].tipo,
                  operacoes[cont].label,
                  operacoes[cont].descricao,
                  &operacoes[cont].codigo,
                  &operacoes[cont].valor) == 6) {
        cont++;
    }

    fclose(arquivo);
    printf("Operacoes lidas com sucesso do arquivo!\n");
}