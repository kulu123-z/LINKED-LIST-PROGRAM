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
	struct node *prev;
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
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	int value;
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
			newnode->prev=NULL;
			newnode->next=NULL;
			head=newnode;
		}
		else
		{
			newnode->prev=NULL;
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
		cout<<"\nVALUE IS INSERTED AT BEGIN.";
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
		newnode->prev=ptr;
		ptr->next=newnode;
		temp->prev=newnode;
		cout<<"\nVALUE INSERTED BEFORE POSITION: "<<position;
	}
}
void insertAtPosition()
{
	struct node *newnode,*ptr,*temp;
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
		cout<<"\nENTER POSITION AT WHICH YOU WANT TO INSERT VALUE: ";
		cin>>position;
		newnode->data=value;
		if(head==NULL)
		{
			cout<<"\nNODE IS NOT INSERTED BECAUSE LIST IS ALLREADY EMPTY.";
		}
		else
		{
			temp=head;
			for(int i=0;i<position-1;i++)
			{
				ptr=temp;
				temp=temp->next;
				if(ptr==NULL)
				{
					cout<<"\nVALUE CAN'T INSERTED BEFORE POSITION: "<<position;
					return;
				}
			}
			newnode->next=temp;//newnode->next=temp->next;
			newnode->prev=ptr;//newnode->prev=temp;
			ptr->next=newnode;//temp->next=newnode;
			temp->prev=newnode;//temp->next->prev=newnode;

			cout<<"\nVALUE INSERTED AT POSITION: "<<position;
		}	
	}
}

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
		cout<<"\nENTER POSITION AFTER WHICH YOU WANT TO INSERT VALUE: ";
		cin>>position;
		newnode->data=value;
		if(head==NULL)
		{
			newnode->prev=NULL;
			newnode->next=NULL;
			head=newnode;	
			cout<<"\nVALUE INSERTED AFTER POSITION: "<<position;
		}
		else
		{
			temp=head;
			for(int i=0;i<position-1;i++)
			{
				temp=temp->next;
				if(temp==NULL)
				{
					cout<<"\nVALUE CAN'T INSERTED AFTER POSITION: "<<position;
					return;
				}
			}
			newnode->next=temp->next;
			newnode->prev=temp;
			temp->next=newnode;
			temp->next->prev=newnode;

			cout<<"\nVALUE INSERTED AFTER POSITION: "<<position;
		}	
	}
}

void insertBeforeKey()
{
	struct node *newnode,*temp;;
	int value,key;
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
		cout<<"\nENTER KEY VALUE BEFORE WHICH YOU WANT TO STORE VALUE: ";
		cin>>key;
		if(head==NULL)
		{
			cout<<"\nVALUE IS NOT INSERTED BECAUSE LIST IS ALLREADY EMPTY.";
			return;
		}
		else if(head->data==key)
		{
			newnode->next=head;
			newnode->prev=NULL;
			head=newnode;
		}
		else
		{
		
			temp=head;
			while(temp->next->data!=key)
			{
				temp=temp->next;
			}
			newnode->next=temp->next;
			newnode->prev=temp;
			temp->next->prev=newnode;
			temp->next=newnode;
		}
		cout<<"\nVALUE IS INSERTED BEFORE KEY VALUE.";
	}
}
//final

void insertAfterKey()
{
	struct node *newnode,*temp;;
	int value,key;
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
		cout<<"\nENTER KEY VALUE AFTER WHICH YOU WANT TO STORE VALUE: ";
		cin>>key;
		temp=head;
		while(temp->data!=key)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		newnode->prev=temp;
		temp->next->prev=newnode;
		temp->next=newnode;
		cout<<"\nVALUE IS INSERTED AFTER KEY VALUE.";
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
			newnode->next=NULL;
			newnode->prev=NULL;
			head=newnode;
			cout<<"\nVALUE INSERTED AT LAST.";
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			newnode->next=NULL;
			newnode->prev=temp;
			temp->next=newnode;
		}
	}
}
void deleteBegin()
{
	struct node *temp;
	if(head==NULL)
	{
		cout<<"\nLIST IS ALLREADY EMPTY.";
		return;
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		cout<<"\nNODE DELETED FROM BEGIN.";
	}
	else
	{
		temp=head;
		head=temp->next;
		head->prev=NULL;
		free(temp);
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
		temp->next->prev=ptr;
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
		cout<<"\nENTER POSITION BEFORE WHICH NODE IS DELETE: ";
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
		temp->next->prev=ptr->next;
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
		temp->next->prev=ptr->next;
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
		temp->next->prev=ptr;
		free(temp);
		cout<<"\nNODE DELETED BEFORE KEY VALUE.";
	}
		
}
void deleteAtKey()
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
			ptr=temp;
			temp=temp->next;
		}
		ptr->next=temp->next;
		temp->next->prev=ptr;
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
		ptr->next->prev=temp;
		free(ptr);
		cout<<"\nNODE DELETED AFTER KEY VALUE.";
	}
		
}
void deleteLast()
{
	struct node *temp;
	if(head==NULL)
	{
		cout<<"\nLIST IS ALLREADY EMPTY.";
		return;
	}
	else if(head->next==NULL)
	{
		
		head=NULL;
		free(head);
		cout<<"\nNODE DELETED FROM LAST.";
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
		free(temp);
		cout<<"\nNODE DELETED FROM LAST.";
	}
}
void search()
{
	struct node *temp;
	int value,i,flag;
	cout<<"\nENTER NUMBER THAT YOU WANT TO FIND IN LIST: ";
	cin>>value;
	if(head==NULL)
	{
		cout<<"\nLIST IS EMPTY.\nSEARCHING IS NOT POSSIBLE.";
		return;
	}
	else
	{
		i=0;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==value)
			{
				cout<<"\nVALUE IS FOUNDED IN LIST AT POSITION: "<<i+1;
				flag=0;
				break;
			}
			else
			{
				flag=1;
			}
			i++;
			temp=temp->next;
		}
		if(flag==1)
		{
			cout<<"\nVALUE IS NOT FOUND IN LIST.";
		}
	}
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		cout<<"\nLIST IS EMPTY.";
		return;
	}
	else
	{
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}
