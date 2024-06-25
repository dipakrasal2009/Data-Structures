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
	PNODE newn = (PNODE) malloc(sizeof(NODE));

	newn -> data = no;
	newn -> next = NULL;
	if (*First == NULL)
	{
		*First = newn;
	}
	else
	{
		newn->next = *First;
		*First = newn;
	}
}

void InsertLast(PPNODE First, int no)
{
	PNODE newn = (PNODE)malloc(sizeof(NODE));
	PNODE temp = *First;
	newn-> data = no;
	newn-> next = NULL;

	if (*First == NULL)
	{
		*First = newn;
	}
	else
	{
		while(temp -> next != NULL)
		{
			temp = temp->next;
		}
		temp -> next = newn;
	}


}


void Display(PNODE First)
{
        printf("element of the node is : \n");
        while(First != NULL)
        {
                printf("| %d |=>",(First)->data);
                First = (First) -> next;
        }
        printf("NULL\n");
}

int nodecount(PNODE First)
{
        int iCnt = 0;

        while(First != NULL)
        {
                iCnt++;
                First = First->next;
        }
        return iCnt;
}

void InsertAtPos(PPNODE First,int no, int pos)
{
	int NodeCount = 0,iCnt = 0;
	PNODE newn = NULL;
	PNODE temp = NULL;

	NodeCount = nodecount(*First);

	if((pos < 1)||(pos > (NodeCount + 1)))
	{
		printf("Invalid position\n");
	}
	return;

	if (pos == 1)
	{
		InsertFirst(First,no);
	}
	else if(pos  == NodeCount + 1)
	{
		InsertLast(First,no);
	}
	else
	{
		PNODE newn = (PNODE) malloc(sizeof(NODE));

		newn->data = no;
		newn->next = NULL;

		temp = *First;

		for(iCnt = 1;iCnt < pos-1;iCnt++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
	}

}


void deleteFirst(PPNODE First)
{
	PNODE temp =*First;
	if(*First == NULL)
	{
		printf("Linked list is empty\n");
		return;
	}
	else if((*First) -> next == NULL)
	{
		free(*First);
		*First = NULL;
	}
	else
	{
		(*First) = (*First)->next;
		free(temp);
	}
}


void DeleteLast(PPNODE First)
{
	PNODE temp = *First;

	if(*First == NULL)
	{
		printf("Linked list is empty\n");
	}
	else if((*First)->next == NULL)
	{
		free(*First);
		*First = NULL;
	}
	else
	{
		while(temp ->next->next != NULL)
		{
			temp = temp->next;
		}
		free(temp->next);
		temp->next = NULL;
	}
}
		

void DeleteAtPos(PPNODE First,int pos)
{
	PNODE temp1 = NULL;
	PNODE temp2 = NULL;

	int NCnt = 0;
	int i = 0;

	NCnt = nodecount(*First);

	if((pos < 1)||(pos > (NCnt-1)))
	{
		printf("INVALID POSITION\n");
		return;
	}

	if(pos == 1)
	{
		deleteFirst(First);
	}
	else if(pos == NCnt-1)
	{
		DeleteLast(First);
	}
	else
	{
		temp1 = *First;
		for(i = 1; i<pos-1;i++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		free(temp2);
	}
}




int main()
{
 	PNODE Head = NULL;
	int Ret = 0;

	InsertFirst(&Head,11);
	InsertFirst(&Head,10);
	InsertFirst(&Head,9);
	InsertLast(&Head,22);
	InsertLast(&Head,23);
	//InsertAtPos(&Head,20,3);
	//deleteFirst(&Head);
	//DeleteLast(&Head);
	DeleteAtPos(&Head,3);
	Display(Head);
	Ret = nodecount(Head);
	printf("number of nodes are the linked list : %d ",Ret);

	return 0;
}
