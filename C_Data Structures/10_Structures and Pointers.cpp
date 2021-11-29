#include <stdio.h>

struct student{
	int r_no;
	char name[20];
	char course[20];
	int fees;		
};

int main(){
	struct student *ptr, stud;
	ptr = &stud;

	printf("Enter the details of the student :");
	printf("\nEnter the Roll Number = ");
	scanf("%d", &ptr-> r_no);
	printf("\nEnter the Name = ");
	scanf("%s", ptr->name);
	printf("\nEnter the Course = ");
	scanf("%s", ptr->course);
	printf("\nEnter the Fees = ");
	scanf("%d", &ptr-> fees);

	printf("\nDETAILS OF THE STUDENT");
	printf("\nROLL NUMBER = %d", ptr -> r_no);
	printf("\nNAME = %s", ptr -> name);
	printf("\nCOURSE = %s", ptr -> course);
	printf("\nFEES = %d", ptr -> fees);
	
	return 0;
}

