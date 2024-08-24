#ifndef SDB_FN_DECLARE
#define SDB_FN_DECLARE

#include"STD.h"

//Struct variable for each student
typedef struct SimpleDb
{
uint32 Student_ID;
uint32 Student_year;
uint32 Course1_ID;
uint32 Course1_grade;
uint32 Course2_ID;
uint32 Course2_grade;
uint32 Course3_ID;
uint32 Course3_grade;
struct SimpleDb* next;                                
}student;

//Important Variables
static student* Head = NULL;
static student* S1;
static uint8 counter;
uint32 ID;
uint32 arr[10];


//Functions

void SDB_APP(void);
void SDB_action(uint8 ans);
boolean SDB_IsFull(void);
boolean SDB_AddEntry(void);
void traverse_print(student* head);
void SDB_DeletEntry(uint32 ID);
boolean SDB_ReadEntry(uint32 ID);
void SDB_GetList(uint32 arr[10]);
boolean SDB_IsIDExist(uint32 ID);
uint8 SDB_GetUsedSize(void);


 

#endif
