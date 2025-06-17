/*WAP to define a C structure named Student (roll_no, name, branch and 
batch_no) and also to access the structure members using Pointer.*/
#include <stdio.h>
#include <stdlib.h>  // for malloc

struct student {
    int roll_no;
    char name[30];
    char branch[10];
    int batch_no;
};

void main() {
    struct student *stu1;

    stu1 = (struct student*)malloc(sizeof(struct student));
    
    if (stu1 == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", stu1->name);

    printf("Enter student roll no: ");
    scanf("%d", &stu1->roll_no);

    printf("Enter student branch: ");
    scanf("%s", stu1->branch);

    printf("Enter student batch no: ");
    scanf("%d", &stu1->batch_no);

    printf("\nStudent Details:\n");
    printf("Name: %s\n", stu1->name);
    printf("Roll No: %d\n", stu1->roll_no);
    printf("Branch: %s\n", stu1->branch);
    printf("Batch No: %d", stu1->batch_no);

    free(stu1); 
}
