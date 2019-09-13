#include<iostream>
#include<stdlib.h>
using namespace std;

void insertBegin();
void insertBeforePosition();
void insertAtPosition();
void insertAfterPosition();
void insertBeforeKey();
void insertAfterKey();
void insertLast();

void deleteBegin();
void deleteBeforePosition();
void deleteAtPosition();
void deleteAfterPosition();
void deleteBeforeKey();
void deleteAtKey();
void deleteAfterKey();
void deleteLast();

void search();
void display();

struct node
{
	int data;
	struct node *next;
};
struct node *head;
int main()
{
	int choice=0;
	while(choice!=18)
	{
		cout<<"\n------------------MENU-----------------";
		cout<<"\n1) INSERT AT BEGIN\n2)INSER BEFORE POSITION\n3) INSERT AT SPECIFIED POSITION\n4) INSERT AFTER SPECIFIED POSITION\n5)INSERT BEFORE KEY VALUE\n6) INSERT AFTER KEY VALUE\n7) INSERT AT LAST\n8) DELETE AT BEGIN\n9) DELETE BEFORE SPECIFIED POSITION\n10) DELETE AT SPECIFIED POSITION\n11) DELETE AFTER SPECIFIED POSITION\n12) DELETE BEFORE KEY VALUE\n13) DELETE AT KEY VALUE\n14)  DELETE AFTER KEY VALUE\n15)DELETE AT LAST\n16) SEARCH VALUE IN LINKED LIST\n17) DISPLAY ALL VALUE IN LINKED LIST\n18) EXIT";
		cout<<"\nENTER YOUR CHOICE: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				insertBegin();
				break;
			case 2:
				insertBeforePosition();
				break;
			case 3:
				insertAtPosition();
				break;
			case 4:
				insertAfterPosition();
				break;
			case 5:
				insertBeforeKey();
				break;
			case 6:
				insertAfterKey();
				break;
			case 7:
				insertLast();
				break;
			case 8:
				deleteBegin();
				break;
			case 9:
				deleteBeforePosition();
				break;
			case 10:
				deleteAtPosition();
				break;
			case 11:
				deleteAfterPosition();
				break;
			case 12:
				deleteBeforeKey();
				break;
			case 13:
				deleteAtKey();
				break;
			case 14:
				deleteAfterKey();
				break;
			case 15:
				deleteLast();
				break;
			case 16:
				search();
				break;
			case 17:
				display();
				break;
			case 18:
				exit(1);
				break;
			default:
				cout<<"\nENTER VALID CHOICE.";
				break;
		}
	}
	return 0;
}
void insertBegin()
{
	struct node *newnode,*temp;
	int value;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}
	else
	{
		cout<<"\nENTER VALUE: ";
		cin>>value;
		newnode->data=value;
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
			cout<<"\nVALUE IS INSERTED AT BEGIN.";
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			head=newnode;
			cout<<"\nVALUE INSERTED AT BEGIN.";
		}
	}
}
void insertBeforePosition()
{
	struct node *newnode,*temp,*ptr;
	int value,position;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}	
	else
	{
		cout<<"\nENTER VALUE: ";
		cin>>value;
		newnode->data=value;
		cout<<"\nENTER POSITION BEFORE WHICH YOU WANT TO INSERT VALUE.";
		cin>>position;
		temp=head;
		for(int i=0;i<position-2;i++)
		{
			ptr=temp;
			if(ptr==NULL)
			{
				cout<<"\nVALUE CAN'T INSERTED.";
				return;		
			}	
			temp=temp->next;
		}
		newnode->next=temp;
		ptr->next=newnode;
		cout<<"\nVALUE INSERTED BEFORE POSITION: "<<position;
	}
}
void insertAtPosition()
{
	struct node *newnode,*temp,*ptr;
	int value,position;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}	
	else
	{
		cout<<"\nENTER VALUE: ";
		cin>>value;
		newnode->data=value;
		cout<<"\nENTER POSITION AT WHICH YOU WANT TO INSERT VALUE.";
		cin>>position;
		temp=head;
		for(int i=0;i<position-1;i++)
		{
			ptr=temp;
			if(ptr==NULL)
			{
				cout<<"\nVALUE CAN'T INSERTED.";
				return;		
			}	
			temp=temp->next;
		}
		newnode->next=temp;
		ptr->next=newnode;
		cout<<"\nVALUE INSERTED BEFORE POSITION: "<<position;
	}
}
//final
void insertAfterPosition()
{
	struct node *newnode,*temp;
	int value,position;
	newnode=(struct node *)malloc(sizeof(struct node));
	
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}	
	else
	{
		cout<<"\nENTER VALUE: ";
		cin>>value;
		newnode->data=value;
		cout<<"\nENTER POSITION AFTER WHICH YOU WANT TO INSERT VALUE.";
		cin>>position;
		temp=head;
		for(int i=0;i<position-1;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				cout<<"\nVALUE CAN'T INSERTED.";
				return;		
			}	
		}
		newnode->next=temp->next;
		temp->next=newnode;
		cout<<"\nVALUE INSERTED AFTER POSITION: "<<position;
	}
}
void insertBeforeKey()
{
	struct node *newnode,*temp;
	int value,key;
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"\nENTER KEY VALUE: ";
	cin>>key;
	cout<<"\nENTER VALUE: ";
	cin>>value;
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}
	else
	{
		temp=head;	
		while(temp->next->data!=key)
		{
			temp=temp->next;
		}
		newnode->data=value;
		newnode->next=temp->next;
		temp->next=newnode;
		cout<<"\nVALUE INSERTED BEFORE KEY VALUE.";
	}
	
}

