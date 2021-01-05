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

Node insert(Node root,int item){
	Node temp,cur,prev;
	temp=getnode();
	temp->rlink=NULL;
	temp->llink=NULL;
	temp->info=item;
	if(root==NULL)
		return temp;
	prev=NULL;
	cur=root;
	while(cur!=NULL){
		prev=cur;
		cur=(item<cur->info)?cur->llink:cur->rlink;
	}
	if(item<prev->info)
		prev->llink=temp;
	else
		prev->rlink=temp;
	return root;
}

void display(Node root, int i){
	int j;
	if(root!=NULL){
		display(root->rlink,i+1);
		for(j=0;j<i;j++)
			printf(" ");
		printf("%d\n", root->info);
		display(root->llink,i+1);
	}
}

Node delete(Node root,int item)
{
	Node cur,parent,q,suc;
	if(root==NULL){
		printf("It is empty\n");
		return root;
	}
	parent=NULL;
	cur=root;
	while(cur!=NULL && item!=cur->info){
		parent=cur;
		cur=(item<cur->info)?cur->llink:cur->rlink;
	}
	if(cur==NULL){
		printf("item not found\n");
		return root;
	}
	if(cur->llink==NULL)
		q=cur->rlink;
	else if(cur->rlink==NULL)
		q=cur->llink;
	else{
		suc=cur->rlink;
		while(suc->llink!=NULL)
			suc=suc->llink;
		suc->llink=cur->rlink;
		q=cur->rlink;
	}
	if(parent==NULL)
		return q;
	if(cur==parent->llink)
		parent->llink=q;
	else
		parent->rlink=q;
	freenode(cur);
	return root;
}

void preorder(Node root){
	if(root!=NULL){
		printf("%d\n",root->info);
		preorder(root->llink);
		preorder(root->rlink);
	}
}

void postorder(Node root){
	if(root!=NULL){
		postorder(root->llink);
		postorder(root->rlink);
		printf("%d\n",root->info);
	}
}

void inorder(Node root){
	if(root!=NULL){
		inorder(root->llink);
		printf("%d\n",root->info);
		inorder(root->rlink);
	}
}

void main(){
	int item,choice;
	Node root=NULL;
	for(;;)
	{
		printf("1.Insert\n2.Display\n3.preorder\n4.postorder\n5.inorder\n6.delete\n7.exit\n");
		printf("Enter the choice\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:printf("Enter the item\n");
			scanf("%d", &item);
			root=insert(root,item);
			break;
			case 2:display(root,0);
			break;
			case 3:preorder(root);
			break;
			case 4:postorder(root);
			break;
			case 5:inorder(root);
			break;
			case 6:printf("Enter the item\n");
			scanf("%d", &item);
			root=delete(root,item);
			break;
			default:exit(0);
			break;
		}
	}
}

