#include<stdio.h>
#include<string.h>

int pos = 0;

struct Funcionario {
    char nome[50];
    char cargo[50];
    double salario_base;
    double beneficios;
    double descontos;
    double salario_liquido;

    void ler() {
        printf("Nome do Funcionario: ");
        scanf("%s", nome);
        printf("Cargo do Funcionario: ");
        scanf("%s", cargo);
        printf("Salário do Funcionario: ");
        scanf("%lf", &salario_base);
        printf("Beneficios do Funcionario: ");
        scanf("%lf", &beneficios);
        printf("Descontos do Funcionario: ");
        scanf("%lf", &descontos);
    }


    double calculaS() {
        salario_liquido = salario_base + beneficios - descontos;
        return salario_liquido;
    }

    void imprimir() {
        printf("Nome Funcionário: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salário: %.2lf\n", salario_base);
        printf("Beneficios: %.2lf\n", beneficios);
        printf("Descontos: %.2lf\n", descontos);
        printf("Salario Liquido: %.2lf\n\n", calculaS());
    }
};

struct Funcionarios {
    Funcionario func[10];
    double media = 0;
    double salarioSoma = 0;
    char maior[50];
    double salarioMaior = 0;

    void cadastrar() {
        if (pos >= 10) {
            printf("Limite de Funcionarios alcançado.\n");
            return;
        }
        func[pos].ler();
        salarioSoma += func[pos].salario_base;
        pos++;
    }

    double calculaMedia() {
        if (pos > 0) {
            media = salarioSoma / pos;
        }
        return media;
    }

    void maiorSalario() {
        for (int i = 0; i < pos; i++) {
            if (func[i].salario_base > salarioMaior) {
                strcpy(maior, func[i].nome);
                salarioMaior = func[i].salario_base;
            }
        }
    }

    void imprimir() {
        if (pos == 0) {
            printf("Nao ha funcionarios para listar!\n");
            return;
        }
        for (int i = 0; i < pos; i++) {
            func[i].imprimir();
        }
        printf("Média Salarial: %.2lf\n", calculaMedia());
        maiorSalario();
        printf("O funcionario com salario mais alto eh %s\n", maior);
    }
};

int main() {
    Funcionarios f;
    int opcao = 1;

    do {
        printf("1. Cadastrar Funcionario.\n");
        printf("2. Listar Dados dos funcionarios\n");
        printf("3. Sair\n");

        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1:
                f.cadastrar();
                break;
            case 2:
                f.imprimir();
                break;
        }

    } while (opcao < 3);
    return 0;
}