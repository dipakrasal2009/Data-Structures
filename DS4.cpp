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

class DoublyCL
{
	public:
		PNODE First;
		PNODE Last;
		int count;

		DoublyCL();

		void InsertFirst(int no);
		void InsertLast(int no);
		void InsertAtPos(int no , int ipos);

		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int ipos);

		void Display();
};

DoublyCL :: DoublyCL()
{
	First = NULL;
	Last = NULL;
}

void DoublyCL :: InsertFirst(int no)
{
	PNODE newn = new NODE;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;

	if((First == NULL)&&(Last == NULL))
	{
		First = Last = newn;
		Last->next = First;
		First->prev = Last;
		count++;
	}
	else
	{
		//Last = First->prev;
		newn->next = First;
		newn->prev = Last;
		Last -> next = newn;
		First->prev = newn;
		First = newn;
		count++;
	}
}

void DoublyCL :: Display()
{
	cout<<"element of the linked List are : \n";

	cout<<"NULL<=>";

	do
	{
		cout<<"|"<<First->data<<"|<=>";
		First = First->next;
	}while(First != Last);
	cout<<"NULL\n";
}


int main()
{
	DoublyCL obj;

	obj.InsertFirst(51);
	obj.InsertFirst(21);
	obj.InsertFirst(11);
	obj.InsertFirst(1);
	obj.Display();
	cout<<"Number of nodes in the linked list  are : "<<obj.count<<"\n";

	return 0;

}

