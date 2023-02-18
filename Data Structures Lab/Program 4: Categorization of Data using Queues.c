#include<stdio.h>
#include<stdlib.h>
#define capacity 20
void insert(),delete(),display();
int queue[capacity],rear=-1,front=-1;
void main(){
    int choice;
    while(1){
        printf("\n1.Enter 1 to insert element.");
        printf("\n2.Enter 2 to delete element.");
        printf("\n3.Enter 3 to display queue.");
        printf("\n4.Enter 4 to quit.");
        printf("\nEnter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();break;
            case 2:delete();break;
            case 3:display();break;
            case 4:exit(1);break;
            default:printf("Wrong Choice\n");break;
        }
    }
}
void insert(){
    int element;
    if(rear==capacity-1) printf("Queue is full!\n");
    else{
        if(front==-1) front=0;
        printf("Enter the element to be inserted:\n");
        scanf("%d",&element);
        rear=rear+1;
        queue[rear]=element;
    }
}
void delete(){
    if(front==-1||front>rear){
        printf("Queue is empty!\n");return;
    }
    else{
        printf("Element deleted from the queue: %d\n",queue[front]);
        front+=1;
    }
}
void display(){
    int i;
    if(front==-1||front>rear) printf("Queue is empty!\n");
    else{
        printf("Elements of the queue are:\n");
        for(i=front;i<=rear;i++) printf("%d\t",queue[i]);
        printf("\n");
        printf("------------------------------------------\n");
        printf("Categorization of the data:\n");
        printf("------------------------------------------\n");
        printf("\nGroup 1: Less than 10\n");
        for(i=front;i<=rear;i++){
            if(queue[i]<10) printf("%d\t",queue[i]);
        }
        printf("\nGroup 2: Between 10 and 19\n");
        for(i=front;i<=rear;i++){
            if(queue[i]>=10&&queue[i]<20) printf("%d\t",queue[i]);
        }
        printf("\nGroup 3: Between 20 and 29\n");
        for(i=front;i<=rear;i++){
            if(queue[i]>=20&&queue[i]<30) printf("%d\t",queue[i]);
        }
        printf("\nGroup 4: 30 and above\n");
        for(i=front;i<=rear;i++){
            if(queue[i]>=30) printf("%d\t",queue[i]);
        }
    }
}
