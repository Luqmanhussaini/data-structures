































































































































































































































































































































































































































































































#include<stdlib.h>
#include<stdio.h>
#define max 20
int a[max],rare=-1,front=-1;
void enqueue(int x){
        if(rare==max-1)
                printf("It is over flow\n");
        else{
                if(front==-1)
                        front =0;
                        rare=0;
                }
                else{
                        rare++;
                }
                a[rare]=x;
        }
}
int dequeue(){
        int x;
        if(front==-1)
                return -1;
        else{
                x=a[front];
                if(front==rare)
                        front=rare=-1;
                else
                        front++;
                return x;
        }
}
void display(){
        int i;
        if(front==-1)
                printf("no elements\n");
        else{
                for(i=front;i<=rare;i++)
                        printf("%d\t",a[i]);
        }
        printf("\n");
}
void main(){
        int opt,x;
        while(1){
                printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
                printf("choose an option:  ");
                scanf("%d",&opt);
                switch(opt){
                        case 1:
                                printf("enter an element to insert: ");
                                scanf("%d",&x);
                                enqueue(x);
                                break;
                        case 2:
                                x=dequeue();
                                if(x==-1)
                                        printf("No elements in the list\n");
                                else
                                printf("element is: %d\n",x);
                                break;
                        case 3:
                                display();
                                break;
                        case 4:
                                exit(0);
                        default:
                                printf("....wrong input....\n");

                }

        }
}
