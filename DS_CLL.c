#include<stdio.h>
#include<stdlib.h>
struct cll{
        int data;
        struct cll *next;
};
typedef struct cll node;
node *create(node *first)
{
        int x;
        node *new,*prev;
        while(1)
        {
                printf("Enter the data or -1 to exit: ");
                scanf("%d",&x);
                if(x!=-1){
                        new=(node *)malloc(sizeof(node));
                        new->data=x;
                        new->next=NULL;
                        if(first==NULL){
                                first=new;
                                prev=new;
                        }
                        else{
                                prev->next=new;
                                prev=new;
                        }
                }
                else{
                        prev->next=first;
                        return first;
                }

        }
}
void display(node *first)
{
        node *temp=first;
        if(first==NULL)
        {
                printf("\nNo list\n");
        }
        else{
                do{
                        printf("%d ->",temp->data);
                        temp=temp->next;
                }while(temp->next!=first->next);
                printf("%d",temp->data);
        }
}
int count(node *first)
{
        int c=0;
        node *temp=first;
        while(temp->next!=first){
                c++;
                temp=temp->next;
        }
        c++;
        return c;
}
void search(node *first, int x)
{
        int flag=0;
        node *temp=first;
        while(temp->next!=first){
                if(temp->data==x){
                        flag=1;
                        break;
                }
                temp=temp->next;
        }
        if(flag==1)
                printf("\n%d is found\n",x);
        else
                printf("\n%d is not found\n",x);

}
node *insert_first(node *first, int x)
{
        node *temp=first, *new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL){
                first=new;
                new->next=first;
        }
        else{
                do{
                        temp=temp->next;
                }while(temp->next!=first);
                new->next=first;
                temp->next=new;
                first=new;
        }
        return first;
}
node *insert_last(node *first, int x)
{
        node *temp=first,*new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
        {
                first=new;
                new->next=first;
        }
        else{
                do{
                        temp=temp->next;
                }while(temp->next!=first);
                new->next=first;
                temp->next=new;
        }
        return first;
}
node *insert_pos(node *first, int x, int pos)
{
        node *temp=first, *new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        for(int i=1;i<pos;i++)
                temp=temp->next;
        new->next=temp->next;
        temp->next=new;
        return first;
}
node *delete(node *first,int x)
{
        node *temp,*temp1;
        int flag=0;
        if(first==NULL)
                printf("Not found");
        else if(first->data==x){
                temp1=first;
                temp=first;
                while(temp->next!=first)
                        temp=temp->next;
                first=first->next;
                temp->next=first;
                free(temp);
        }
        else{
                {
                        if(temp->data==x){
                                flag=1;
                                break;
                        }
                        else{
                                temp1=temp;
                                temp=temp->next;
                                while(temp!=first)
                                {
                                        if(temp->data==x)
                                        {
                                                flag=1;
                                                break;
                                        }
                                        else{
                                                temp1=temp;
                                                temp=temp->next;
                                        }
                                }
                        }
                }
                if(flag==1){
                        temp1->next=temp->next;
                        free(temp);
                }
                else{
                        printf("not found");
                }
        }
        return first;
}
node *sort(node *first)
{
        node *temp1, *temp2;
        int x;
        for(temp1=first; temp1->next!=first; temp1=temp1->next)
                for(temp2=temp1->next;temp2!=first;temp2=temp2->next)

                        if(temp1->data>temp2->data){
                                x=temp1->data;
        return first;
}
                return first;
        do{
                same=present->next;
                present->next=prev;
                prev=present;
                present=same;
        }while(present!=first);
        present->next=prev;
        present=prev;
        return present;

}
void main()
{
        node *head=NULL;
        int opt,c,x,pos;
        while(1)
        {
                scanf("%d",&opt);
                switch(opt)
                {
                        case 1:
                                head=create(head);
                                break;
                        case 2:
                                display(head);
                                break;
                        case 3:
                                c=count(head);
                                printf("No.of elements in Circular Linked List: %d\n",c);
                                break;
                        case 4:
                                printf("\nEnter an element to search: ");
                                scanf("%d",&x);
                                search(head,x);
                                break;
                        case 5:
                                printf("Enter an element to insert at first: ");
                                scanf("%d",&x);
                                head=insert_first(head,x);
                                break;
                        case 6:
                                printf("Enter an element to insert at last: ");
                                scanf("%d",&x);
                                head=insert_last(head,x);
                                break;
                        case 7:
                                printf("Enter an element and position to insert: ");
                                scanf("%d %d",&x,&pos);
                                head=insert_pos(head,x,pos);
                                break;
                        case 8:
                                printf("Enter an element to delete: ");
                                scanf("%d",&x);
                                head=delete(head,x);
                                break;
                        case 9:
                                head=sort(head);
                                break;
                        case 10:
                                head=reverse(head);
                                break;
                        case 11:
                                exit(0);
                        default:
                                printf("Please Enter Right Input");
                }
        }
}
