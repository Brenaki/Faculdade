/*
 * Nome dos desenvolvedores:
 * João Pedro Borsato de Ramos
 * Victor Angelo Legat Cerqueira
 * */


#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define N 4

struct no {
  int chave;
  struct no **prox;
  struct no **ant;
};

struct SkipList {
  int nivelMax;
  float p;
  int nivel;
  struct no *inicio;
  struct no *fim;
};

struct no* novoNo(int chave, int nivel){
  struct no* novo = malloc(sizeof(struct no));
  if(novo != NULL){
    novo->chave = chave;
    novo->prox = malloc((nivel+1) * sizeof(struct no*));
    novo->ant = malloc((nivel+1) * sizeof(struct no*));
    for(int i = 0; i <= nivel; i++) {
      novo->prox[i] = NULL;
      novo->ant[i] = NULL;
    }
  }
  return novo;
}

struct SkipList *criaSkipList(int MAXLVL, float p){
  struct SkipList *sk = (struct SkipList*)malloc(sizeof(struct SkipList));
  if(sk != NULL){
    sk->nivelMax = MAXLVL;
    sk->p = p;
    sk->nivel = 0;
    sk->inicio = novoNo(-1, MAXLVL);
    sk->fim = novoNo(-1, MAXLVL);

    for(int i =0; i<=MAXLVL;i++){
      sk->inicio->prox[i] = sk->fim;
      sk->fim->ant[i] = sk->inicio;
    }
  }
  return sk;
}

void freeSkipList(struct SkipList *sk){
  if (sk == NULL) return;
    struct no *atual = sk->inicio->prox[0];
    while (atual != NULL) {
        struct no *prox = atual->prox[0];
        free(atual->prox);
        free(atual->ant);
        free(atual);
        atual = prox;
    }
    free(sk->inicio->prox);
    free(sk->inicio->ant);
    free(sk->inicio);
    free(sk);
}

int sorteaiNivel(struct SkipList *sk){
  float r = (float)rand()/RAND_MAX;
  int nivel = 0;
  while(r < sk->p && nivel < sk->nivelMax){
    nivel++;
    r = (float)rand()/RAND_MAX;
  }
  return nivel;
}

int insertSkip(struct SkipList *sk, int chave){
  if(sk == NULL) return 0;
  int i;
  struct no *atual = sk->inicio;
  struct no **aux;
  aux = malloc((sk->nivelMax+1) * sizeof(struct no*));
  for(i = 0; i <= sk->nivelMax; i++)
    aux[i] = NULL;

  for(i = sk->nivel; i >= 0; i--){
    while(atual->prox[i] != sk->fim && atual->prox[i]->chave < chave)
      atual = atual->prox[i];
    aux[i] = atual;
  }

  atual = atual->prox[0];
  if(atual == NULL || atual->chave != chave){
    int Novonivel = sorteaiNivel(sk);
    struct no *novo = novoNo(chave, Novonivel);
    if(Novonivel > sk->nivel){
      for(i = sk->nivel + 1; i <= Novonivel; i++)
        aux[i] = sk->inicio;
      sk->nivel = Novonivel;
    }

    for(i = 0; i <= Novonivel; i++){
      if(aux[i]->prox[i] != NULL){
        aux[i]->prox[i]->ant[i] = novo;
      }
      novo->prox[i] = aux[i]->prox[i];
      novo->ant[i] = aux[i];
      aux[i]->prox[i] = novo; 
    } 
    free(aux);
    return 1;
  } else {
    free(aux);
    return 0;
  }
}

int buscaSkipList(struct SkipList *sk, int chave, int pos){
  if(pos == 0){
    if(sk == NULL) return 0;
    struct no *atual = sk->inicio;
    int i;
    for(i = sk->nivel; i >= 0; i--){
      while(atual->prox[i] != NULL && atual->prox[i]->chave < chave)
        atual = atual->prox[i];
    }
    atual = atual->prox[0];
    if(atual != NULL && atual->chave == chave)
      return 1;
    else
      return 0;
  } else if(pos == 1){
    if(sk == NULL) return 0;
    struct no *atual = sk->fim;
    int i;
    for(i = sk->nivel; i >= 0; i--){
      while(atual->ant[i] != NULL && atual->ant[i]->chave > chave)
        atual = atual->ant[i];
    }
    atual = atual->ant[0];
    if(atual != NULL && atual->chave == chave)
      return 1;
    else
      return 0;
  } else {
    system("echo \"\nposicao tem que ser 0(inicio), 1(fim).\n\"");
    return 0;
  }
}

