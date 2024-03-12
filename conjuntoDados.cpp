#include <iostream>

struct Conjunto{
    int conjunto[20];
    int tamanho;

    void conjuntoVazio(){
        tamanho = 0;
        printf("Conjunto vazio criado!\n");
    }

    void ler(){
        do{
            printf("Digite o tamanho do conjunto: ");
            scanf("%d", &tamanho);
        }while(tamanho <= 0 || tamanho > 20);

        printf("Digite os elementos do conjunto de tamanho %d :", tamanho);
        for(int i = 0; i < tamanho; i++){
            scanf("%d", &conjunto[i]);
        }
    }

    void imprimir(){
        for(int i = 0; i < tamanho; i++){
            printf("%d ", conjunto[i]);
        }
        printf("}\n");
    }
};

struct TDA{
    Conjunto c[2];
    int qtdConjuntos = 0;

    void criarConjuntoVazio(){
        if(qtdConjuntos == 2){
            printf("Limite de conjuntos atingido!\n");
            return;
        }
       c[qtdConjuntos].conjuntoVazio();
       qtdConjuntos++;
    }

    void lerConjunto(){
        if(qtdConjuntos == 2){
            printf("Limite de conjuntos atingido!\n");
            return;
        }
        printf("Conjunto %d :\n", qtdConjuntos+1);
        c[qtdConjuntos].ler();
        qtdConjuntos++;
    }

    void unir(){

        if(qtdConjuntos == 0){
            printf("Necessario ler dois conjunto para fazer a uniao!\n");
            return;
        }else if (qtdConjuntos < 2){
            printf("Necessario ler outro conjunto para fazer a uniao!\n");
            return;
        }

        int resultadoUniao[40];
        for(int i = 0; i < c[0].tamanho; i++){
            resultadoUniao[i] = c[0].conjunto[i];
        }

        int j = 0;
        for(int i = c[0].tamanho; i < c[1].tamanho + c[0].tamanho; i++){
            resultadoUniao[i] = c[1].conjunto[j];
            j++;
        }

        printf("Conjunto 1 U Conjuto 2: { ");
        for(int i = 0; i < c[1].tamanho + c[0].tamanho; i++){
            printf("%d ", resultadoUniao[i]);
        }

        printf("}\n");
    }

    void intersecao(){

        if(qtdConjuntos == 0){
            printf("Necessario ler dois conjunto para fazer a intersecao!\n");
            return;
        }else if (qtdConjuntos < 2){
            printf("Necessario ler outro conjunto para fazer a intersecao!\n");
            return;
        }

        int resultadoIntersecao[20], cont = 0;
        for(int i = 0; i < c[0].tamanho; i++){
            for(int j = 0; j < c[1].tamanho; j++){
                if(c[0].conjunto[i] == c[1].conjunto[j]){
                    resultadoIntersecao[cont] = c[0].conjunto[i];
                    cont++;
                }
            }
        }

        printf("Conjunto 1 & Conjuto 2: { ");
        for(int i = 0; i < cont; i++){
            printf("%d ", resultadoIntersecao[i]);
        }

        printf("}\n");
    }

    void imprimirConjunto(){

        if(qtdConjuntos == 0){
            printf("Nao ha conjuntos para imprimir!\n");
            return;
        }

        for (int i = 0; i < qtdConjuntos; i++) {
            printf("Conjunto %d : {", i + 1);
            c[i].imprimir();
        }
    }

};




int main(){
    TDA conj;

    int opcao;

    do{
        printf("       MENU\n");
        printf("1. Criar conjunto vazio.\n");
        printf("2. Ler os dados de um conjunto.\n");
        printf("3. Unir  os dois conjuntos.\n");
        printf("4. Fazer intersecao dos dois conjuntos.\n");
        printf("5. Imprimir conjuntos.\n");
        printf("6. Sair .\n\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                conj.criarConjuntoVazio();
                break;
            case 2:
                conj.lerConjunto();
                break;
            case 3:
                conj.unir();
                break;
            case 4:
                conj.intersecao();
                break;
            case 5:
                conj.imprimirConjunto();
                break;

        };

    }while(opcao != 6);


    return 0;
}

