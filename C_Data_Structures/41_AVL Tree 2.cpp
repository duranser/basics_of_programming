#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	int balance;       // Left height - Right height
	struct node *left;
	struct node *right;
};

struct node *search(struct node *ptr, int data);
struct node *insert (int data, struct node *ptr, bool *ht_inc);
void display(struct node *, int );
void preOrder(struct node *);
void inOrder(struct node *);
void postOrder(struct node *);

int main(){
	bool ht_inc;
	int data, option;
	struct node *root = (struct node *)malloc(sizeof(struct node));
	root = NULL;
	while(option != 3){
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Quit\n");
		printf("Enter your option : ");
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("\nEnter the value to be inserted: ");
				scanf("%d", &data);
				if( search(root, data) == NULL )
					root = insert(data, root, &ht_inc);
				else
					printf("\nDublicate value ignored\n");
					break;
			case 2:
				if(root == NULL){
					printf("Tree is empty\n");
					break;
				}
				printf("Tree is: \n");
				display(root, 1);
				printf("\n\n");
				printf("Inorder Traversal is: ");
				inOrder(root);
				printf("\n");
				break;
		}
	}
	return 0;
}

struct node *search(struct node *ptr, int data){
	if(ptr != NULL){
		if(data < ptr->data)
			ptr = search(ptr->left, data);
		else if(data > ptr->data)
			ptr = search(ptr->right, data);
	return ptr;
	}
}

struct node *insert (int data, struct node *ptr, int *ht_inc){
	struct node *bptr, *cptr;
	if(ptr == NULL){
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->data = data;
		ptr->left = NULL;
		ptr->right = NULL;
		ptr->balance = 0;
		*ht_inc = 1;
		return ptr;
	}
	if(data < ptr->data){
		ptr->left = insert(data, ptr->left, ht_inc);
		if(*ht_inc){                   // Yeni düðüm eklendiyse
			switch(ptr->balance){
				case -1:               // Right heavy
					ptr->balance = 0;
					*ht_inc = 0;
					break;
				case 0:                // Balanced
					ptr->balance = 1;
					break;
				case 1:				   // Left heavy,
					bptr = ptr->left;
					if(bptr->balance == 1){   //  LL case
						printf("Left to Left Rotation\n");
						ptr->left = bptr->right;
						bptr->right = ptr;
						ptr->balance = 0;        
						bptr->balance = 0;
						ptr = bptr;
					}
					else{
						printf("Left to Right Rotation\n");
						cptr = bptr->right;
						bptr->right = cptr->left;
						cptr->left = bptr;
						ptr->left = cptr->right;
						cptr->right = ptr;
						if( cptr -> balance == 1 )
							ptr -> balance = -1;
						else
							ptr -> balance = 0;
						if(cptr -> balance == -1)
							bptr -> balance = 1;
						else
							bptr -> balance = 0;
						cptr -> balance = 0;
						ptr = cptr;
					}
					*ht_inc = 0;
			}
		}		
	}
/*   LL:               RR:
	 1   A                  A   -1
	    / \               /  \
    0  B   T3           T1   B   0
  	  / \                   / \
 	T1  T2                T2  T3
 	
*/
/*  LR:					   RL:
	  1  A                    A  -1
	    / \      	        /  \
   	0  B   T4    		   T1   B  0
  	  / \                      / \
 	T1   C                    C  T4
 		/ \			     	 / \
 	  T2   T3 	    	   T2   T3
*/

	if(data > ptr->data){
		ptr->right = insert(data, ptr->right, ht_inc);
		if(*ht_inc == true){
			switch(ptr->balance){
				case 1:   // Left heavy
					ptr->balance = 0;
					*ht_inc = 0;
					break;
				case 0:
					ptr->balance = -1;
					break;
				case -1:    // Right heavy
					bptr = ptr->right;
					if(bptr->balance == -1){   // RR case
						printf("Right to Right Rotation\n");
						ptr->right = bptr->left;
						bptr->left = ptr;
						ptr->balance = 0;
						bptr->balance = 0;
						ptr = bptr;
					}
					else{
						printf("Right to Left Rotation\n");
						cptr = bptr->left;
						bptr->left = cptr->right;
						cptr->right = bptr;
						ptr->right = cptr->left;
						cptr->left = ptr;
						if(cptr -> balance == -1)
							ptr -> balance = 1;
						else
							ptr -> balance = 0;
						if(cptr -> balance == 1)
							bptr -> balance = -1;
						else
							bptr -> balance = 0;
						cptr->balance = 0;
						ptr = cptr;
					}
				*ht_inc = 0;
			}
		}
	}
	return ptr;
}

void display(struct node *ptr, int level){
	int i;
	if(ptr != NULL){
		display(ptr->right, level + 1);
		printf("\n");
		for(i = 0; i<level; i++)
			printf("  ");
		printf("%d", ptr->data);
		display(ptr->left, level+1);
	}
}

void inOrder(struct node *tree){
	if(tree != NULL){
		inOrder(tree->left);
		printf("\t%d", tree->data);
		inOrder(tree->right);
	}
}

void preOrder(struct node *tree){
	if(tree != NULL){
		printf("\t%d", tree->data);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void postOrder(struct node *tree){
	if(tree != NULL){
		postOrder(tree->left);
		postOrder(tree->right);
		printf("\t%d", tree->data);
	}
}

