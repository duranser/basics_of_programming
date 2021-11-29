#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *f(struct node *x){
	if( x->next != NULL)
		x = f(x->next);
	return x;
}

int main(){
	struct node *x, *y, *z, *t, *k, *m;
	x = (struct node *)malloc(sizeof(struct node));
	y = (struct node *)malloc(sizeof(struct node));
	z = (struct node *)malloc(sizeof(struct node));
	t = (struct node *)malloc(sizeof(struct node));
	x->next = y, y->next = z, z->next = t, t->next = NULL;
	x->data = 1, y->data = 2, z->data = 3, t->data = 4;
	
	k = f(x);
	printf("%d", k->data);
	
}

