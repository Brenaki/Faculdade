#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Função para fazer a travessia em ordem
void printInorder(struct Node* node) {
    if (node == NULL)
        return;

    // primeiro recurso no lado esquerdo
    printInorder(node->left);

    // então imprima os dados do nó
    printf("%d ", node->data);  

    // agora recurso no lado direito
    printInorder(node->right);
}

int main() {
    /* criando uma árvore binária simples
            1
          /   \
        2      3
       / \
      4   5
    */
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Travessia em ordem da árvore binária é \n");
    printInorder(root);

    return 0;
}

