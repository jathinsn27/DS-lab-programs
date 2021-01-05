#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 3
void insertrear();
int deletefront();
void displayq();
int item, front = 0, rear  = -1, q[100];
void main(){
    int choice=1;
    while(choice != 0){
        printf("Enter your choice\n");
        printf("1.insert rear\n2.delete front\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            insertrear();
            break;
            case 2:item = deletefront();
            if(item == -1){
                printf("Queue Empty\n");
            }
            else{
                printf("item deleted is %d\n", item);
            }
            break;
            case 3:displayq();
            break;
            case 4:choice = 0;
            break;
            default:printf("Invalid input\n");
        }
    }
}
void insertrear(){
    if(rear == QUE_SIZE-1){
        printf("Queue oerflow\n");
    }
    else{
        rear = rear + 1;
        q[rear] = item;
    }
}
int deletefront(){
    if(front>rear){
        front =0;
        rear = -1;
        return -1;
    }
    return q[front++];
}
void displayq(){
    int i;
    if(front>rear){
        printf("Empty queue\n");
    }
    else{
        printf("Contents of queue\n");
        for(i=front; i<= rear; i++){
            printf("%d\n",q[i]);
        }
    }
}