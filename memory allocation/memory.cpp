#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/*nice one thanks to vs codes continue working on it*/

using namespace std;

struct Student{
    char name[50];
    int rollno;
    int marks[5];
};
int main(){
    struct Student *studentPtr;

    int avg = 0;
    int no_of_student;
    printf("Enter the number of student: ");
    scanf("%d",&no_of_student);
    int sum[no_of_student];

    studentPtr = (struct Student*)malloc(no_of_student * sizeof(struct Student));

    for(int i=0;i<no_of_student;i++){
        printf("Enter name of student: ");
        scanf("%s",studentPtr[i].name);
        printf("Enter rollno: ");
        scanf("%d",&studentPtr[i].rollno);

        for(int j=0;j<5;j++){
            scanf("%d",&studentPtr[i].marks[j]);
            avg += studentPtr->marks[i];
        }
        sum[i]=avg/5;
    }

    for(int i=0;i<no_of_student;i++){
        printf("Student name: %s %d\n",studentPtr[i].name,i+1);
        printf("roll No. %d %d\n",studentPtr[i].rollno,i+1);
        printf("avg of there marks: %d\n",sum[i]);
    }
    system("pause");
    return 0;
}