/*
 * Nome dos Integrantes da dupla:
 * João Pedro Borsato de Ramos
 * Victor Angelo Legat Cerqueira
 */
#include <stdio.h>
#include <stdlib.h>

struct no
{
    int valor;
    struct no *prox;
};

struct no *lista = NULL;

void insereLista(int valor)
{
    struct no *aux;
    aux = (struct no *)malloc(sizeof(struct no));
    aux->valor = valor;
    struct no *atual, *anterior;
    atual = lista;
    anterior = NULL;
    while (atual != NULL && atual->valor < valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    if (anterior == NULL)
    {
        aux->prox = lista;
        lista = aux;
    }
    else
    {
        aux->prox = anterior->prox;
        anterior->prox = aux;
    }
    printf("\nElemento inserido!\n");
}

void recuperaLista(int valor)
{
    int achou = 0;
    if (lista == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }
    struct no *aux;
    int i = 0;
    for (aux = lista; aux != NULL && aux->valor <= valor; aux = aux->prox)
    {
        if (aux->valor == valor)
        {
            printf("\nNa %d posição está o número %d\n", i, aux->valor);
            achou = 1;
        }
        i++;
    }
    if (achou == 0)
        printf("\nNão existe esse valor\n");
    return;
}

void removeValor(int valor)
{
    if (lista == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }
    int achou = 0;
    struct no *anterior, *atual;
    atual = lista;
    while (atual != NULL && atual->valor <= valor)
    {
        anterior = atual;
        if (atual->valor == valor)
        {
            if (atual == lista)
                lista = lista->prox;
            else
            {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\nElemento removido!\n");
            achou = 1;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (achou == 0)
    {
        printf("\nElemento não encontrado!\n");
    }
    return;
}

void removeLista(int posicao)
{
    if (lista == NULL)
    {
        printf("\nLista vazia!\n");
        return;
    }
    if (posicao <= 0)
    {
        printf("\nPosição inválida!\n");
        return;
    }
    struct no *anterior = NULL, *atual;
    int i = 1, achou = 0;
    for (atual = lista; atual != NULL; atual = atual->prox)
    {
        anterior = atual;
        atual = atual->prox;
        if (i == posicao)
        {
            struct no *aux = atual;
            anterior->prox = aux->prox;
            free(aux);
            return;
        }
        i++;
        printf("papa");
    }
    if (achou == 0)
    {
        printf("Posição não encontrada!");
        return;
    }

    printf("\nElemento na posicao %d removido!\n", posicao);
}

void imprime()
{
    if (lista == NULL)
    {
        printf("\nLista vazia!\n");
    }
    struct no *aux;
    printf("\nLista: ");
    for (aux = lista; aux != NULL;)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    fflush(stdin);
}

int main()
{
    printf("Ponteiro: %p", lista);
    insereLista(3);
    insereLista(4);
    recuperaLista(3);
    insereLista(2);
    insereLista(5);
    imprime();
    removeValor(3);
    imprime();
    // removeLista(1);
    // imprime();
    return 0;
}