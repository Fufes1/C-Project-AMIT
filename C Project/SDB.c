#include<stdio.h>
#include"SDB.h"
#include<stdlib.h>
// GetUsedSize simply displays the counter variable that is resposinble for counting when a student is added or subtracting when
// a student is deleted.
uint8 SDB_GetUsedSize(void)
{
    printf("\nUsed size is %d\n",counter);
}

//This function add a new student to the database. If this is the first time adding a student it will link the "Head" pointer to S1. 
// Otherwise it creates a temporary pointer and traverses the linked list until it reaches the last member of the list and add one after it.
boolean SDB_AddEntry(void)
{
    if(counter == 10)
    {
        return False;
    }
    else
    {
        if(counter == 0)
        {
            S1 = malloc(sizeof(student));
            Head = S1;
            S1->next = NULL;
            printf("Enter student year: ");
            scanf("%d", &S1->Student_year);
            printf("Enter student ID: ");
            scanf("%d", &S1->Student_ID);
            printf("Enter course(1) ID: ");
            scanf("%d", &S1->Course1_ID);
            printf("Enter course(1) grade: ");
            scanf("%d", &S1->Course1_grade);
            printf("Enter course(2) ID: ");
            scanf("%d", &S1->Course2_ID);
            printf("Enter course(2) grade: ");
            scanf("%d", &S1->Course2_grade);
            printf("Enter course(3) ID: ");
            scanf("%d", &S1->Course3_ID);
            printf("Enter course(3) grade: ");
            scanf("%d", &S1->Course3_grade);
            counter++;
            return True;
        }   
        else
        {
            student* newstudent = malloc(sizeof(student));
            student* temp = Head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newstudent;
            newstudent ->next = NULL;
            printf("Enter student year: ");
            scanf("%d", &newstudent->Student_year);
            printf("Enter student ID: ");
            scanf("%d", &newstudent->Student_ID);
            printf("Enter course(1) ID: ");
            scanf("%d", &newstudent->Course1_ID);
            printf("Enter course(1) grade: ");
            scanf("%d", &newstudent->Course1_grade);
            printf("Enter course(2) ID: ");
            scanf("%d", &newstudent->Course2_ID);
            printf("Enter course(2) grade: ");
            scanf("%d", &newstudent->Course2_grade);
            printf("Enter course(3) ID: ");
            scanf("%d", &newstudent->Course3_ID);
            printf("Enter course(3) grade: ");
            scanf("%d", &newstudent->Course3_grade);
            counter++;
            // printf("%d", Head->next->Student_year);
            return True;
        }
    }
}

//The max number of students in the database is 10. This function checks if the counter is equal to 10 or not.
boolean SDB_IsFull(void)
{
    
    if(counter==10)
    {
        counter--;
        return True;
    }
    else
    return False;
}

// This function deletes a student from the database. If the student is is the first member of the linked list the Head pointer is 
// redefined to point to the one after it. Otherwise it traverses the list till it find the student and deletes it and connect the list back together.
void SDB_DeletEntry(uint32 ID)
{
    student* temp = Head;
    student* prev;
    if (counter == 3)
    {
        printf("\nCannot delete, student minumum number of students is three");
        return;
    }
    else
    {
        if(temp != NULL && temp->Student_ID == ID)
        {
            Head = temp->next;
            free(temp);
            counter--;
            return;
        }
        while(temp != NULL && temp->Student_ID != ID)
        {
            if(temp == NULL)
            {
            return;
            }
            prev = temp;
            temp = temp->next;
        }
        counter--;
        free (temp);
    }
}

// This function traverses the list till it finds the ID of the student and prints the student's entered data
boolean SDB_ReadEntry(uint32 ID)
{
    student* temp = Head;
    while(temp != NULL && temp->Student_ID != ID)
    {
        if(temp == NULL)
        {
        return False;
        }
        temp = temp->next;
    }
    
    printf("Student year: %d\n", temp->Student_year);
    printf("Student ID: %d\n", temp->Student_ID);
    printf("Course(1) ID: %d\n", temp->Course1_ID);
    printf("Course(1) grade: %d\n", temp->Course1_grade);
    printf("Course(2) ID: %d\n", temp->Course2_ID);
    printf("Course(2) grade: %d\n", temp->Course2_grade);
    printf("Course(3) ID: %d\n", temp->Course3_ID);
    printf("Course(3) grade: %d\n", temp->Course3_grade);
    return True;
}

// This function traverses the list and stores the id of each student in an array and the prints the array
void SDB_GetList(uint32 arr[10])
{
    student* temp = Head;
    uint8 c = 0;
    while(temp != NULL)
    {
        // printf("%d\n", temp->Student_ID);
        arr[c] = temp->Student_ID;
        c++;
        temp = temp->next;
        // printf("%d\n",c);
    }
    for(uint8 i = 0;i<c;i++)
    {
        printf("%d \t",arr[i]);
    }
}

// This function traverses the list till it finds the ID the user wants. If it finds it, it will return 1. If not, return 0.
boolean SDB_IsIDExist(uint32 ID)
{
    student* temp  = Head;
    while(temp != NULL)
    {
        if (temp->Student_ID == ID)
        {
            return True;
        }
        temp = temp->next;
        
    }
    return False;
}
