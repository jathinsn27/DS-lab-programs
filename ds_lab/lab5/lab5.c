#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node*link;
};
typedef struct node *Node;
Node getnode()
{
	Node x;
	x=(Node)malloc(sizeof(struct node));
	if(x==NULL){
		printf("Memory Full\n");
		exit(0);
	}
	return x;
}

void freenode(Node x){
	free(x);
}

Node insert_front(Node first,int item)
{
	Node temp;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	temp->link=first;
	first=temp;
	return first;
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


Node insert_pos(int item,int pos,Node first)
{
	Node temp,cur,prev;
	int count;
	temp=getnode();
	temp->info=item;
	temp->link=NULL;
	if(first==NULL&&pos==1)
	{
		return temp;
	}
	if(first==NULL)
	{
		printf("invalid position\n");
		return first;
	}
	if(pos==1)
	{
		temp->link=first;
		first=temp;
		return temp;
	}
	count=1;
	prev=NULL;
	cur=first;
	while(cur!=NULL&&count!=pos)
	{
		prev=cur;
		cur=cur->link;
		count++;
	}
	if(count==pos)
	{
		prev->link=temp;
		temp->link=cur;
		return first;
	}
	printf("invalid position\n");
	return first;
}


void display(Node first)
{
	Node temp;
	if(first==NULL)
		printf("list empty cannot display items\n");
	for(temp=first; temp!=NULL; temp=temp->link){
		printf("%d\n",temp->info);
	}
}

int main()
{
	int item,choice,pos;
	Node first=NULL;

	for(;;)
	{
		printf("\n 1:Insert_front\n 2:Insert_rear\n 3:Insert_pos\n 4:display_list\n 5:Exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter the item at front-end\n");
			scanf("%d",&item);
			first=insert_front(first,item);
			break;
			case 2:printf("enter the item at rear-end\n");
			scanf("%d",&item);
			first=insert_rear(first,item);
			break;
			case 3:printf("Enter item to be inserted\n");
			scanf("%d", &item);
			printf("Enter position\n");
			scanf("%d", &pos);
			first=insert_pos(item,pos,first);
			break;
			case 4:display(first);
			break;
			default:exit(0);
			break;
		}
	}
}
