#include<stdio.h>
#include"SDB.h"

// void SDB_APP(void);
// void SDB_action(uint8 ans);


int main(void)
{
    SDB_APP();
    return 0;
}


// This function displays the options available to the user and takes the input number corresponding to the action they want to do.
// SDB_APP then calls SDB_action and passes the input of the user to it
void SDB_APP(void)
{
    uint8 choice;
   
    printf("NOTE: MAX NUMBER OF STUDENTS IS 10\n");
    printf("\nWhat do you want to do?\nTo add entry, enter 1\nTo get used size in database, enter 2\n"); 
    printf("To read student data, enter 3\nTo get list of student IDs, enter 4\nTo check if ID exists, enter 5\nTo delete student data, enter 6\n");
    printf("To check if database is full, enter 7\nTo exit enter 0\n");
    scanf("%d",&choice);
    SDB_action(choice);
    // main->MAX[0].Student_ID;
    // main->top = -1;     
}

// SDb_action uses a switch-case to choose which function it should call based on the input of the user. 
// It then returns the main function (SDB_App) so that the user is prompted with the options again 
void SDB_action(uint8 ans)
{
    switch (ans)
    {
        case 1:
            SDB_AddEntry();
            return SDB_APP();
        case 2:
            SDB_GetUsedSize();
            return SDB_APP();
        case 3:
            printf("\nEnter ID of student you want to read: ");
            scanf("%d",&ID);
            SDB_ReadEntry(ID);
            return SDB_APP();
        case 4: 
            SDB_GetList(arr);
            return SDB_APP();
        case 5:
            printf("\nEnter ID of student you want to check: ");
            scanf("%d",&ID);
            printf("%d\n",SDB_IsIDExist(ID)); 
            return SDB_APP();
        case 6:
            printf("\nEnter ID of student you want to delete: ");
            scanf("%d",&ID);
            SDB_DeletEntry(ID); 
            return SDB_APP();
        case 7:
            printf("%d\n",SDB_IsFull());
            return SDB_APP();
        default:
            break;
    }
}