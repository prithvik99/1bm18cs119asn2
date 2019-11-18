#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node * NODE;
NODE getnode();
NODE del_val(NODE head,int val);
NODE insert_front(NODE head,int item);
NODE insert_left(NODE head,int item,NODE n);
void display(NODE head);
NODE getnode()
{
NODE p;
p=(NODE)malloc(sizeof(struct node));
if(p!=NULL)
return p;
else
{
printf("Insufficieant memory\n");
exit(0);
}
}
NODE insert_front(NODE head,int item)
{
NODE newn;
newn=getnode();
newn->data=item;
newn->prev=NULL;
if(head==NULL)
{
newn->next=NULL;
head=newn;
}
else
{
newn->next=head;
head->prev=newn;
head=newn;
}
return head;
}
NODE insert_left(NODE head,int item,NODE n)
{
NODE newn;
newn=getnode();
newn->data=item;
if(n->prev==NULL)
{
newn->next=n;
n->prev=newn;
newn->prev=NULL;
head=newn;
}
else
{
n->prev->next=newn;
newn->prev=n->prev;
newn->next=n;
n->prev=newn;
}
return head;
}
NODE del_val(NODE head,int val)
{
NODE p=head;
if(head==NULL)
{
printf("list is empty\n");
return head;
}
if(head->next==NULL)
{
if(head->data==val)
{
free(head);
return NULL;
}
else
{
printf("value not found\n");
return head;
}
}
while(p!=NULL)
{
if(p->data==val)
{
if(p->next==NULL)
{
p->prev->next==NULL;
free(p);
return head;
}
else
{
p->prev->next=p->next;
p->next->prev=p->prev;
free(p);
return head;
}
}
p=p->next;
}
if(p==NULL)
{
printf("value not found\n");
return head;
}
}

void display(NODE head)
{
NODE p;
if(head==NULL)
{
printf("list is empty\n");
exit(0);
}
p=head;
while(p!=NULL)
{
printf("%d\n", p->data);
p=p->next;
}
}
int main()
{
NODE head=NULL;
NODE p;
int ch,item,n,i,c,val,pos,x;
printf("Enter\n1.Create a doubly linked list\n2.Insert node to the left of given node\n3.Delete a node based on specific value\n4.Display\n5.Exit");
scanf("%d",&ch);
while(1)
{
switch(ch)
{
case 1:printf("Enter the no.of items\n");
scanf("%d",&n);
printf("Enter the items\n");
for(i=0;i<n;i++)
{
scanf("%d",&item);
head=insert_front(head,item);
}
break;
case 2:c=0;
printf("Enter the item to be inserted\n");
scanf("%d",&item);
printf("Enter the node to the left of which new node is to be inserted\n");
scanf("%d",&pos);
p=head;
while(p!=NULL)
{
c++;
if(c==pos)
head=insert_left(head,item,p);
p=p->next;
}
break;
case 3:printf("enter the value of the node to be deleted\n");
scanf("%d",&val);
head=del_val(head,val);
break;
case 4:display(head);
break;
case 5:exit(0);
break;
default:printf("Please enter a valid input\n");
}
printf("Enter next choice\n");
scanf("%d",&ch);
}
return 0;
}
