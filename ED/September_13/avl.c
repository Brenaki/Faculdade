#include <stdio.h>
#include <stdlib.h>

struct Node {
  int num;
  int h;
  struct Node* left;
  struct Node* right;
};

int max(int a, int b){
  if(a>b) return a;
  return b;
}

int height(struct Node* node){
  if(node == NULL) return 0;

  return node->h;

}

int Balance(struct Node* node){
  if(node == NULL) return 0;
  return height(node->left) - height(node->right);
}

struct Node* NewNode(int num){
  struct Node* aux = (struct Node*)malloc(sizeof(struct Node));
  aux->num = num;
  aux->h = 1;
  aux->right = NULL;
  aux->left = NULL;

  return aux;
}

struct Node* LeftRotate(struct Node* z){
	struct Node* y = z->right;
	struct Node* t2 = y->left;

	y->left = z;
	z->right = t2;

	z->h = max(height(z->left),height(z->right))+1;
	y->h = max(height(y->left),height(y->right))+1;

	return y;
}

struct Node* RightRotate(struct Node* z){
	struct Node* y = z->left;
	struct Node* t3 = y->right;

	y->right = z;
	z->left = t3;

	z->h = max(height(z->left),height(z->right))+1;
	y->h = max(height(y->left),height(y->right))+1;

	return y;
}

struct Node* Insert(struct Node* root, int num){
  if(root == NULL) return NewNode(num);

  if(root->num > num) 
    root->left = Insert(root->left, num);
  else if(num > root->num)
    root->right = Insert(root->right, num);
  else return root;

  root->h = max(height(root->left), height(root->right))+1;

  int balance = Balance(root);

  // Left Left Case
	if(balance > 1 && num < root->left->num)
		return RightRotate(root);

	// Right Right Case
	if(balance < -1 && num > root->right->num)
		return LeftRotate(root);

	//Left Right Case
	if(balance > 1 && num > root->left->num){
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}

	// Right Left Case
	if(balance < -1 && num < root->right->num){
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}

  return root;
}

void searchTree(struct Node* root, int num){
	if(root == NULL) return;

	else {
		struct Node *atual = root;
		struct Node *ptr = NULL;
		while(1){
			ptr = atual;
			if(num < ptr->num){
				atual = atual->left;

				if(atual == NULL){
					printf("\nNumber don't found!\n");
					return;
				}
				if(atual->num == num){
					printf("\nNumber found!\n");
					return;
				}
			}
			else {
				atual = atual->right;

				if(atual == NULL){
					printf("\nNumber don't found!\n");
					return;
				}
				if(atual->num == num){
					printf("\nNumber found!\n");
					return;
				}
			}
		}
	}
}

void Inorder(struct Node *root) {
    if(root){
			Inorder(root->left);
			printf("%d ", root->num);
			Inorder(root->right);
  }
}

void Preorder(struct Node *root){
  if(root){
    printf("%d ", root->num);
    Preorder(root->left);
    Preorder(root->right);
  }
}

void Posorder(struct Node *root){
  if(root){ 
    Posorder(root->left);
    Posorder(root->right);
    printf("%d ", root->num);
  }
}

int main(){
  struct Node* root = NULL;
  root = Insert(root, 20);
  root = Insert(root, 30);
  root = Insert(root, 10);
  root = Insert(root, 15);
  root = Insert(root, 8);
  root = Insert(root, 12);
  printf("Pre order by:\n");
  Preorder(root);
  printf("\nIn order by:\n");
  Inorder(root);
  printf("\nPos order by:\n");
  Posorder(root);
  printf("\n");
  searchTree(root, 8);
  searchTree(root, 13);
  return 0;
}
