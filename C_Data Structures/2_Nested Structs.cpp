#include <stdio.h>


int main() {
	struct DOB{
		int day, month, year;
	};
	struct student {
		int roll_no;
		char name[100];
		float fees;
		struct DOB date;
	};
	struct student stud1;
	
	printf("Enter the roll number: ");
	scanf("%d", &stud1.roll_no);
	printf("\nEnter the name: ");
	scanf("%s", stud1.name);
	printf("\nEnter the fees: ");
	scanf("%f", &stud1.fees);
	printf("Enter the DOB: ");
	scanf("%d %d %d", &stud1.date.day, &stud1.date.month,&stud1.date.year);
		
	printf("\n ********STUDENT'S DETAILS *******");
	printf("\n ROLL No. = %d", stud1.roll_no);
	printf("\n NAME = %s", stud1.name);
	printf("\n FEES = %f", stud1.fees);
	printf("\n DOB = %d – %d – %d", stud1.date.day, stud1.date.month, stud1.date.year);

}
