#include <stdio.h>
#include <stdlib.h>

struct Fila {

    int capacidade;
    float *dados;
    int primeiro;
    int ultimo;
    int nItens;

};

void criarFila( struct Fila *f, int c ) {

    f->capacidade = c;
    f->dados = (float*) malloc (f->capacidade * sizeof(float));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;

}

void inserir(struct Fila *f, int v) {

    if(f->ultimo == f->capacidade-1) {
        f->ultimo = -1;
    }
    f->ultimo++;
    f->dados[f->ultimo] = v;
    f->nItens++;

}

int remover( struct Fila *f ) {

    int temp = f->dados[f->primeiro++];

    if(f->primeiro == f->capacidade) {
        f->primeiro = 0;
    }
    f->nItens--;
    return temp;

}

int Vazia( struct Fila *f ) {

    return (f->nItens==0);

}

int Cheia( struct Fila *f ) {

    return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

    int j, i;

    for ( j=0, i= f->primeiro; j < f->nItens; j++){

        printf("%.2f\t",f->dados[i++]);

        if (i == f->capacidade) {
            i = 0;
        }
    }
    printf("\n\n");

}
void main () {

    int opcao, capa;
    float valor;
    struct Fila nFila;

    printf("\nCapacidade da fila ? ");
    scanf("%d",&capa);
    criarFila(&nFila, capa);

    while( 1 ){

        printf("\n1 - Inserir elemento\n"
               "2 - Remover elemento\n"
               "3 - Mostrar Fila\n"
               "0 - Sair\n\n"
               "Opcao = ");
        scanf("%d", &opcao);

        switch(opcao){

            case 0:

                exit(0);

            case 1:

                if (Cheia(&nFila)){

                    printf("\nFila Cheia !\n\n");

                }
                else {

                    printf("\nDigite o elemento a ser inserido = ");
                    scanf("%f", &valor);
                    inserir(&nFila,valor);

                }

                break;

            case 2:

                if (Vazia(&nFila)){

                    printf("\nFila vazia!!!\n\n");

                }
                else {

                    valor = remover(&nFila);
                    printf("\n%1f removido com sucesso\n\n", valor) ;

                }
                break;

            case 3:

                if (Vazia(&nFila)){

                    printf("\nFila vazia!!!\n\n");

                }
                else {

                    printf("\nFila = ");
                    mostrarFila(&nFila);

                }
                break;

            default:
                printf("\nOpcao Invalida\n\n");

        }
    }
}
