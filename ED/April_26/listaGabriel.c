//  EXERCÍCIO DA LISTA 6                                      //
//  CÓDIGO FEITO POR: Gabriel do Espírito Santo RA: 23001726  //
//                                                            //
////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// estrutura que será usada para criar a lista

typedef struct no{
    int valor ;
    struct no *prox;
}no ;

// ponteiro que diz aonde nossa lista começa

no *inicio;

 // função que diz se a lista está vazia

int vazia(){

    if(inicio == NULL){
        printf("\n\nLISTA VAZIA!!\n\n");
        return 1;
    }
    else{
        return 0 ;
    }
}

// função para inserir elementos

void insereLista(int valor){

    no *aux = (no*)malloc(sizeof(no));

    aux->valor = valor ;

    no *atual, *anterior ;

    atual = inicio ;
    anterior = NULL ;

    while(atual != NULL && valor > atual->valor){
        anterior = atual;
        atual = atual->prox ;
    }
    if(anterior == NULL ){
        aux->prox = inicio ;
        inicio = aux ;
    }
    else{
        aux->prox = anterior->prox ;
        anterior->prox = aux ;
    }
    printf("VALOR %d INSERIDO\n\n",valor);
}

// função que imprime a lista atual

void imprime(){

    if(vazia()){
        return ;
    }

    no *aux ;

    aux = inicio ;

    printf("\n\nLISTA ATUAL\n\n");

    while(aux != NULL){
        printf("%d ",aux->valor);
        aux = aux->prox ;
    }
    printf("\n\n");
}

// procedimento que remove elementos por valor

void removeValor(int valor){
    no *aux, *atual, *anterior ;
    int achei = 0 ;

    atual = inicio ;


    while(atual != NULL && valor>= atual->valor){

        if(atual->valor == valor){
            achei  = 1;
            if(atual == inicio){
                inicio = inicio->prox ;
            }
            else{
                anterior->prox = atual->prox ;
            }

            free(atual);
            printf("\nVALOR %d REMOVIDO DA LISTA\n\n",valor);


            }
        anterior = atual;
        atual = atual->prox ;

    }
    if(!achei){
    printf("\n\nVALOR %d NÃO ENCONTRADO\n\n",valor);
    }
}

// procedimento que remove elementos por posição

void removeLista(int posicao){

    no *atual ;

    if(posicao == 0){
        atual = inicio ;
        inicio = inicio->prox;
        printf("\n\nVALOR REMOVIDO DA POSIÇÃO %d\n\n",posicao);
        free(atual);
        return ;
    }
    else{

        int cont = 0 ;

        no *anterior, *atual;

        anterior = NULL ;
        atual = inicio ;

        while(atual != NULL ){

            if(cont == posicao){
                    anterior->prox = atual->prox ;
                    printf("\n\nVALOR REMOVIDO DA POSIÇÃO %d \n\n",posicao);
                    free(atual);
                    return ;
            }
            anterior = atual ;
            atual = atual->prox ;
            cont ++ ;
        }
    }
}

// menu de inserção

void menuInsereLista(){

    int num ;
    printf("\nDIGITE UM NÚMERO PARA INSERIR: ");
    scanf("%d",&num);
    insereLista(num);
}

// menu para remover por valor

void menuRemoveValor(){

    if(vazia()){
        return ;
    }
    int valor ;

    printf("\n\nDIGITE O VALOR PARA REMOVER --> ");
    scanf("%d",&valor);

    removeValor(valor);
}

int posicaoValida(int posicao){
    no *atual = inicio ;
    int cont =  0 ;

    while(atual != NULL){
        atual = atual->prox ;
        cont ++ ;
    }
    if(posicao < cont && posicao>=0){
        return 1 ;
    }
    else{
        printf("\n\nPOSIÇÃO INVÁLIDA!!\n\n");
        return 0 ;
    }
}
// menu para remover por posição

void menuRemoveLista(){

    int posicao ;

    if(vazia()){
        return ;
    }

    printf("\n\nDIGITE A POSIÇÃO PARA REMOVER O ELEMENTO --> ");
    scanf("%d",&posicao);

    if(posicaoValida(posicao)){
        removeLista(posicao);
    }
}

// função recursiva que percorre a lista até chegar na posição desejada

void recuperaLista(no *atual,int posicao,int cont){

    if(cont == posicao){
        printf("\n\nVALOR INSERIDO NA POSIÇÃO %d = %d\n\n",posicao,atual->valor);
    }
    else{
        recuperaLista(atual->prox,posicao,cont+1);
    }
}

// verifica se a posição é válida



// menu para recuperar um elemento

void menuRecuperaLista(){
    no *aux = inicio ;
    int posicao ;

    if(vazia()){
        return ;
    }

    printf("\n\nINSIRA A POSIÇÃO PARA RECUPERAR O ELEMENTO --> ");
    scanf("%d",&posicao);

    if(posicaoValida(posicao)){
        recuperaLista(aux,posicao,0);
    }

}

// menu principal do programa

void menu(){

    int opcao = 0;

    while(opcao != 6){

        system("cls");
        printf("MENU LISTAS DINÂMICAS\n\n1- ADICIONAR ELEMENTO\n2- RETIRAR ELEMENTO POR VALOR\n3- RETIRAR ELEMENTO POR POSIÇÃO\n4- VER LISTA ATUAL\n5- RECUPERAR ELEMENTO DA LISTA\n6- SAIR\n");
        printf("Digite a opção desejada --> ");
        scanf("%d",&opcao);
        printf("\n\n");

        switch(opcao){

            case 1:{
                menuInsereLista();
                break;
            }
            case 2:{
                menuRemoveValor();
                break;
            }
            case 3:{
                menuRemoveLista();
                break;
            }
            case 4:{
                imprime();
                break;
            }
            case 5:{
                menuRecuperaLista();
                break;
            }
            case 6:{
                printf("VOCÊ ESCOLHEU VOLTAR!\n");
                break;
            }
            default:{
                printf("OPÇÃO INVÁLIDA\n");
                break;
            }
        }
        system("pause");
    }
}

 // função main

int main(){

    setlocale(LC_ALL,"Portuguese");

    menu();

    return 0;
}

