// Singly Linear Linked List 

//Operations : InsertFirst,InsertLast,InsertATPosition     DeleteFirst,DeleteLast,DeleteATPosition      Display     Count

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,int no)
{
    printf("Insert First\n");
    PNODE newn = (PNODE)malloc (sizeof(NODE));

    newn-> data = no;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}



void InsertLast(PPNODE First,int no)
{
    printf("Insert Last\n");

    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *First;

    newn->data = no;
    newn->next = NULL;

    if(First == NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

}

void InsertAtPos(PPNODE First,int no,int ipos)
{
    printf("Insert At Position\n");

    int NodeCnt = 0,iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt= Count(*First);

    if((ipos < 1)||(ipos > (NodeCnt+1)))
    {
        printf("Invalid position\n");
        return;
    }
    

    if(ipos == 1)
    {
        InsertFirst(First,no);
    }
    else if(ipos == NodeCnt+1)
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *First;

        for(iCnt = 1;iCnt < ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn ->next = temp->next;
        temp->next = newn;
    }


}

void DeleteFirst(PPNODE First)
{
    printf("Delete First\n");

    PNODE temp = *First;

    if(*First== NULL)
    {
        printf("linked list is empty\n");
        return;
    }
    else if((*First)->next==NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        (*First)=(*First)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    printf("Delete Last\n");
    PNODE temp = *First;

    if(*First == NULL)
    {
        printf("linked list is empty\n");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First= NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void DeleteAtPos(PPNODE First,int ipos)
{
    printf("Delete At Position\n");
    int NodeCnt = 0,iCnt=0;

    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1)||(ipos > NodeCnt))
    {
        printf("invalid Positiom\n");
        return;
    }
    else if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for(iCnt = 1;iCnt < ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        free(temp2);
    }

}

void Display(PNODE First)
{
    printf("element of the linked list are : \n");

    while(First != NULL)
    {
        printf("| %d |->",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

int main()
{
    printf("\n Singly linear linked list\n\n");
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,2);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    InsertFirst(&Head,1);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    InsertLast(&Head,4);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    InsertLast(&Head,5);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    InsertAtPos(&Head,3,3);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    InsertAtPos(&Head,10,5);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    DeleteAtPos(&Head,2);
    Display(Head);
    iRet = Count(Head);
    printf("There are %d element in the linked list\n\n",iRet);

    return 0;
}