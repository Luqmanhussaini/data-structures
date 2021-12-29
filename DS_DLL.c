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
node *insert_first(node *first, int x)
{
        node *temp=first,*new=(node *)malloc(sizeof(node));
        new->data=x;
        new->right=new->left=NULL;
        if(first==NULL)
                first=new;
        else{
                new->right=first;
                first->left=new;
                first=new;
        }
        return first;
}
node *insert_last(node *first, int x)
{
        node *temp=first,*new=(node *)malloc(sizeof(node));
        new->data=x;
        new->right=new->left=NULL;
        if(first==NULL)                first=new;
        else{
                while(temp->right!=NULL)
                        temp=temp->right;
                new->left=temp;
                temp->right=new;
                temp=new;
        }
        return first;
}
node *insert_mid(node *first, int ele,int pos){
        node *temp=first, *new=(node *)malloc(sizeof(node));
        new->data=ele;
        new->right=new->left=NULL;
        for(int i=0;i<pos-1;i++)
                temp=temp->right;
        new->right=temp->right;
        new->left=temp;
        temp->right=new;
        temp->right->left=new;
        return first;
}
node *delete(node *first, int x)
{
        node *temp;
        int f=0;
        if(first==NULL)
                printf("empty list");
        else if(first->data==x){
                temp=first;
                first=first->right;
                if(first!=NULL)
                        first->left=NULL;
                free(temp);
        }
        else{
                temp=first;
                while(temp!=NULL){
                        if(temp->data==x){
                                f=1;
                                break;
                        }
                        else
                                temp=temp->right;
                }
        }
        if(f==1){
                if(temp->right==NULL){
                        temp->left->right=NULL;
                        free(temp);
                }
                else{
                        temp->right->left=temp->left;
                        temp->left->right=temp->right;
                        free(temp);
                }
        }
        else
                printf("Element not found\n");
        return first;
}
void search(node *first,int x){
        node *temp=first;
        int f=0;
        if(first==NULL)
                printf("no list");
        else{
                while(temp!=NULL){
                        if(temp->data==x){
                                f=1;
                                break;
                        }
                        else
                                temp=temp->right;
                }
        }
                if(f==1)
                        printf("Element found\n");
                else
                        printf("element not found\n");
}
void sorting(node *first){
        node *temp1,*temp2;
        int x;
        for(temp1=first;temp1->right!=NULL;temp1=temp1->right)
                for(temp2=temp1->right;temp2!=NULL;temp2=temp2->right)
                        if(temp1->data>temp2->data){
                                x=temp1->data;
                                temp1->data=temp2->data;
                                temp2->data=x;
                        }
}
node *reverse(node *first){
        node *present=first,*prev=NULL,*same=NULL;
        while(present!=NULL){
                same=present->right;
                present->right=prev;
                prev=present;
                present=same;
        }
        return present;
}
void main(){
        node *head=NULL;
        int opt,x,pos;
        while(1){
                printf("1.create\n2.display\n3.count\n4.insert_first\n5.insert_last\n6.insert_mid\n7.delete\n8.search\n9.sort\n10.reverse\n11.exit\n");
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
                        case 4:
                                printf("Enter an element to insert: ");
                                scanf("%d",&x);
                                head=insert_first(head,x);
                                break;
                        case 5:
                                printf("Enter an element to insert: ");
                                scanf("%d",&x);
                                head=insert_last(head,x);
                                break;
                        case 6:
                                printf("enter element and position: ");
                                scanf("%d %d",&x,&pos);
                                head=insert_mid(head,x,pos);
                                break;
                        case 7:
                                printf("Enter element to delete: ");
                                scanf("%d",&x);
                                head=delete(head,x);
                                break;
                        case 8:
                                printf("Enter element to search: ");
                                scanf("%d",&x);
                                search(head,x);
                                break;
                        case 9:
                                sorting(head);
                                break;
                        case 10:
                                head=reverse(head);
                                break;
                        case 11:
                                exit(0);
                        default:
                                printf("Choose the right option\n");
                }
        }
}
