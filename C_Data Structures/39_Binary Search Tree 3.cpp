#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *insert_node(struct node *, int);
struct node *delete_node(struct node *, int);
struct node *getptr(struct node *, int , struct node **);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);

int main(){
	struct node *tree = NULL;
	int option, val;
	while( option != 6){
		printf("\n ******BINARY SEARCH TREE******* \n");
		printf("\n 1. Insert Element");
		printf("\n 2. Delete Element");
		printf("\n 3. Preorder Traversal");
		printf("\n 4. Inorder Traversal");
		printf("\n 5. Postorder Traversal");
		printf("\n 6. Exit");
		printf("\n\nChoose an option :");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\nEnter the value of the new node: ");
				scanf("%d", &val);
				tree = insert_node(tree, val);
				break;
			case 2:
				printf("\nEnter the value of the node to be deleted: ");
				scanf("%d", &val);
				tree = delete_node(tree, val);
				break;
			case 3:
				printf("\n");
				preorderTraversal(tree);
				break;
			case 4:
				printf("\n");
				inorderTraversal(tree);
				break;
			case 5:
				printf("\n");
				postorderTraversal(tree);
				break;
			
		}
	}
}

struct node *insert_node(struct node *tree, int val){
	if(tree == NULL){
		tree = (struct node *)malloc(sizeof(struct node));
		tree->data = val;
		tree->left = NULL;
		tree->right = NULL;		
	}
	else{
		if( val < tree->data)
			tree->left = insert_node(tree->left, val);
		else if(val > tree->data)
			tree->right = insert_node(tree->right, val);
		else
			printf("The value exists");
	}
	return tree;
}

struct node *getptr(struct node *tree, int val, struct node **parent){
	struct node *temp;
	if( tree == NULL )
		return NULL;
	temp = tree;
	*parent = NULL;
	while(temp != NULL || temp->data == val){
		*parent = temp;
		if(temp->data > val)
			temp = temp->left;
		else if(temp->data < val)
			temp = temp->right;
	}
	return temp;
}

struct node *delete_node(struct node *tree, int val){   // Çalýþmýyor!!!
	// Algoritma farklý in-order successor ya da predecessor kullanýlmýyor!
	struct node *x, *parent, *temp;
	x = getptr(tree, val, &parent);
	if( x== NULL){
		printf("\nThe node does not exist");
		return tree;
	}
	else{
		if( x == tree){   // Root deletion
			temp = x->left;
			parent = x->right;
			tree = temp;
			while(temp->right != NULL)
				temp = temp->right;
			temp->right = parent;    
			free(x);	 
			printf("\nThe root is deleted");    		
			return tree;
		}
		else if( x->left != NULL && x->right != NULL){   // Ýki çocuklu düðüm
			if(parent->left == x){              // x parent'ýn solundaysa
				temp = x->left;
				parent->left = x->left;
				while( temp->right != NULL)
					temp = temp->right;
				temp->right = x->right;
				x->left = NULL;
				x->right = NULL;
			}
			else{                    // x parent'ýn saðýndaysa
				temp = x->right;
				parent->right = x->right;
				while( temp->left != NULL)
					temp = temp->left;
				temp->left = x->left;
				x->left = NULL;
				x->right = NULL;
			}
			free(x);
			return tree;
		}
		else if( x->left == NULL && x->right != NULL){   // Tek çocuklu (sað)
			if(parent->left == x)
				parent->left = x->right;
			else
				parent->right = x->right;
			x->right = NULL;
			free(x);
			return tree;
		}
		else if( x->left != NULL && x->right == NULL){    // Tek çocuklu (sol)
			if(parent->left == x)
				parent->left = x->left;
			else
				parent->right = x->left;
			x->left = NULL;
			free(x);
			return tree;
		}
		else if( x->left == NULL && x->right == NULL){
			if(parent->left == x)
				parent->left = NULL;
			else
				parent->right = NULL;
			free(x);
			return tree;
		}
	}
}

void preorderTraversal(struct node *tree){
	if(tree != NULL){
		printf("%d\t", tree->data);
		preorderTraversal(tree->left);
		preorderTraversal(tree->right);
	}
}

void inorderTraversal(struct node *tree){
	if(tree != NULL){
		inorderTraversal(tree->left);
		printf("%d\t", tree->data);
		inorderTraversal(tree->right);
	}
}

void postorderTraversal(struct node *tree){
	if(tree != NULL){
		postorderTraversal(tree->left);
		postorderTraversal(tree->right);
		printf("%d\t", tree->data);
	}
}
