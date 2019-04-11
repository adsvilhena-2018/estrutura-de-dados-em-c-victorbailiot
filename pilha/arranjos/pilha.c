#include <stdio.h>
#include <stdlib.h>

int const MAXTAM = 1000;

int Pilha[MAXTAM];
int Topo;

void Construtor(){
    Topo = -1;
}

bool Pilha_Vazia(){
    if(Topo==-1)
        return true;
    else
        return false;
}

int Tamanho(){
    return Topo+1;
}

bool Pilha_Cheia(){
    if(Topo==MAXTAM-1)
        return true;
    else
        return false;
}

bool Push(int valor){ //Push = Empilhar
    if( Pilha_Cheia() ){
       return false;
    }else{
        Topo++;
        Pilha[Topo] = valor;
        return true;
    }
}

bool Pop(int &valor){ //Pop = Desempilhar

    if( Pilha_Vazia() ){
        return false;
    }else{
        valor=Pilha[Topo];
        Topo--;
        return true;
    }
}

bool Pilha_Get(int &valor){ //Consulta
    if( Pilha_Vazia() ){
        return false;
    }else{
        valor=Pilha[Topo];
        return true;
    }
}

int main(){

    int valor;

    Construtor();
    Push(5);
    Push(7);
    Push(9);
    Push(1);
    Push(2);

    printf("\n\n Quant. itens da pilha:%d \n\n\n", Tamanho() );
    
    while( Pop(valor) ){
        printf("\n %d \n",valor);
    }
    
    printf("\n\n Quant. itens da pilha:%d \n\n\n", Tamanho() );

    system("pause");
    return 0;
}
