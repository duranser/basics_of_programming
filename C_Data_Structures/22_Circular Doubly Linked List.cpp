#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_list(struct node *);

int main(){
	int option;
	while( option != 9){
		printf("\n\n *****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");
		printf("\n 5: Delete a node from the beginning");
		printf("\n 6: Delete a node from the end");
		printf("\n 7: Delete a given node");
		printf("\n 8: Delete the entire list");
		printf("\n 9: EXIT");
		printf("\n\nEnter your option: ");
		scanf("%d", &option);
		
		switch(option){
			case 1: start = create_ll(start); printf("\nCIRCULARLY DOUBLY LINKED LIST CREATED"); break;
			case 2: start = display(start); break;
			case 3: start = insert_beg(start); break;
			case 4: start = insert_end(start); break;
			case 5: start = delete_beg(start); break;
			case 6: start = delete_end(start); break;
			case 7: start = delete_node(start); break;
			case 8: start = delete_list(start); break; printf("\nCIRCULARLY DOUBLY LINKED LIST DELETED"); break;
		}
	}
	
	return 0;
}

struct node *create_ll(struct node *){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter -1 to end");
	printf("\nEnter the data: ");
	scanf("%d", &num);
	while(num != -1){
		if(start == NULL){
			new_node =(struct node *)malloc(sizeof(struct node));
			new_node->data = num;
			new_node->prev = NULL;
			start = new_node;
			new_node->next = start;
			}
		else{
			new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = num;
			ptr = start;
			while(ptr->next != start)
			ptr = ptr->next;
			new_node->prev = ptr;
			ptr->next = new_node;
			new_node->next = start;
			start->prev = new_node;
		}
		printf("\nEnter the data: ");
		scanf("%d", &num);
	}
	return start;
}

struct node *display(struct node *){
	struct node *ptr;
	ptr = start;
	while( ptr->next != start){
		printf("\t%d", ptr->data);
		ptr = ptr->next;
	}
	
	return start;
}

struct node *insert_beg(struct node *){
	struct node *new_node, *ptr;
	int num;
	printf("\nEnter the data: ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	while(ptr->next != start)
		ptr = ptr->next;
	new_node->prev = ptr;
	ptr->next = new_node;
	new_node->next = start;
	start->prev = new_node;
	start = new_node;
	
	return start;
}
struct node *insert_end(struct node *){
	struct node *new_node, *ptr;
	int num;
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = num;
	ptr = start;
	while( ptr->next != start)
		ptr = ptr->next;
	ptr->next = new_node;
	new_node->next = start;
	new_node->prev = ptr;
	start->prev = new_node;
	
	return start;
}

struct node *delete_beg(struct node *){
	struct node *ptr, *temp;
	ptr = start;
	while(ptr->next != start)
		ptr = ptr->next;
	ptr->next = start->next;
	temp = start;
	start = start->next;
	start->prev = ptr;
	free(temp);
	
	return start;
}

struct node *delete_end(struct node *){
	struct node *ptr;
	ptr=start;
	while(ptr -> next != start)
		ptr = ptr -> next;
	ptr -> prev -> next = start;
	start -> prev = ptr -> prev;
	free(ptr);
	
	return start;
	
}
struct node *delete_node(struct node *){
	struct node *ptr;
	int val;
	printf("\n Enter the value of the node which has to be deleted : ");
	scanf("%d", &val);
	ptr = start;
	if(ptr -> data == val){
		start = delete_beg(start);
	return start;
	}
	else{
		while(ptr -> data != val)
		ptr = ptr -> next;
		ptr -> prev -> next = ptr -> next;
		ptr -> next -> prev = ptr -> prev;
		free(ptr);
	return start;
	}
}

struct node *delete_list(struct node *){
	struct node *ptr;
	ptr = start;
	while(ptr -> next != start)
		start = delete_end(start);
	free(start);
	return start;
}

