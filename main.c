#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ARRAY_SIZE 10

typedef char* string;
typedef struct StudentData StudentData;
struct StudentData{
    char name[ARRAY_SIZE];
    StudentData *next;
};

typedef struct List List;
struct List{
    StudentData *first;
};

List *initialisation();
void insertion(List *list, char stdName[]);
void insertionAuMilieu(List *list, char stdSearched[], char newStd[]);
void dltNewLine(char name[]);
void deleteStd(List *list, char stdSearched[]);
void printStds(List *list);



int main(){
    int nbrDesEtd = 0, i = 0;
    char name[ARRAY_SIZE];
    char stdSearched[ARRAY_SIZE];
    char newStd[ARRAY_SIZE];

    List *myList = initialisation();

    printf("Enter the number of students : ");
    scanf("%d", &nbrDesEtd);
    for(i; i < nbrDesEtd; i++)
    {
        fflush(stdin);
        printf("Enter the name of student %d : ", i+1);
        fgets(name, ARRAY_SIZE, stdin);
        /* delete the new line */
        dltNewLine(name);
        /* Sending the name into insertion function to insert student's name */
        insertion(myList, name);
    }
    /* Adding in the middle */
    printf("What's the name of the new student -> ");
    fgets(newStd, ARRAY_SIZE, stdin);
    fflush(stdin);
    printf("Where you wanna put the new student -> ");
    fgets(stdSearched, ARRAY_SIZE, stdin);
    fflush(stdin);
    dltNewLine(newStd);
    dltNewLine(stdSearched);

    insertionAuMilieu(myList, stdSearched, newStd);

    /* Deleting an element */
    printf("Enter student's name that you wanna delete : ");
    fgets(stdSearched, ARRAY_SIZE, stdin);
    dltNewLine(stdSearched);
    fflush(stdin);
    deleteStd(myList, stdSearched);
    deleteStd(myList, "");

    /* Printing students */
    printStds(myList);
}

List *initialisation(){
    /* Creating instances */
    List *list = (List *)malloc(sizeof(*list));
    StudentData *student = (StudentData *)malloc(sizeof(*student));

    if(list == NULL || student == NULL)
        exit(EXIT_FAILURE);
    /* initializing */
    strcpy(student->name, "");
    student->next = NULL;
    list->first = student;

    return list;
}

void insertion(List *list, char stdName[])
{
    /* Creating an instance of new student */
    StudentData *newStudent = (StudentData *)malloc(sizeof(*newStudent));

    if(list == NULL || newStudent == NULL)
        exit(EXIT_FAILURE);
    /* Affecting the name to the student */
    strcpy(newStudent->name, stdName);
    newStudent->next = list->first;
    list->first = newStudent;
}

void insertionAuMilieu(List *list, char stdSearched[], char newStd[])
{
    StudentData *newStudent = (StudentData *)malloc(sizeof(*newStudent));
    StudentData *temp = list->first;

    if(list == NULL || newStudent == NULL)
        exit(EXIT_FAILURE);
    while((strcmp(temp->next->name, stdSearched) != 0) && (temp->next != NULL)) {
        temp = temp->next;
    }
    if(temp->next != NULL)
    {
        strcpy(newStudent->name, newStd);
        newStudent->next = temp->next;
        temp->next = newStudent;
    }
}

void printStds(List *list)
{
    StudentData *currentStd = list->first;

    if(list == NULL)
        exit(EXIT_FAILURE);
    while(currentStd != NULL)
    {
        printf("%s -> ", currentStd->name);
        currentStd = currentStd->next;
    }
    printf("END OF STUDENTS\n");
}

void deleteStd(List *list, char stdSearched[])
{
    StudentData *aSupprimer = NULL;
    if(list == NULL)
        exit(EXIT_FAILURE);
    if(strcmp(list->first->name, stdSearched) == 0)
    {
        aSupprimer = list->first;
        list->first = list->first->next;
        free(aSupprimer);
    }
    else
    {
        StudentData *temp = list->first;

        while((strcmp(temp->next->name, stdSearched) != 0) && (temp->next != NULL))
            temp = temp->next;
        if(temp->next != NULL)
        {
            aSupprimer = temp->next;
            temp->next = temp->next->next;
            free(aSupprimer);
        }
    }
}

void dltNewLine(char name[])
{
    int i = 0;

    for(i; i < ARRAY_SIZE; i++)
    {
        if(name[i] == '\n')
            name[i] = 0;
    }

}