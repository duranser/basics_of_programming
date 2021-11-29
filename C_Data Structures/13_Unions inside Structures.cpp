#include <stdio.h>


typedef struct{
	union{
		char name[20];
		int roll_no;
	};
	int marks;
}student;


int main(){
	student stud;
	char choice;
	printf("You can enter the name or roll number of the student.");
	printf("\nDo you want to enter the name? (Y or N): ");
	scanf("%c",&choice);
	if (choice=='y' || choice=='Y'){
		printf("Enter the name: ");
		scanf("%s",stud.name);
	}
	else{
		printf("\nEnter the roll number: ");
		scanf("%d",&stud.roll_no);
	}
	printf("\nEnter the marks: ");
	scanf("%d",&stud.marks);
	if(choice=='y' || choice=='Y')
		printf("\nname: %s", stud.name);
	else
		printf("\nMarks: %d",stud.roll_no);
	printf("\nMarks: %d", stud.marks);
	
	return 0;
}

