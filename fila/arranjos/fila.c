#include <stdio.h>
#include <stdlib.h>

int const MAXTAM=1000;

int Frente, Tras;
int Fila[MAXTAM];

void Construtor(){
    Frente=0;
    Tras=-1;
}

bool Fila_Vazia(){
    if(Frente>Tras){
        return true;
    }else{
        return false;
    }
}

bool Fila_Cheia(){
    if(Tras==MAXTAM-1){
        return true;
    }else{
        return false;
    }
}

bool Enfileirar(int valor){
    if(Fila_Cheia()){
        return false;
    }else{
        Tras++;
        Fila[Tras]=valor;
        return true;
    }
}

bool Desenfileirar(int &valor){
    if(Fila_Vazia()){
        return false;
    }else{
        valor=Fila[Frente];
        Frente++;
        return true;
    }
}

//verificar ultimo valor da fila 
bool Fila_Get(int &valor){
    if(Fila_Vazia()){
        return false;
    }else{
        valor=Fila[Frente];
        return true;
    }
}

int Tamanho(){
    return (Tras - Frente)+1;
}


int main(){
    int Valor;
    Construtor();

    Enfileirar(2);
    Enfileirar(5);
    Enfileirar(4);

    printf("\n\nTamanho:%d\n\n",Tamanho());


    while( Desenfileirar(Valor) ){
        printf("\nValor:%d\n",Valor);
    }
    printf("\n\nTamanho:%d\n\n",Tamanho());

    system("pause");
    return 0;
}
