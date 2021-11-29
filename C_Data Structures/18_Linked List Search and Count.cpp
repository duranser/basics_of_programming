#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void insertFront( struct Node**,int);
int getCount( struct Node *head);   
void printList(struct Node*);
bool search(struct Node *, int);

int main(){
	struct Node *head = NULL;
	
	insertFront(&head, 7);
	insertFront(&head, 1);
	insertFront(&head, 3);
	insertFront(&head, 2);
	insertFront(&head, 8);
	
	printf("Created Linked List: ");
	printList(head);
	printf("\n\nCount of nodes is: %d", getCount(head));
	printf("\n\nSearch a value if you want: ");
	int x;
	scanf("%d",&x);
	search(head, x)? printf("Yes"):printf("No");
	
}

void insertFront( struct Node **head_ref ,int new_data){
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

int getCount( struct Node *head){
	int count=0;
	struct Node *current = head;
	while( current != NULL){
		count++;
		current=current->next;
	}
	return count;
}

bool search(struct Node *head, int x){
	struct Node *current;
	current = head;
	
	while( current != NULL){
		if(current->data == x)
			return 1;
		current = current->next;
	}
	return 0;
}

void printList(struct Node *node){
	while( node != NULL ){
		printf("%d ", node->data);
		node = node->next;
	}
}
