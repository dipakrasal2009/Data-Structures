#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
	int data;
	struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCL
{
	public:
		PNODE First;
		PNODE Last;
		int count;

		SinglyCL();

		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no , int ipos);

		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);

		void Display();
		int Count();
};

SinglyCL :: SinglyCL()
{
	First = NULL;
	Last = NULL;
	count = 0;
}

void SinglyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;

	newn->data = no;
	newn->next = NULL;

	if((First == NULL)&&(Last == NULL))
	{
		First = Last = newn;
		Last->next = First;
		count++;
	}
	else
	{
		newn->next = First;
		First = newn;
		(Last)->next = First;
		count++;
	}
}
void SinglyCL :: InsertLast(int no)
{
	PNODE newn = new NODE;

	newn->data = no;
	newn->next = NULL;

	if ((First == NULL)&&(Last == NULL))
	{
		First = Last = newn;
		(Last)->next = First;
		count++;

	}
	else
	{
		Last -> next = newn;
		Last = newn;
		Last->next = First;
		count++;
	}

}
void SinglyCL :: InsertAtPos(int no , int ipos)
{
	if((ipos < 1)||(ipos > count+1))
	{
		cout<<"INvalid position\n";
	}
	else if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == count+1)
	{
		InsertLast(no);
	}
	else
	{
		PNODE newn = new NODE;
		PNODE temp = First;

		newn->data = no;
		newn->next = NULL;

		for(int i = 1;i < ipos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp -> next;
		temp -> next = newn;
		count++;
	}
}
void SinglyCL :: DeleteFirst()
{
	PNODE temp = First;

	if((First == NULL)&&(Last == NULL))
	{
		cout<<"linked list is empty nothing to delete\n";
		return;
	}
	else if (First == Last)
	{
		delete First;
		First = NULL;
		Last = NULL;
		count--;

	}
	else
	{
		First = (First)->next;
		delete temp;

		(Last)->next = First;
		count--;
	}
}
void SinglyCL :: DeleteLast()
{
	PNODE temp = First;

	if((First == NULL)&&(Last == NULL))
	{
		return;
	}
	else if(First == Last)
	{
		delete First;

		First =  NULL;
		Last = NULL;
		count--;

	}
	else
	{
		while(temp->next != Last)
		{
			temp = temp->next;
		}
		delete temp->next;

		Last = temp;
		Last ->next = First;
		count--;
	}

}
void SinglyCL :: DeleteAtPos(int ipos)
{
	int iCnt = 0;
	PNODE temp1 = First;
	PNODE temp2 = NULL;
	if ((ipos < 1)||(ipos > count + 1))
	{
		cout<<"Invalid Position\n";
		return;

	}

	else if(ipos == 1)
	{
		DeleteFirst();
	}
	else if (ipos == count)
	{
		DeleteLast();
	}
	else
	{
		for(iCnt = 1;iCnt < ipos-1; iCnt ++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		delete temp2;
		count--;
	}

}
void SinglyCL :: Display()
{
	PNODE temp = First;

	cout<<"Element of the linked list are : \n";
	do
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}while (temp != Last->next);
	cout<<"NULL\n";

}


int main()
{
	SinglyCL obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.Display();
	cout<<"Number of nodes are the linked list : "<<obj.count<<"\n";

	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.Display();
	cout<<"Number of nodes are the linked list : "<<obj.count<<"\n";

	obj.InsertAtPos(71,4);
 	obj.Display();
        cout<<"Number of nodes are the linked list : "<<obj.count<<"\n";	

	obj.DeleteFirst();
 	obj.Display();
        cout<<"Number of nodes are the linked list : "<<obj.count<<"\n";


	obj.DeleteLast();
	obj.Display();
        cout<<"Number of nodes are the linked list : "<<obj.count<<"\n";

	obj.DeleteAtPos(2);
	 obj.Display();
        cout<<"Number of nodes are the linked list : "<<obj.count<<"\n";
	return 0;
}

