// Doubly Circuler LinkedList

#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node * prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}

void Display(PNODE First)
{
    printf("element from the linked list are\n");

    printf("NULL<=>");

    while(First != NULL)
    {
        printf("|%d|<=>",First->data);
        First = First -> next;
    }
    printf("NULL\n");
}

int count(PNODE First)
{
    int iCnt = 0;

    while(First != NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

void InsertLast(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    PNODE temp = *First;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }

    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteFirst(PPNODE First)
{
    if(*First == NULL)                   //Empty LINKED LIST
    {
        printf("Empty LinkedList\n");
        return;
    }
    else if((*First)->next == NULL)        //linkedList contains at least one element
    {
        free(*First);
        *First = NULL;
    }
    else                               //LinkedList contains more than one element
    {
        *First = (*First)->next;
        free((*First)->prev);
        (*First)->prev = NULL;
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;
    if(*First == NULL)
    {
        printf("LL iS Empty\n");
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE First,int no,int ipos)
{
    int NodeCnt = 0,iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    NodeCnt = count(*First);

    if((ipos < 1)||(ipos > (NodeCnt+1)))
    {
        printf("Invalid position\n");
        return;
    }
    if(ipos == 1)
    {
        InsertFirst(First,no);
    }
    else if(ipos == (NodeCnt+1))
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn ->data = no;
        newn ->next = NULL;
        newn ->prev = NULL;

        temp = *First;

        for(iCnt = 1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

void DeleteAtPos(PPNODE First,int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;
    int iCnt = 0,NodeCnt = 0;
    NodeCnt = count(*First);

    if((ipos < 1)||(ipos > (NodeCnt+1)))
    {
        printf("Invalid position\n");
        return;
    }
    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos < NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1=*First;
        for(iCnt = 1; iCnt < NodeCnt-1;iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2=temp2->next;

        temp1->next = temp2->next;
        temp2->next->prev=temp1;
        free(temp2);
    }
}

int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,11);
    InsertFirst(&Head,10);
    InsertFirst(&Head,22);
    InsertFirst(&Head,33);
    Display(Head);
    iRet = count(Head);
    printf("element are the linkedlist  are : %d\n",iRet);

    InsertLast(&Head,12);
    InsertLast(&Head,13);
    Display(Head);
    iRet = count(Head);
    printf("element are the linkedlist  are : %d\n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = count(Head);
    printf("element are the linkedlist  are : %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = count(Head);
    printf("element are the linkedlist  are : %d\n",iRet);
    
    InsertAtPos(&Head,5,2);
    Display(Head);
    iRet = count(Head);
    printf("element are the linkedlist  are : %d\n",iRet);

    DeleteAtPos(&Head,2);
    Display(Head);
    iRet = count(Head);
    printf("element are the linkedlist  are : %d\n",iRet);

    return 0;
}