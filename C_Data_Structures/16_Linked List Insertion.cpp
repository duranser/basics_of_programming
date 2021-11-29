#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void insertFront(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void insertEnd(struct Node** head_ref, int new_data);
void printList(struct Node *node);

int main(){
	struct Node *head = NULL;
	
	insertEnd(&head, 6);
	insertFront(&head, 7);
	insertFront(&head, 1);
	insertEnd(&head, 4);
	insertAfter(head->next, 8);
	
	printf("\nCreated Linked list is: ");
	printList(head);
	
	printf("\n%d",head->next->next->data);
}

void insertFront(struct Node** head_ref, int new_data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;   // Double Pointer (pointer to pointer)
	*head_ref = new_node;         // Header pointerý deðiþmiþ oldu.
}

void insertAfter(struct Node* prev_node, int new_data){
	if(prev_node == NULL){
		printf("The given previous node cannot be NULL");
		return;
	}
	
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void insertEnd(struct Node** head_ref, int new_data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if(*head_ref == NULL){
		*head_ref = new_node;
		return;
	}
	while(last->next != NULL){
		last = last->next;
	}
		
	last->next = new_node;
	return;
}

void printList(struct Node *n){
	while(n!=NULL){
		printf("%d ",n->data);
		n=n->next;
	}
}

