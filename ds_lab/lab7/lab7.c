#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
typedef struct node *Node;
Node getnode()
{
	Node x;
	x=(Node)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("mem full\n");
		exit(0);
	}
	return x;
}

Node insert_rear(Node first,int item)
{
	Node temp,cur;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return first;
}

void display(Node first)
{
	Node temp;
	if(first==NULL)
		printf("list empty");

	for(temp=first;temp!=NULL;temp=temp->link)
	{
		printf("%d\n",temp->info);
	}
}

Node order_list(int item, Node first){
	Node temp, prev, cur;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)return temp;
	if(item<first->info){
		temp->link=first;
		return temp;
	}
	prev=NULL;
	cur=first;
	while(cur!=NULL && item>cur->info){
		prev=cur;
		cur=cur->link;
	}
	prev->link=temp;
	temp->link=cur;
	return first;
}

Node concat(Node first,Node second)
{
	Node cur;
	if(first==NULL)
		return second;
	if(second==NULL)
		return first;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=second;
	return first;
}

Node reverse(Node first)
{
	Node cur,temp;
	cur=NULL;
	while(first!=NULL)
	{
		temp=first;
		first=first->link;
		temp->link=cur;
		cur=temp;
	}
	return cur;
}

void main()
{
	int item,choice,pos,i,n;
	Node first=NULL,a,b;
	for(;;)
	{
		printf("1.insert_front\n2.ordered_list\n3.concat\n4.reverse\n5.dislay\n6.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the item\n");
			scanf("%d",&item);
			first=insert_rear(first,item);
			break;
			case 2:printf("Enter item to be inserted in ordered list\n");
			scanf("%d",&item);
			first=order_list(item,first);
			break;
			case 3:printf("enter the no of nodes in 1\n");
			scanf("%d",&n);
			a=NULL;
			for(i=0;i<n;i++)
			{
				printf("enter the item\n");
				scanf("%d",&item);
				a=insert_rear(a,item);
			}
			printf("enter the no of nodes in 2\n");
			scanf("%d",&n);
			b=NULL;
			for(i=0;i<n;i++)
			{
				printf("enter the item\n");
				scanf("%d",&item);
				b=insert_rear(b,item);
			}
			a=concat(a,b);
			display(a);
			break;
			case 4:first=reverse(first);
			display(first);
			break;
			case 5:display(first);
			break;
			default:exit(0);
		}
	}
}
