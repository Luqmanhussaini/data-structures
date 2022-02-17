


































































































#include<stdio.h>
#include<stdlib.h>
typedef struct Stackll{
        int x;
        struct Stackll *next;
}node;
node *top=NULL;
void push(int a){
        node *new=(node *)malloc(sizeof(node));
        new->x=a;
        new->next=NULL;
        if(top==NULL){
                top=new;
        }
        else{
                new->next=top;
                top=new;
        }
}
int pop(){
        node *temp;
        int a;
        if(top==NULL)
                return -1;
        else{
                a=top->x;
                temp=top;
                top=top->next;
                free(temp);
                return a;
        }

}
void display(){
        node *temp=top;
        while(temp!=NULL){
                printf("%d -> ",temp->x);
                temp=temp->next;
        }
        printf("NULL\n");
}
void main(){
        int opt,a;
        while(1){
                printf("1.push\n2.pop\n3.display\n4.exit");
                scanf("%d",&opt);
                switch(opt){
                        case 1:
                                printf("Enter data:");
                                scanf("%d",&a);
                                push(a);
                                break;
                        case 2:
                                a=pop();
                                printf("pop value: %d\n",a);
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
