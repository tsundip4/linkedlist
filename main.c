#include <stdio.h>
#include <stdlib.h>

/* double linked list using C*/

struct node{
    struct node* previous;
    int data;
    struct node* next;

};

struct node* Head= NULL;


struct node* createdoublelink()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(Head == NULL){
        Head = temp;
    }

    printf("take the data please\n");
    scanf("%d", &temp->data);
    temp->previous = NULL;
    temp->next = NULL;
    return(temp);
}

void adddoublenode()
{

    struct node* temp1;
    temp1 = createdoublelink();

    Head->previous = temp1;
    temp1->next = Head;

    Head = temp1;


}

void display()
{
    struct node* temp3;
    temp3 = Head;

    while(temp3!=NULL){
        printf("%d>>", temp3->data);
        temp3 = temp3->next;
    }
    printf("\n");
}

void deletefirstnode()
{
    struct node* dfirst;
    dfirst = Head;

    Head = dfirst->next;
    dfirst->previous =Head;

    free(dfirst);

}

void insertnnode()
{
    int position, i;
    struct node* temp1=NULL;
    struct node* temp2=Head;
    struct node* temp;

    printf("insert the position\n");
    scanf("%d", &position);

    temp = createdoublelink();

    for(i=0; i<position-1; i++){
        temp1 = temp2;
        temp2 = temp2->next;
    }
    temp->previous = temp1;
    temp1->next = temp;
    temp->next = temp2;
    temp2->previous = temp;
}

void reverse()
{
    struct node* rev;
    rev = Head;

    while(rev->next!=NULL){
        rev = rev->next;
    }


    while(rev != NULL){
        printf("%d>>", rev->data);
        rev = rev->previous;
    }
    printf("\n");
}

int main()
{
    int choice;

    while(1){
        printf("press 1 for createdouble node\n");
        printf("press 2 for addnode\n");
        printf("press 3 for display node\n");
        printf("press 4 for first node delete\n");
        printf("press 5 for reverse display\n");
        printf("press 6 for insert node at any place\n");

        scanf("%d", &choice);

        switch(choice){

    case 1:
        createdoublelink();
        break;

    case 2:
        adddoublenode();
        break;

    case 3:
        display();
        break;

    case 4:
        deletefirstnode();
        break;

    case 5:
        reverse();
        break;

    case 6:
        insertnnode();
        break;

    default :
        printf("invalid entry\n");
        break;
        }
    }
}
