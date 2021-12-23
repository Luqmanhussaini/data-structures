#include<stdio.h>
#include<stdlib.h>
typedef struct DLL{
        int data;
        struct DLL *left,*right;
}node;
node *create(node *first)
{
        node *prev,*new;
        int x;
        while(1){
                printf("Enter data or -1 to exit: ");
                scanf("%d",&x);
                if(x!=-1)
                {
                        new=(node *)malloc(sizeof(node));
                        new->data=x;
                        new->left=new->right=NULL;
                        if(first==NULL){
                                first=new;
                                prev=new;
                        }
                        else{
                               prev->right=new;
                                new->left=prev;
                                prev=new;
                        }
                }
                else
                        return first;
        }
}
void display(node *first)
{
        node *temp=first;
        if(temp==NULL)
                printf("No elements \n");
        else
        {
                while(temp!=NULL){
                        printf("%d->",temp->data);
                        temp=temp->right;
                }
        }
        printf("NULL\n");
}
void count(node *first){
        node *temp=first;
        int c=0;
        while(temp!=NULL)
        {
                c++;
                temp=temp->right;
        }
        printf("no.of elements =%d\n",c);
}

void main(){
        node *head=NULL;
        int opt;
        while(1){
                printf("1.create\n2.display\n3.count\n11.exit\n");
                printf("Choose an option: ");
                scanf("%d",&opt);
                switch(opt){
                        case 1:
                                head=create(head);
                                break;
                        case 2:
                                display(head);
                                break;
                        case 3:
                                count(head);
                                break;
                        case 11:
                                exit(0);
                        default:
                                printf("Choose the right option\n");
                }
        }
}
