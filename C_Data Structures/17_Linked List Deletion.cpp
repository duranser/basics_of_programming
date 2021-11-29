#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void insertFront( struct Node**,int);
void deleteNode(struct Node**, int);   // Finding value
void deleteNode2(struct Node**, int);  // Finding position
void printList(struct Node*);

int main(){
	struct Node *head = NULL;
	
	insertFront(&head, 7);
	insertFront(&head, 1);
	insertFront(&head, 3);
	insertFront(&head, 2);
	insertFront(&head, 8);
	
	printf("Created Linked List: ");
	printList(head);
	deleteNode(&head, 1);
	deleteNode2(&head, 2);
	printf("\n\nLinked List after Deletion of value 1 and position 2 : ");
	printList(head);
	
}

void insertFront( struct Node **head_ref ,int new_data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void deleteNode(struct Node **head_ref, int key){   // Deleting at given value
	struct Node *temp = *head_ref;
	struct Node *prev;
	
	if( temp != NULL && temp->data == key ){  // If head node is wanted to be deleted
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	while( temp != NULL && temp->data != key ){
		prev = temp;
		temp = temp->next;
	}
	
	if( temp==NULL)    // If the node to be deleted was not found 
	return;
	
	prev->next = temp->next;
	
	free(temp);
}

void deleteNode2(struct Node **head_ref, int position){   // Deleting at given position
	if( *head_ref == NULL)   // If list is empty
		return;
	
	struct Node *temp = *head_ref;
	
	if(position == 0){
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	for(int i=0; temp != NULL && i<position-1; i++)  // Find previous node of the node to be deleted
		temp = temp->next;
		
	if( temp == NULL || temp->next == NULL)   // If position is more than number of nodes
		return;
		
	struct Node *next = temp->next->next;
	
	free(temp->next);
	temp->next = next;  // Unlink the deleted node from list
}

void printList(struct Node *node){
	while( node != NULL ){
		printf("%d ", node->data);
		node = node->next;
	}
}
