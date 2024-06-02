#include <stdio.h>

// Procedimento para exibir uma mensagem de saudação
void saudacao(char nome[]) {
  printf("Olá, %s! Bem-vindo!\n", nome);
}

int main() {
  char nome_usuario[20]
  printf("Digite seu nome: ");
  scanf("%s", nome_usuario);
  saudacao(nome_usuario); // Chama o procedimento 'saudacao'

  return 0;
}