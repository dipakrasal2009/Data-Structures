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


class SinglyLL
{
	public :
		PNODE First;
		int iCount;

		SinglyLL();

		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no,int ipos);

		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);

		void Display();
		//int count();
};

SinglyLL :: SinglyLL()
{
	First = NULL;
	iCount = 0;
}

void SinglyLL :: InsertFirst(int no)
{
	PNODE newn = new NODE;

	newn -> data = no;
	newn -> next  = NULL;

	if (First == NULL)
	{
		First = newn;
		iCount++;
	}
	else
	{
		newn->next = First;
		First = newn;
		iCount ++;
	}

}

void SinglyLL :: InsertLast(int no)
{
	PNODE newn = new NODE;

	newn ->data = no;
	newn -> next = NULL;

	if (First == NULL)
	{
		First = newn;
		iCount++;
	}
	else
	{
		PNODE temp = First;

		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		iCount++;

	}	
}

void  SinglyLL :: InsertAtPos(int no,int iPos)
{
	PNODE newn = new NODE;

	newn->data = no;
	newn->next = NULL;

	if((iPos < 1)||(iPos > (iCount+1)))
	{
		cout<<"Invalid Position";
	}
	else if(iPos == 1)
	{
		InsertFirst(no);
	}
	else if(iPos == (iCount -1))
	{
		InsertLast(no);
	}
	else
	{
		PNODE temp = First;
		int i = 1;

		for(i = 1; i < iPos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;
		iCount ++;
	}
}

void SinglyLL :: DeleteFirst()
{
	PNODE temp = First;
	if(First == NULL)
	{
		cout<<"Linked List is empty nothing to delete\n";
		return;
	}
	else if(First->next == NULL)
	{
		delete(First);
		First = NULL;
		iCount--;
	}
	else
	{
		First = First->next;
		delete temp;
		iCount--;
	}
}

void SinglyLL :: DeleteLast()
{
	if(First == NULL)
	{
		return;
	}
	else if(First -> next == NULL)
	{
		delete First;
		First = NULL;
		iCount--;
	}
	else
	{
		PNODE temp = First;

		while(temp -> next ->next != NULL)
		{
			temp = temp ->next;
		}
		delete temp->next;
		temp->next = NULL;

		iCount--;
	}
}

void SinglyLL :: DeleteAtPos(int ipos)
{
	if ((ipos < 1)||(ipos > (iCount)))
	{
		cout <<"Invalid position\n";
			return;
	}
	else if(ipos == 1)
	{
		DeleteLast();
	}
	else if(ipos == iCount)
	{
		DeleteLast();
	}
	else
	{
		PNODE temp1 = First;

		for (int i = 1 ; i< ipos-1;i++)
		{
			temp1 = temp1->next;
		}
		PNODE temp2 = temp1->next;
		temp1->next  = temp2->next;
		delete temp2;
		iCount--;
	}

}
void SinglyLL :: Display()
{
	cout<<"Elements of linked list are : "<<"\n";
	PNODE temp = First;

	while(temp != NULL)
	{
		cout<<"|"<<temp->data<<"|->";
		temp = temp->next;
	}
	cout <<"NULL\n";

}



int main()
{

	SinglyLL obj1;


	cout <<sizeof(obj1)<<"\n";
	cout <<"First Pointer contains : "<<obj1.First<<"\n";
	cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

	obj1.InsertFirst(51);
	obj1.InsertFirst(21);
	obj1.InsertFirst(11);

	obj1.Display();

	cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

	obj1.InsertLast(101);
	obj1.InsertLast(111);
	obj1.InsertLast(121);

	obj1.Display();

	cout<<"Number of nodes are :"<<obj1.iCount<<"\n";

	obj1.InsertAtPos(201,5);
	obj1.InsertAtPos(1,1);
	obj1.InsertAtPos(71,4);
	obj1.Display();
	cout<<"Number of nodes are : "<<obj1.iCount<<"\n";

	obj1.DeleteFirst();
        obj1.Display();
        cout<<"Number of Nodes are : "<<obj1.iCount<<"\n";

	obj1.DeleteLast();
	obj1.Display();
	cout<<"Number of Nodes are : "<<obj1.iCount<<"\n";

	obj1.DeleteAtPos(3);
	obj1.Display();
        cout<<"Number of Nodes are : "<<obj1.iCount<<"\n";


	return 0;
}
