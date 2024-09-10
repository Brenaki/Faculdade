# Busca em árvore - Árvore AVL

## Busca em árvore binária

Vimos anteriormente a eficiência da busca em árvores binária

Se a árvore binária for uma árvore, completa ou cheia a busca tende a ficar com ordem de O(log2(n))

Mas isso depende exclusivamente da ordem em que foram inseridos os elementos

### Árvores balanceadas

A solução para o problema anterior é manter as árvores balanceadas

Existem dois tipos principais de árvores balanceadas

Árvores AVL

Árvores Rubro Negra

## Árvore AVL

Á árvore AVL foi criada em 1962 por Adelson Velsky e Landis

É uma árvore balanceada que respeita as características de uma árvore binária

Principal regra é:
- Cada nó apresenta diferença de altura entre as sub-arvores direita e esquerda de 1, 0 ou -1.

### Para entender melhor

Vamos substituir a altura da árvore por **quantidades de níveis** dps nós(qn)

**qn da subárvore esquerda do nó - qn da subárvore direita do nó**

Para balancear a árvore devemos realizar *rotações*

### Rotações

- As rotações podem ser:
1. Simples para direita ou para esquerda
2. Dupla com filho para direita e pai para esquerda
3. Dupla com filho para esquerda e pai para direita

Rotação 2 | Rotação -2 | Numero 2 | Numero -2
:-- | :-: | :-: | --:
Simples para à esquerda | Simples para à direita | 1 | -1
Simples para esquerda | Simples para à direita | 0 | 0 
Dupla com filho para direita e pai para esquerda | Dupla com filho para esquerda e pai para direita | -1 | 1

## Pseudocódigo

```
Se nó N possui balanceamento 2
    Se filho esquerda de N tem balanceamento 1
     Faça uma rotação direita no nó N
     Senão faça uma rotação esquerda no filho esquerda de N e uma rotação direita em N
Se nó N balanceamento -2
    Se filho direito de N tem balanceamento -1
        Faça uma rotação esquerda no nó N
        Senão faça uma rotação direita no filho direita de N e uma rotação esquerda em N
```

## Código
código feito por [amitbansal7](https://github.com/amitbansal7/Data-Structures-and-Algorithms/blob/master/8.AVL-tree/AVLTree.c)
```c
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	int height;
	struct Node* left;
	struct Node* right;
};
//Insertion and deletion in AVL Tree
struct Node* NewNode(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

int max(int a,int b)
{
 	return (a>b)?a:b;
}

int height(struct Node* node)
{
	if(node==NULL)
		return 0;

 	return node->height;
}

int Balance(struct Node* node)
{
	if(node==NULL)
		return 0;

 	return height(node->left) - height(node->right);
}

struct Node* LeftRotate(struct Node* z)
{
	struct Node* y = z->right;
	struct Node* t2 = y->left;

	y->left = z;
	z->right = t2;

	z->height = max(height(z->left),height(z->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

struct Node* RightRotate(struct Node* z)
{
	struct Node* y = z->left;
	struct Node* t3 = y->right;

	y->right = z;
	z->left = t3;

	z->height = max(height(z->left),height(z->right))+1;
	y->height = max(height(y->left),height(y->right))+1;

	return y;
}

void preorder(struct Node* root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

struct Node* FindMin(struct Node* node)
{
	while(node->left!=NULL)
		node = node->left;

	return node;
}

struct Node* Delete(struct Node* root,int data)
{
	if(root==NULL)
		return root;

	if(data < root->data)
		root->left = Delete(root->left,data);

	else if(data > root->data)
		root->right = Delete(root->right,data);

	else
	{
		if(root->right==NULL && root->left==NULL)
		{
			free(root);
			root = NULL;
		}

		else if(root->left!=NULL && root->right==NULL)
		{
			struct Node* temp = root->left;
			root = root->left;
			free(temp);
		}

		else if(root->right!=NULL && root->left==NULL)
		{
			struct Node* temp = root->right;
			root = root->right;
			free(temp);
		}

		else
		{
			struct Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	if(root==NULL)
		return root;

	root->height = 1 + max(height(root->left),height(root->right));

	int balance = Balance(root);

	//Left Left Case
	if(balance > 1 && Balance(root->left) >=0)
		return RightRotate(root);

	// Right Right Case
	if(balance < -1 && Balance(root->right) <=0)
		return LeftRotate(root);

	// Left Right Case
	if(balance > 1 && Balance(root->left) < 0)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}
	
	//Right Left Case
	if(balance < -1 && Balance(root->right) > 0)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}
	return root;
}

struct Node* Insert(struct Node* root,int data)
{
	if(root==NULL)
		return NewNode(data);

	if(data < root->data)
		root->left = Insert(root->left,data);

	else if(data > root->data)
		root->right = Insert(root->right,data);

	else
		return root;

	root->height = max(height(root->left),height(root->right))+1;

	int balance = Balance(root);

	// Left Left Case
	if(balance > 1 && data < root->left->data)
		return RightRotate(root);

	// Right Right Case
	if(balance < -1 && data > root->right->data)
		return LeftRotate(root);

	//Left Right Case
	if(balance > 1 && data > root->left->data)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}

	// Right Left Case
	if(balance < -1 && data < root->right->data)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}

	return root;
}

int main()
{
	struct Node* root = NULL;

	root = Insert(root,5);
	root = Insert(root,10);
	root = Insert(root,15);
	root = Insert(root,25);
	root = Insert(root,30);
	root = Insert(root,14);
	root = Insert(root,23);
	root = Insert(root,6);
	root = Insert(root,24);
	root = Insert(root,30);
	root = Insert(root,3);

	/*
            BST -->     5
                       /   \
                      3    10
                         /  \
                        6   15
                           /  \
                          14   25
                              /  \
                             23  30
                              \   
                              24   



            AVL TREE -->    15
                          /    \	
                         10     25
                       /   \   /  \
                      5    14 23  30
                    /  \       \
                   3    6      24
	*/

	printf("\nPreorder traversal of tree is : "); preorder(root);

	root = Delete(root,10);
	/*	
        After deleting 10
           AVL TREE -->           15
                                /    \	
                               5     25
                             /   \   /  \
                            3    14 23  30
                                /    \
                               6     24
					    
	*/
	printf("\nPreorder traversal after deleting 10 is : "); preorder(root);

	return 0;
}
```
