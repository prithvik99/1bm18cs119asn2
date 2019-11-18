#include<stdio.h>
#include<conio.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node *Node;
Node getnode()
{
	Node temp;
	temp=(Node)malloc(sizeof(struct node));
	return temp;
}
Node insert_end(Node first,int item)
{
	Node temp;
	Node curr=first;
	temp=getnode();
	temp->data=item;
	temp->next=NULL;
	temp->prev=NULL;
	if(first==NULL)
	return temp;
	else
	{
		while(curr->next!=NULL)
		curr=curr->next;
	      //	curr->next=temp;
		temp->prev=curr;
		curr->next=temp;
		temp->next=NULL;
	}
	return first;
}
Node insert_pos(Node first)
{

	Node temp,curr,p;
	 int count,num,val;
	 printf("Enter the data:\n");
	 scanf("%d",&num);
	 printf("Enter the value of node\n");
	 scanf("%d",&val);
	curr=first;
	temp=getnode();
	temp->data=num;
	temp->prev=NULL;
	temp->next=NULL;
	while(curr!=NULL)
		{
			if(curr->data==val)
			break;
			curr=curr->next;
		}
		if(curr==NULL)
		{printf("key not found\n");
		return first;
		}
		if(curr==first)
		{
		temp->next=first;
		first->prev=temp;
		first=temp;
		return first;
		}
		 p=curr->prev;
		 p->next=temp;
		 temp->prev=p;
		 curr->prev=temp;
		 temp->next=curr;
		 return first;

}
Node delete_pos(Node first,int item)
{
     //	int count=1;
	Node curr=first;
	while(curr!=NULL)
	{
	     //	count=count+1;
		if(curr->data==item)
		{
			(curr->prev)->next=curr->next;
			(curr->next)->prev=curr->prev;
			free(curr);
			break;
		}
		else
		curr=curr->next;
	}
	if(curr->next==NULL&&curr->data!=item)
	printf("invalid value\n");
	return first;
}
void display(Node first)
{
	Node temp=first;
	if(first==NULL)
	printf("LIST EMPTY\n");
	else
	{
		while(temp!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void main()
{
	Node first;
	int item,n,i;
	i=1;
	clrscr();
	while(1)
	{
		printf("1.Create doubly linked list\n");
		printf("2.insert a new node to the left of the node\n");
		printf("3.delete the node based on a specific value\n");
		printf("4.display\n");
		printf("5.exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			printf("Enter 0 to stop\n");
			printf("Enter data:\n");
			scanf("%d",&i);
			while(i!=0)
			{
			first=insert_end(first,i);
			printf("enter data:\n");
			scanf("%d",&i);
			}
			break;
			case 2:
		      //	printf("enter position of node to insert new node\n");
		       //	scanf("%d",&i);
		       //	printf("enter value\n");
		       //	scanf("%d",&item);
			first=insert_pos(first);
			break;
			case 3:
			printf("Enter value to be deleted\n");
			scanf("%d",&item);
			first=delete_pos(first,item);
			break;
			case 4:
			printf("LIST:\n");
			display(first);
			break;
			case 5:
			exit(0);

			}
		}
	}