void insertAfterKey()
{
	struct node *newnode,*temp;
	int value,key;
	newnode=(struct node *)malloc(sizeof(struct node));
	cout<<"\nENTER KEY VALUE: ";
	cin>>key;
	cout<<"\nENTER VALUE: ";
	cin>>value;
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}
	else
	{
		temp=head;	
		while(temp->data!=key)
		{
			temp=temp->next;
		}
		newnode->data=value;
		newnode->next=temp->next;
		temp->next=newnode;
		cout<<"\nVALUE INSERTED AFTER KEY VALUE.";
	}
		
}
void insertLast()
{
	struct node *newnode,*temp;
	int value;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		cout<<"\nOVERFLOW.";
		return;
	}
	else
	{
		cout<<"\nENTER VALUE: ";
		cin>>value;
		newnode->data=value;
		if(head==NULL)
		{
			head=newnode;
			newnode->next=head;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				temp=temp->next;
			}
			newnode->next=head;
			temp->next=newnode;
			
		}
		cout<<"\nVALUE IS INSERTED AT LAST.";
	}
}
void deleteBegin()
{
	struct node *temp;
	if(head==NULL)
	{
		cout<<"\nUNDERFLOW.";
		return;
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		cout<<"\nNODE DELETED FROM BEGIN.";
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		free(head);
		head=temp->next;//or comment above statemant and write head=head->next;
		cout<<"\nNODE DELETED FROM BEGIN.";
	}
}
void deleteBeforePosition()
{
	struct node *temp,*ptr;
	int position;
	if(head==NULL)
	{
		cout<<"\nLIST IS EMPTY.";
		return;
	}
	else
	{
		temp=head;
		cout<<"\nENTER POSITION BEFORE WHICH NODE IS DELETE: ";
		cin>>position;
		
		for(int i=0;i<position-2;i++)
		{
			ptr=temp;
			temp=temp->next;
			if(ptr==NULL)
			{
				cout<<"\nCAN'T DELETED.";
				return;
			}
		}
		ptr->next=temp->next;
		free(temp);
		cout<<"\nNODE DELETED BEFORE POSITION "<<position;
	}
}
void deleteAtPosition()
{
	struct node *temp,*ptr;
	int position;
	if(head==NULL)
	{
		cout<<"\nLIST IS EMPTY.";
		return;
	}
	else
	{
		temp=head;
		cout<<"\nENTER POSITION AT WHICH NODE IS DELETE: ";
		cin>>position;
		
		for(int i=0;i<position-1;i++)
		{
			ptr=temp;
			temp=temp->next;
			if(ptr==NULL)
			{
				cout<<"\nCAN'T DELETED.";
				return;
			}
		}
		ptr->next=temp->next;
		free(temp);
		cout<<"\nNODE DELETED BEFORE POSITION "<<position;
	}
}
void deleteAfterPosition()
{
	struct node *temp,*ptr;
	int position;
	if(head==NULL)
	{
		cout<<"\nLIST IS EMPTY.";
		return;
	}
	else
	{
		temp=head;
		cout<<"\nENTER POSITION AFTER WHICH NODE IS DELETE: ";
		cin>>position;
		
		for(int i=0;i<position;i++)
		{
			ptr=temp;
			temp=temp->next;
			if(ptr==NULL)
			{
				cout<<"\nCAN'T DELETED.";
				return;
			}
		}
		ptr->next=temp->next;
		free(temp);
		cout<<"\nNODE DELETED AFTER POSITION "<<position;
	}
}

