#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

int max(int, int);
int height(struct node *);
struct node *newNode(int);
struct node *rightRotate(struct node *);
struct node *leftRotate(struct node *);
int getBalance(struct node *);
struct node *insert(struct node * , int);
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);
struct node *deleteNode(struct node *, int );
struct node *deleteTree(struct node *);

int main(){
	struct node *root = NULL;
	int option, val;
	while( option != 7){
		printf("\n\n********** AVL TREE ***********");
		printf("\n 1. Insert Element");
		printf("\n 2. Delete Element");
		printf("\n 3. Preorder Traversal");
		printf("\n 4. Inorder Traversal");
		printf("\n 5. Postorder Traversal");
		printf("\n 6. Delete AVL Tree");
		printf("\n 7. EXIT");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\nEnter the value of the new node: ");
				scanf("%d", &val);
				root = insert(root, val);
				break;
			case 2:
				printf("\nDelete the element: ");
				scanf("%d", &val);
				root = deleteNode(root, val);
				break;
			case 3:
				printf("\nPreorder traversal of the AVL: \n");
				preOrder(root);
				break;
			case 4:
				printf("\nInorder traversal of the AVL: \n");
				inOrder(root);
				break;
			case 5:
				printf("\nPostorder traversal of the AVL: \n");
				postOrder(root);
				break;
			case 6:
				printf("\nAVL Tree is deleted");
				root = deleteTree(root);
				break;
		}
	}
	return 0;
}

int max(int a, int b) { 
    return (a > b) ? a : b; 
} 

int height(struct node *n){
	if(n == NULL)
		return 0;
	return n->height;
}

struct node *newNode(int data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1;
	return new_node;
}

/*   y                                x
    / \      Right Rotation         /  \
   x   T3    – – – – – – – >       T1   y 
  / \        < - - - - - - -           / \
 T1  T2      Left Rotation           T2  T3

*/
struct node *rightRotate(struct node *y){
	struct node *x = y->left;
	struct node *T2 = x->right;
	
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1;
    
    return x;
}

struct node *leftRotate(struct node *x){
	struct node *y = x->right;
	struct node *T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1;
	
	return y;
}

int getBalance(struct node *n){
	if(n == NULL)
		return 0;
	return height(n->left) - height(n->right);
}

struct node *insert( struct node *node, int data){
	if( node == NULL)
		return newNode(data);
	
	if( data < node->data)
		node->left = insert(node->left, data);
	else if(data > node->data)
		node->right = insert(node->right, data);
	else
		return node;
	
	node->height = max(height (node->left), height(node->right)) + 1;
	
	int balance = getBalance(node);
	
	if(balance > 1 && data < node->left->data)  // LL
		return rightRotate(node);
	
	if(balance < -1 && data > node->right->data) // RR
		return leftRotate(node);

	if(balance > 1 && data > node->left->data){  // LR
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	
	if(balance < -1 && data < node->right->data){  // RL
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;	// Root
}

struct node *minValueNode(struct node *node){
	while(node->left != NULL)
		node = node->left;
	return node;
}

struct node *deleteNode(struct node *root, int data){
	if(root == NULL)     // node bulunamazsa
		return root;
	if(data < root->data)
		root->left = deleteNode(root->left, data);
	else if(data > root->data)
		root->right = deleteNode(root->right, data);
	else{          // The node is found
		if( ( root->left == NULL) || (root->right == NULL) ){   // one child
			struct node *temp = root->left ? root->left: root->right;			
			if( temp == NULL ){   // No child
				temp = root;
				root = NULL;
			}
			else // One child
				*root = *temp;   // root deðiþti
			
			free(temp);      
		}
		else{                   // two children
			struct node *temp = minValueNode(root->right);  // in-order successor
			root->data = temp->data;
			
			free(temp);
		} 
	}
	
	 if (root == NULL) 
      return root; 
	
	root->height = max(height(root->left), height(root->right)) + 1;
	
	int balance = getBalance(root);
	int balanceLeft = getBalance(root->left);
	int balanceRight = getBalance(root->right);
	
	if(balance > 1 && balanceLeft >= 0 )  // LL
		return rightRotate(root);
	
	if(balance > 1 && balanceLeft < 0){   // LR
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if(balance < -1 && balanceRight <= 0) // RR
		return leftRotate(root);
	
	if(balance < -1 && balanceRight > 0){  // RL
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;	// Root
}

void preOrder(struct node *root){
	if( root != NULL){
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct node *root){
	if( root != NULL){
		inOrder(root->left);
		printf("%d ", root->data);
		inOrder(root->right);
	}
}

void postOrder(struct node *root){
	if( root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->data);
	}
}

struct node *deleteTree(struct node *root){
	if( root != NULL){
		deleteTree(root->left);
		deleteTree(root->right);
		free(root);
	}
	return root;
}




