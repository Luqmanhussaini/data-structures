#include<stdio.h>
#include<stdlib.h>
typedef struct queuell{
        int data;
        struct queuell *next;
}node;
node *front=NULL,*rare=NULL;
void enqueue(int x){
        node *new=(node *)malloc(sizeof(node)),*temp;
        new->data=x;
        new->next=NULL;
        if(front==NULL&&rare==NULL){
                front=rare=new;
        }
        else{
                rare->next=new;
                rare=new;
        }
}
int dequeue(){
        int x;
        node *temp;
        if(front==NULL)
                return -1;
        else{
                x=front->data;
                if(front==rare){
                        front=rare=NULL;
                }
                else{
                        temp=front;
                        front=front->next;
                        free(temp);
                }
                return x;

        }
}
void display(){
        node *temp;
        if(front==NULL)
                printf("empty\n");
        else{
                temp=front;
                while(temp!=NULL){
                        printf("%d\t",temp->data);
                        temp=temp->next;
                }
        }
}
void main(){
        int opt,x;
        while(1){
                printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
                printf("choose an option:  ");
                scanf("%d",&opt);
                switch(opt){
                        case 1: printf("enter element to insert: ");
                                scanf("%d",&x);
                                enqueue(x);
                                break;
                        case 2:
                                x=dequeue();
                                printf("element : %d\n",x);
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("wrong input\n");
                }
        }
}
