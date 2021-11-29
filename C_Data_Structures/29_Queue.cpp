#include <stdio.h>

#define MAX 10   // Altering length of queue

int queue[MAX];
int front = -1;   // Eleman sildiðinde front indisi artýrýlýr.
int rear = -1;    // Eleman eklediðinde rear indisi artýrýlýr.

void insert();
int delete_element();
int peek();
void display();

int main(){
	int option, val;
	while(option != 5){
		printf("\n\n ***** MAIN MENU *****");
		printf("\n 1. Insert an element: ");
		printf("\n 2. Delete an element: ");
		printf("\n 3. Peek: ");
		printf("\n 4. Display the queue: ");
		printf("\n 5. EXIT");
		printf("\n Enter your option : ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert();
				break;
			case 2:
				val = delete_element();
				if (val != -1)
				printf("\n The number deleted is : %d", val);
				break;
			case 3:
				val = peek();
				if (val != -1)
				printf("\n The first value in queue is : %d", val);
				break;
			case 4:
				display();
				break;
		}
	}
	return 0;
}

void insert(){
	int num;
	printf("\nEnter the number to be inserted in the queue");
	scanf("%d", &num);
	if(rear == MAX-1)
		printf("\nOVERFLOW");
	else if(front == -1 && rear == -1)
		front = rear = 0;
	else
		rear++;
	queue[rear] = num;
}

int delete_element(){
	int val;
	if(front == -1 || front>rear){
		printf("\nUNDERFLOW");
		return -1;
	}
	else{
		val = queue[front];
		front++;
		if(front>rear)
			front = rear = -1;
		return val;
	}
}

int peek(){
	if(front == -1 || front>rear){
		printf("\nQUEUE IS EMPTY");
		return -1;
	}
	else{
		return queue[front];
	}
}

void display(){
	int i;
	printf("\n");
	if(front == -1 || front > rear)
		printf("\n QUEUE IS EMPTY");
	else{
		for(i = front; i<= rear; i++)
			printf("\t%d", queue[i]);	
	}
}
