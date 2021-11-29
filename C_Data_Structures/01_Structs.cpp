#include <stdio.h>
#include <conio.h>

int main() {
	struct student {
		int roll_no;
		char name[80];
		float fees;
		char DOB[80];
	};
	struct student stud1;

	printf("Enter the roll number: ");
	scanf("%d", &stud1.roll_no);
	printf("\nEnter the name: ");
	scanf("%s", stud1.name);
	printf("\nEnter the fees: ");
	scanf("%f", &stud1.fees);
	printf("Enter the DOB: ");
	scanf("%s", stud1.DOB);
	printf("\n%s\n%s%d\n%s%s\n%s%f\n%s%s",
		"**********STUDENT'S DETAILS************",
		"ROLL No.=", stud1.roll_no,
		"NAME = ", stud1.name,
		"FEES = ", stud1.fees,
		"DOB = ", stud1.DOB);
		
	getch();
}
