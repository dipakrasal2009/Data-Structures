#include<iostream>

using namespace std;

#pragma pack(1)
struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class DoublyLL
{
	public:
		PNODE First;
		int count;


		DoublyLL();

		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no, int ipos);

		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);

		void Display();
};

DoublyLL :: DoublyLL()
{
	First = NULL;
}

void DoublyLL :: InsertFirst(int no)
{
	PNODE newn = new NODE;

	newn -> next = NULL;
	newn-> data = no;
	newn-> prev = NULL;

	if(First == NULL)
	{
		First = newn;
		count++;
	}
	else
	{
		newn->next = First;
		(First)->prev = newn;
		First = newn;
		count++;
	}
}

void DoublyLL :: InsertLast(int no)
{
	PNODE newn = new NODE;
	PNODE temp = First;

	newn -> prev = NULL;
	newn-> data = no;
	newn -> next = NULL;

	if(First == NULL)
	{
		First = newn;
		count++;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newn;
		newn->prev = temp;
		count++;
	}
}


void DoublyLL :: Display()
{
	cout<<"Element of linked List are : \n";

	cout<<"NULL<=>";

	while(First != NULL)
	{
		cout<<"|"<<First->data<<"|<=>";
		First = First-> next;
	}
	cout<<"NULL\n";
}


void DoublyLL :: InsertAtPos(int no , int ipos)
{
	if((ipos < 1)|| (ipos > count))
	{
		cout<<"Invalid position\n";
		return;
	}
	else if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if (ipos == count)
	{
		InsertLast(no);
	}
	else
	{
		PNODE newn = new NODE;
		PNODE temp = First;
		newn->prev = NULL;
		newn-> data = no;
		newn->next =  NULL;

		for(int i = 1;i < ipos-1; i++)
		{
			temp = temp->next;
		}
		newn ->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		count++;
	}
}







int main()
{
	DoublyLL obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.Display();
	cout<<"Number of nodes in the linked List : "<<obj.count<<"\n";


	obj.InsertLast(101);
	obj.InsertLast(111);
	obj.InsertLast(121);
	obj.Display();
        cout<<"Number of nodes in the linked List : "<<obj.count<<"\n";

	obj.InsertAtPos(71,4);
	obj.Display();
	cout<<"Numebr of nodes in the linked list : "<<obj.count<<"\n";


	return 0;
}
