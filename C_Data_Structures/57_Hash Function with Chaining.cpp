#include <stdio.h>
#include <stdlib.h>

struct node{
	int key;
	int value;
	struct node *next;
};

struct arrayitem{     // Storing a LL at Hash Table
	struct node *head;
	struct node *tail;
};


struct arrayitem *array;
int size = 0;    // Number of elements present in hash table
int max = 10;    // Capacity of hash table



void init_array();
int hashcode(int key);
void insert(int key, int value);
void rehash();
int find(struct node *list, int key);
struct node *get_element(struct node *list, int find_index);
void remove_element(int key);
void display();


int main(){
	int choice=0, key, value, n;
	array = (struct arrayitem*)malloc(max * sizeof(struct arrayitem*));
	init_array();
	while(choice != 5){
		printf("HASH TABLE Chaining with Singly Linked List \n\n");
		printf("MENU : \n1.Inserting item"
                              "\n2.Removing item"
                              "\n3.Check the size" 
                              "\n4.Display"
		       "\n\n Please enter your choice -: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Inserting element in Hash Table\n");
				printf("Enter key and value:\t");
				scanf("%d %d", &key, &value);
				insert(key, value);
				break;
			case 2:
				printf("Deleting in Hash Table \nEnter the key to delete:");
		    	scanf("%d", &key);
		        remove_element(key);
		        break;
			case 3:
				n = size;
				printf("Size of Hash Table is: %d\n", n);
				break;
			case 4:
				display();
				break;
		}
	}
	return 0;
}



void init_array(){
	int i = 0;
	for(i=0; i<max; i++){
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}

int hashcode(int key){
	return (key%max);
}

void insert(int key, int value){
	float n = 0.0;    // load factor for rehashing
	
	int index = hashcode(key);
	
	struct node *list = (struct node *)array[index].head;  // ???
	
	struct node *item = (struct node*)malloc(sizeof(struct node));
	item->key = key;
	item->value = value;
	item->next = NULL;
	
	if(list == NULL){
		printf("Inserting %d(key) and %d(value)\n", key, value);
		array[index].head = item;
		array[index].tail = item;
		size ++;
	}
	else{   // A LL is present
		int find_index = find(list, key);
		if(find_index == -1){  // Key not found in LL
			array[index].tail->next = item;
			array[index].tail = item;
			size++;
		}
		else{   // Key already present in LL
			struct node *element = get_element(list, find_index);
			element->value = value;
		}
	}
	n = (1.0*size)/max;
	if(n >= 0.75){
		printf("going to rehash\n");
		rehash();
	}
}

void rehash(){
	struct arrayitem *temp = array;
	
	int i = 0;
	int n = max;
	size = 0;
	max = 2*max;
	
	array = (struct arrayitem*)malloc(max * sizeof(struct node));
	init_array();
	
	for(i=0; i<n; i++){
		struct node *list = (struct node*)temp[i].head;
		if(list == NULL){
			continue;
		}
		else{
			while(list != NULL){
				insert(list->key, list->value);
				list = list->next;
			}
		}
	}
	temp = NULL;
}

int find(struct node *list, int key){
	int retval = 0;
	struct node *temp = list;
	while(temp != NULL){
		if(temp->key == key)
			return retval;
		temp = temp->next;
		retval++;
	}
	return -1;
}

struct node *get_element(struct node *list, int find_index){
	// returns the node (LL item) located at given index
	int i=0;
	struct node *temp = list;
	while(i != find_index){
		temp = temp->next;
		i++;
	}
	return temp;
}

void remove_element(int key){
	int index = hashcode(key);
	struct node *list = (struct node*)array[index].head;
	if(list == NULL){
		printf("This key does not exist\n");
	}
	else{
		int find_index = find(list, key);
		if(find_index == -1)
			printf("This key does not exist\n");
		else{
			struct node *temp = list;
			if(temp->key == key){
				array[index].head = temp->next;
				printf("This key has been removed\n");
				return;
			}
			
			while(temp->next->key != key){
				temp = temp->next;
			}
			
			if(array[index].tail == temp->next){
				temp->next = NULL;
				array[index].tail = temp;
			}
			else{
				temp->next = temp->next->next;
			}
			
			printf("This key has been removed\n");
		}
	}
}

void display(){
	int i=0;
	for(i=0; i<max; i++){
		struct node *temp = array[i].head;
		if(temp==NULL)
			printf("array[%d] has no elements\n", i);
		else{
			printf("array[%d] has elements: ", i);
			while(temp != NULL){
				printf("key=%d  value=%d\t", temp->key, temp->value);
				temp = temp->next;
			}
			printf("\n");
		}
	}
}



