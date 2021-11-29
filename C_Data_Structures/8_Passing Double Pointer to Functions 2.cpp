#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *left;
	struct node *right;
	int data;
};

void minValueNode(struct node *node){
	while(node->left != NULL)
		node = node->left;
}

void minValueNode2(struct node **node){
	while((*node)->left != NULL)
		*node = (*node)->left;
}

int main(){
	struct node *root, *l1, *l2;
	root = (struct node *)malloc(sizeof(struct node));
	l1 = (struct node *)malloc(sizeof(struct node));
	l2 = (struct node *)malloc(sizeof(struct node));
	root->left = l1;
	l1->left = l2;
	l2->left = NULL;
	l1->data = 1;
	l2->data = 2;
	root->data =3;
	
	printf("%p", root);
	minValueNode(root);
	printf("\n%p", root);
	minValueNode2(&root);
	printf("\n%p", root);
}
