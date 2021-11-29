#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int);
struct node *insert(struct node *, int);
struct node *deleteNode(struct node *, int );
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
struct node *minValueNode(struct node*);
struct node *deleteTree(struct node *tree);

int main(){
	struct node *tree = NULL;
	int option, val;
	while( option != 7){
		printf("\n\n********** BINARY SEARCH TREE ***********");
		printf("\n 1. Insert Element");
		printf("\n 2. Delete Element");
		printf("\n 3. Preorder Traversal");
		printf("\n 4. Inorder Traversal");
		printf("\n 5. Postorder Traversal");
		printf("\n 6. Delete Binary Search Tree");
		printf("\n 7. EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\nEnter the value of the new node: ");
				scanf("%d", &val);
				tree = insert(tree, val);
				break;
			case 2:
				printf("\nDelete an element: ");
				scanf("%d", &val);
				tree = deleteNode(tree, val);
				break;
			case 3:
				printf("\nPreorder traversal of the AVL: \n");
				preorder(tree);
				break;
			case 4:
				printf("\nInorder traversal of the AVL: \n");
				inorder(tree);
				break;
			case 5:
				printf("\nPostorder traversal of the AVL: \n");
				postorder(tree);
				break;
			case 6:
				printf("\nAVL Tree is deleted");
				tree = deleteTree(tree);
				break;
		}
	}
	return 0;
}

struct node *newNode(int val){
	struct node *ptr = (struct node *)malloc(sizeof(struct node));
	ptr->data = val;
	ptr->left = NULL;
	ptr->right = NULL;
	
	return ptr;
}

struct node *insert(struct node *node, int val){
	if(node == NULL)
		return newNode(val);
		
	if(val < node->data)
		node->left = insert(node->left, val);
	else if(val > node->data)
		node->right = insert(node->right, val);
	else
		printf("\nYok öyle bir dünya");
	
	return node;  // Ýlk çaðýrdýðýn fonksiyon yine tree'yi (root)'u döndürür.
}

struct node *deleteNode(struct node *tree, int val){
	if(tree == NULL)
		return tree;
	if(val < tree->data)
		tree->left = deleteNode(tree->left, val);
	else if(val > tree->data)
		tree->right = deleteNode(tree->right, val);
	else{
		// Node with only one child
		if( tree->left == NULL){
			struct node *temp = tree->right;
			free(tree);
			return temp;    // Ýlk çaðýrdýðýn fonksiyon yine tree'yi (root)'u döndürür.
		}
		else if(tree->right == NULL){
			struct node *temp = tree->left;
			free(tree);
			return temp;
		}
		// Node with two children
		struct node *temp = minValueNode(tree->right);
		tree->data = temp->data;
		tree->right = deleteNode(tree->right, temp->data);
	}
	return tree;
}

void inorder(struct node *tree){
	if(tree != NULL){
		inorder(tree->left);
		printf("\t%d", tree->data);
		inorder(tree->right);
	}
}

void preorder(struct node *tree){
	if(tree != NULL){
		printf("\t%d", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void postorder(struct node *tree){
	if(tree != NULL){
		postorder(tree->left);
		postorder(tree->right);
		printf("\t%d", tree->data);
	}
}

struct node *minValueNode(struct node* node){ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 

struct node *deleteTree(struct node *tree){
	if( tree != NULL){
		deleteTree(tree->left);
		deleteTree(tree->right);
		free(tree);
	}
	return tree;
}

