#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *Node;
Node getnode(){
	Node x;
	x=(Node)malloc(sizeof(struct node));
	if(x==NULL){
		printf("Memory full\n");
		exit(0);
	}
	return x;
}
void freenode(Node x){
	free(x);
}

Node dinsert_front(int item,Node head){
	Node temp,cur;
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	cur=head->rlink;
	head->rlink=temp;
	temp->llink=head;
	temp->rlink=cur;
	cur->llink=temp;
	return head;
}

Node dinsert_rear(int item,Node head){
	Node temp,cur;
	temp=getnode();
	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	cur=head->llink;
	head->llink=temp;
	temp->rlink=head;
	temp->llink=cur;
	cur->rlink=temp;
	return head;
}

Node ddelete_front(Node head){
	Node cur,next;
	if(head->rlink==head){
		printf("List is empty\n");
		return head;
	}
	cur=head->rlink;
	next=cur->rlink;
	head->rlink=next;
	next->llink=head;
	printf("Item deleted at front end is %d\n", cur->info);
	free(cur);
	return head;
}

Node ddelete_rear(Node head){
	Node cur,prev;
	if(head->rlink=NULL){
		printf("List is empty\n");
		return head;
	}
	cur=head->llink;
	prev=cur->llink;
	head->llink=prev;
	prev->rlink=head;
	printf("Item deleted at rear end is %d\n", cur->info);
	free(cur);
	return head;
}

void ddisplay(Node head){
	Node temp;
	if(head->rlink==head){
		printf("List is empty\n");
	}
	printf("Contents of the list are:\n");
	temp=head->rlink;
	while(temp!=head){
		printf("%d\n", temp->info);
		temp=temp->rlink;
	}
}

Node dinsert_leftpos(int item,Node head)
{
Node temp,cur,prev;
if(head->rlink==head)
{
printf("list empty\n");
return head;
}
cur=head->rlink;
while(cur!=head)
{
if(item==cur->info)break;
cur=cur->rlink;
}
if(cur==head)
{
 printf("key not found\n");
 return head;
 }
 prev=cur->llink;
 printf("enter towards left of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 prev->rlink=temp;
 temp->llink=prev;
 cur->llink=temp;
 temp->rlink=cur;
 return head;
}

Node ddelete_allkeyitem(int item, Node head){
	Node prev,cur,next;
	int count=0;
	if(head->rlink==head){
		printf("List is empty\n");
		return head;
	}
	cur=head->rlink;
	while(cur!=head){
		if(cur->info!=item){
			cur=cur->rlink;
		}
		else{
			count++;
				prev=cur->llink;
				next=cur->rlink;
				prev->rlink=next;
				next->llink=prev;
				free(cur);
				cur=next;
		}
	}
	if(count==0){
		printf("No such element is present in the list\n");
	}
	else{
		printf("All the duplicate elements are removed\n");
	}
	return head;
}

int main(){
	Node head;
	int item,choice,key;
	head=getnode();
	head->llink=head;
	head->rlink=head;
	for(;;){
		printf("1.dinsert_front\n2.dinsert_rear\n3.ddelete_front\n4.ddelete_rear\n5.ddisplay\n6.dinsert_leftpos\n7.ddelete_allkeyitem\n8.exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:printf("Enter the item at front end:\n");
			scanf("%d", &item);
			head=dinsert_front(item,head);
			break;
			case 2:printf("Enter the item at rear end:\n");
			scanf("%d", &item);
			head=dinsert_rear(item,head);
			break;
			case 3:ddelete_front(head);
			break;
			case 4:ddelete_rear(head);
			break;
			case 5:ddisplay(head);
			break;
			case 6:printf("Enter key element :\n");
			scanf("%d", &key);
			head=dinsert_leftpos(key,head);
			break;
			case 7:printf("Enter the key element to be deleted:\n");
			scanf("%d",&key);
			head=ddelete_allkeyitem(key,head);
			break;
			default:exit(0);
		}
	}
	return 0;
}

