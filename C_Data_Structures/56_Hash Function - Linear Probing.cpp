#include <stdio.h>

int hash[10]; // hash table
int i;     // Probe
int key;

void insert_val();
void search_val();
void delete_val();
void display();


int main(){
	int option=0;
	for(i=0; i<10; i++)
		hash[i] = -1;   // NULL
	
	while(option != 5){
		printf( "\n *****HASHING***** \n1.Insert \n2.Search \n3.Delete \n4.Display \n5.Exit");
		printf("\nEnter your option: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert_val();
				break;
			case 2:
				search_val();
				break;
			case 3:
				delete_val();
				break;
			case 4:
				display();
				break;
			default:
				printf("\nInvalid choice entry!\n");
				break;
		}
	}
	return 0;
}

void insert_val(){
	int val, i = 0;
	printf("\nEnter the element to be inserted: ");
	scanf("%d", &val);
	key = val%10;
	if(hash[key] == -1){
		hash[key] = val;
	}
	else{   // Linear Probing
		for(i = key+1; i<10; i++){
			if(hash[i] == -1){
				hash[i] = val;
				break;
			}
		}
		for(i=0; i<key; i++){
			if(hash[i] == -1){
				hash[i] = val;
				break;
			}
		}
	}
}
	
void display(){
	for(int i=0; i<10; i++)
		printf("\t%d", hash[i]);
}

void search_val(){
	int val, i, flag=0;
	printf("\nEnter the element to be searched: ");
	scanf("%d", &val);
	key = val%10;
	if(hash[key] == val)
		flag=1;
	else{
		for(i=key+1; i<10; i++){
			if(hash[i] == val){
				flag=1;
				key=i;
				break;
			}
		}
		if(flag == 0){
			for(i=0; i<key; i++){
				if(hash[key] == val){
					flag=1;
					key=i;
					break;
				}
			}
		}
	}
	if(flag==1)
		printf("\nThe item searched was found at position %d", key);
	else{
		key = -1;
		printf("\nThe item searched was NOT found");
	}
}

void delete_val(){
	search_val();
	if(key != -1){
		printf("\nThe element deleted is %d ", hash[key]);
		hash[key] = -1;
	}
	else
		printf("\nThe item searched was NOT found");
}






