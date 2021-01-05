#include<stdio.h>
#include<stdlib.h>
struct Node{
	int info;
	struct Node*link;
};
typedef struct Node *Node;
Node getNode()
{
	Node x;
	x=(Node)malloc(sizeof(struct Node));
	if(x==NULL){
		printf("Memory Full\n");
		exit(0);
	}
	return x;
}

void freeNode(Node x){
	free(x);
}

Node insert_front(Node first,int item)
{
	Node temp;
	temp=getNode();
	temp->info=item;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	temp->link=first;
	first=temp;
	return first;
}

Node delete_front(Node first)
{
	Node temp;
	if(first==NULL)
	{
		printf("list is empty cannot delete\n");
		return first;
	}
	temp=first;
	temp=temp->link;
	printf("item deleted at front-end is=%d\n",first->info);
	free(first);
	return temp;
}

Node delete_rear(Node first)
{
	Node cur,prev;
	if(first==NULL)
	{
		printf("list is empty cannot delete\n");
		return first;
	}
	if(first->link==NULL)
	{
		printf("item deleted is %d\n",first->info);
		free(first);
		return NULL;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	printf("iten deleted at rear-end is %d",cur->info);
	free(cur);
	prev->link=NULL;
	return first;
}

Node delete_pos(int pos,Node first)
{
	Node cur;
	Node prev;
	int count,flag=0;
	if(first==NULL || pos<0)
	{
		printf("invalid position\n");
		return NULL;
	}
	if(pos==1)
	{
		cur=first;
		first=first->link;
		freeNode(cur);
		return first;
	}
	prev=NULL;
	cur=first;
	count=1;
	while(cur!=NULL)
	{
		if(count==pos){flag=1;break;}
		count++;
		prev=cur;
		cur=cur->link;
	}
	if(flag==0)
	{
		printf("invalid position\n");
		return first;
	}
	printf("item deleted at given position is %d\n",cur->info);
	prev->link=cur->link;
	freeNode(cur);
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
		printf("\n1:Insert_front\n2:Delete_front\n3:Delete_rear\n4:Delete_pos\n5:Display\n6:Exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("enter the item at front-end\n");
			scanf("%d",&item);
			first=insert_front(first,item);
			break;
			case 2:first=delete_front(first);
			break;
			case 3:first=delete_rear(first);
			break;
			case 4:printf("Enter the position of the item to be deleted\n");
			scanf("%d", &pos);
			first=delete_pos(pos,first);
			break;
			case 5:display(first);
			break;
			default:exit(0);
			break;
		}
	}
}