void deleteBeforeKey()
{
	struct node *temp,*ptr;
	int key;
	cout<<"\nENTER KEY VALUE: ";
	cin>>key;
	if(head==NULL)
	{
		cout<<"\nUNDERFLOW.";
		return;
	}
	else
	{
		temp=head;	
		while(temp->next->data!=key)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=temp->next;//->next=temp->next->next;
		free(temp);
		cout<<"\nNODE DELETED BEFORE KEY VALUE.";
	}
		
}
void deleteAtKey()
{
	struct node *temp;
	int key;
	cout<<"\nENTER KEY VALUE: ";
	cin>>key;
	if(head==NULL)
	{
		cout<<"\nUNDERFLOW.";
		return;
	}
	else
	{
		temp=head;	
		while(temp->next->data!=key)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		free(temp);
		cout<<"\nNODE DELETED AT KEY VALUE.";
	}
		
}

void deleteAfterKey()
{
	struct node *temp,*ptr;
	int key;
	cout<<"\nENTER KEY VALUE: ";
	cin>>key;
	if(head==NULL)
	{
		cout<<"\nUNDERFLOW.";
		return;
	}
	else
	{
		temp=head;	
		while(temp->data!=key)
		{
			temp=temp->next;
			ptr=temp->next;
		}
		temp->next=ptr->next;
		free(ptr);
		cout<<"\nNODE DELETED AFTER KEY VALUE.";
	}
		
}

void deleteLast()
{
	struct node *temp,*ptr;
	if(head==NULL)
	{
		cout<<"\nUNDERFLOW.";
		return;
	}
	else if(head->next==head)
	{
		head=NULL;
		free(head);
		cout<<"\nNODE DELETED FROM LAST.";
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=temp->next;
		free(temp);
		cout<<"\nNODE DELETED FROM LAST.";
	}
}

void display()
{
	struct node *temp;
	if(head==NULL)
	{
		cout<<"\nLIS IS EMPTY.";
		return;
	}
	else
	{
		temp=head;
		while(temp->next!=head)
		{
			cout<<temp->data<<"  ";
			temp=temp->next;
		}
		cout<<temp->data<<"  ";
	}
}

void search()
{
	struct node *temp;
	int value,position=0,flag=0;
	cout<<"\nENTER VALUE THAT YOU WANT TO FIND IN LIST: ";
	cin>>value;
	if(head==NULL)
	{
		cout<<"\nLIST IS EMPTY SO NO SEARCH IS FOUND IN LIST.";
		return;
	}
	else
	{
		if(head->data==value)
		{
			cout<<"\nVALUE FOUND IN LIST AT POSITION: "<<position+1;
			flag=0;
			return;
		}
		else
		{
			temp=head;
			while(temp->next!=head)
			{
				if(temp->data==value)
				{
					cout<<"\nVALUE FOUND IN LIST AT POSITION: "<<position+1;
					flag=0;
					return;
				}
				else
				{
					flag=1;
				}
				position++;
				temp=temp->next;
			}
			if(temp->data==value)
			{
				cout<<"\nVALUE FOUND IN LIST AT POSITION: "<<position+1;
			}
		}
		if(flag!=0)
		{
			cout<<"\nVALUE NOT FOUND IN LIST.";
		}
	}
}
