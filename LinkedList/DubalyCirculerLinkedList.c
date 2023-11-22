// Doubly Cerculer linked list 
#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node     //define structure
{
    int data;
    struct node * next;
    struct node * prev;
};

// new names of structures
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//insert first node in linked list
void InsertFirst(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));// dynamic memory allocation

    newn->data = no;
    newn-> next = NULL;
    newn->prev = NULL;

    if(*First == NULL)//    LL is Empty
    {
        *First = newn;
    }
    else    // LL Contain at least 1 element
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
    }
}

// Display linked list
void Display(PNODE First)
{
    printf("element of the linked list are \n");

    printf("NULL<=> ");

    while(First != NULL)
    {
        printf("| %d | <=>",First->data);
        First=First->next;
    }
    printf("NULL \n");
}

// insert last Function
void InsertLast(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));   // Dynamic memory allocation
    PNODE Temp=*First;

    newn->data = no;
    newn->next=NULL;
    newn->prev=NULL;

    if(First == NULL)//ll is empty
    {
        *First = newn;
    }
    else//LL contains at least 1 element
    {
        while(Temp->next!=NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
    }

}

//     count the nodes of linked list
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


// Insert at that position in linked list
void InsertAtPos(PPNODE First,int no,int ipos)
{
    int NodeCnt = 0,iCnt= 0;
    PNODE newn= NULL;
    PNODE Temp = NULL;

    NodeCnt = Count(*First);

    if((ipos < 1)||(ipos>(NodeCnt+1)))
    {
        printf("Invalid poosition\n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(First,no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        Temp = *First;

        for(iCnt = 1;iCnt< ipos-1;iCnt++)
        {
            Temp = Temp->next;
        }

        newn->next = Temp->next;
        Temp->next->prev = newn;
        Temp->next = newn;
        newn->prev = Temp;
    }
}

void DeleteFirst(PPNODE First)
{
    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else{
        *First = (*First)->next;
        free((*First)->prev);
        (*First)->prev = NULL;
    }
}

void DeleteLast(PPNODE First)
{
    PNODE Temp = *First;

    if(*First == NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        *First = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE First,int ipos)
{
    PNODE Temp1 = NULL;
    PNODE Temp2 = NULL;
    int iCnt = 0,NodeCnt = 0;
    NodeCnt = Count(*First);

    if((ipos < 1) || (ipos > NodeCnt))
    {
        printf("Invalid Position\n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(First);
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        Temp1 = *First;
        for(iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            Temp1 = Temp1->next;
        }

        Temp2 = Temp1 ->next;
        Temp1->next = Temp2->next;
        Temp2->next->prev = Temp1;
        free(Temp2);
    }
}



int main()
{

    printf("\n\nDoubly Circuler linked List start\n\n");
    PNODE Head = NULL;

    int iRet = 0;

    InsertFirst(&Head,11);
    Display(Head);
    iRet = Count (Head);
    printf("Number of element are : %d\n",iRet);


    InsertFirst(&Head,10);
    Display(Head);
    iRet = Count (Head);
    printf("Number of element are : %d\n",iRet);

    InsertLast(&Head,5);
    Display(Head);
    iRet = Count (Head);
    printf("Number of element are : %d\n",iRet);

    InsertLast(&Head,2);
    Display(Head);
    iRet = Count (Head);
    printf("Number of element are : %d\n",iRet);

    InsertAtPos(&Head,8,3);
    Display(Head);
    iRet = Count(Head);
    printf("Number of element are : %d\n",iRet);

    DeleteFirst(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of element are : %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet = Count(Head);
    printf("Number of element are : %d\n",iRet);

    DeleteAtPos(&Head,2);
    Display(Head);
    iRet = Count(Head);
    printf("Number of element are : %d\n",iRet);

    printf("\nEnd of the linked list \n");
    return 0;
}