int printSkiplist(struct SkipList *sk, int pos){ 
  if(pos == 0){
    if(sk == NULL) return 0;
    printf("\033[33;40mSkip pela esquerda.\n");
    struct no *atual;
    for(int i = sk->nivel; i >= 0; i--){
      printf("\033[32;40mNivel %d:\033[0m ", i);
      atual = sk->inicio->prox[i];
      while(atual != sk->fim){
        printf("%d ", atual->chave);
        atual = atual->prox[i];
      }
      printf("\n");
    }
    return 1; 
  } else if(pos == 1){
      if(sk == NULL) return 0;
      printf("\033[33;40mSkip pela direita.\n");
      struct no *atual;
      for(int i = sk->nivel; i >= 0; i--){
        printf("\033[32;40mNivel %d:\033[0m ", i);
        atual = sk->fim->ant[i];
        while(atual != sk->inicio){
          printf("%d ", atual->chave);
          atual = atual->ant[i];
        }
        printf("\n");
      }   
    return 1;
  } else { 
    system("echo \"\nposicao tem que ser 0(inicio), 1(fim).\n\"");
    return 0;
  }
}

int main(){
  setlocale(LC_ALL, "portuguese");
  struct SkipList *sk = criaSkipList(N, 0.5);
  int choose = 0, num, pos, result;
  while (choose != 4) {
     if(system("cls") != 0) system("clear");
     printf("\033[0;44m***********************\n1 - Inserir na skip    \n2 - Buscar na skip     \n3 - Imprimir a skip    \n4 - Sair               \n***********************\n\n\033[31;40myou:\033[0m ");
     scanf("%d", &choose);
     switch (choose) {
      case 1:
        if(system("cls") != 0) system("clear"); 
        printf("\033[32;40mcomputer:\033[0m Digite o número que deseja inserir?\n\033[31;40myou:\033[0m ");
        scanf("%d", &num);
        insertSkip(sk, num);
        system("echo \"\nNúmero inserido com sucesso!\n\"");
        system("echo \"Aguarde 3 segundos ou precione para continuar...\"");
        if(system("pause") != 0) system("sleep 3");
        if(system("cls") != 0) system("clear");
        break;
      case 2:
        if(system("cls") != 0) system("clear");
        printf("\033[32;40mcomputer:\033[0m Número que está buscando?\n\033[31;40myou:\033[0m ");
        scanf("%d", &num);
        printf("\033[32;40mcomputer:\033[0m Gostaria de buscar pelo inicio(0) ou pelo fim(1)?\n\033[31;40myou:\033[0m ");
        scanf("%d", &pos);
        result = buscaSkipList(sk, num, pos);
        if(result == 1) {
          printf("\nNumero foi encontrado!\n");
        }
        else {
          printf("\nNúmero não foi encontrado!\n");
        }
        system("echo \"\nAguarde 3 segundos ou precione para continuar...\"");
        if(system("pause") != 0) system("sleep 3");
        if(system("cls") != 0) system("clear");
        break;
      case 3: 
        if(system("cls") != 0) system("clear");
        printf("\033[32;40mcomputer:\033[0m Gostaria de imprimir pelo inicio(0) ou pelo fim(1)?\n\033[31;40myou:\033[0m ");
        scanf("%d", &pos);
        printSkiplist(sk, pos);
        system("echo \"\nAguarde 10 segundos ou precione para continuar...\"");
        if(system("pause") != 0) system("sleep 10");
        if(system("cls") != 0) system("clear");
        break;
      case 4:
        freeSkipList(sk);
        system("echo \"\nExcluindo a skiplist antes de sair aguarde...\"");
        if(system("pause") != 0) system("sleep 5");
        if(system("cls") != 0) system("clear");
        break;
      default:
        if(system("cls") != 0) system("clear");
        system("echo \"\nOpção inválida!\n\"");
        system("echo \"Aguarde 3 segundos ou precione para continuar...\"");
        if(system("pause") != 0) system("sleep 3");
        if(system("cls") != 0) system("clear");
        break;
    }
  }
  return 0;
}
