#include<stdio.h>

struct Data {
    int dia, mes, ano;

    int calcular() {
        int diaHoje = 7;
        int mesHoje = 3;
        int anoHoje = 2024;
        int idade = anoHoje - ano;

        if (mes == mesHoje && dia > diaHoje) {
            idade--;
        } else if (mes > 7) {
            idade--;
        }
        return idade;
    }
};

struct Cliente {
    char nome[100];
    Data dataNasc;
    char sexo;
    int idade;

    void ler() {
        printf("Nome: ");
        scanf("%[^\n]%*c", nome);
        printf("\nData de Nascimento (dia/mes/ano): ");
        scanf("%d%*c", &dataNasc.dia);
        printf("/");
        scanf("%d%*c", &dataNasc.mes);
        printf("/");
        scanf("%d%*c", &dataNasc.ano);
        printf("\n");
        printf("Sexo: ");
        scanf(" %c", &sexo);
        printf("\n");
    }

    void imprimir() {
        printf("Dados do cliente: \n");
        printf("Nome: %s\n", nome);
        printf("Data de Nascimento: %d/%d/%d\n", dataNasc.dia, dataNasc.mes, dataNasc.ano);
        printf("Sexo: %c\n", sexo);
        printf("Idade: %d\n", dataNasc.calcular());
        printf("\n\n");
    }
};

int contCliente = 0;

struct Clientes {
    Cliente clientes[50];

    void cadastrar() {
        if (contCliente > 50) {
            printf("Limite de clientes atingido!\n");
            return;
        }
        clientes[contCliente].ler();
        contCliente++;
    }

    void imprimir() {
        if (contCliente == 0) {
            printf("Nenhum cliente cadastrado!\n");
            return;
        }
        for (int i = 0; i < contCliente; i++) {
            clientes[i].imprimir();
        }
    }
};

int main() {
    Clientes b;
    int opcao = 1;
    do {
        printf("1. Cadastrar cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair do programa\n");

        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1:
                b.cadastrar();
                break;
            case 2:
                b.imprimir();
                break;
        };

    } while (opcao != 3);

    return 0;
}
