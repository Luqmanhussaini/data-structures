#include<stdio.h>
#include<stdlib.h>
struct dsSLL
{
    int data;
    struct dsSLL *next;
};
typedef struct dsSLL node;
node *create(node *first){
    node *new, *prev;
    int x;
    while (1)
    {
        printf("Enter the data or -1 to stop:  ");
        scanf("%d",&x);
        if(x!=-1){
            new=(node *)malloc(sizeof (node));
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
        else
        return first;
    }
}
void display(node *first){
    if(first==NULL)
    printf("no list");
    else{
        node *temp=first;
        while (temp!=NULL)
        {
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
    }
}
int count(node *first){
    int c=0;
    node *temp=first;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}
void search(node *first, int x){
    node *temp=first;
    int flag=0;
    while (temp!=NULL)
    {
        if(temp->data==x){
            flag=1;
            break;
        }
        else
        temp=temp->next;
    }
    if(flag==1)
    printf("\n%d found\n",x);
    else
    printf("\n%d not found\n",x);
}
node *insert_first(node *first, int x){
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    first=new;
    else{
        new->next=first;
        first=new;
    }
    return first;
}
node *insert_last(node *first, int x){
    node *temp=first;
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    if(first==NULL)
    first=new;
    else{
        while (temp->next!=NULL)
            temp=temp->next;
        temp->next=new;
    }
    return first;
}
node *insert_pos(node *first,int pos,int x){
    node *temp=first;
    node *new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=NULL;
    for(int i=1;i<pos;i++)
        temp=temp->next;
    new->next=temp->next;
    temp->next=new;    
    return first;
}
node *deletion(node *first, int x){
    node *temp,*temp1;
    int flag=0;
    if(first->data==x){
        flag=1;
        first=first->next;
        free(temp);
    }
    else{
        temp1=first;
        temp=first->next;
        while (temp!=NULL){
            if(temp->data==x){
                flag=1;
                break;
            }
            else{
                temp1=temp;
                temp=temp->next;
            }
        }
    }
    if(flag==1){
        temp1->next=temp->next;
        free(temp);
    }
    else
        printf("element not found");
    return first;
}

void sorting(node *first){
    node *temp1,*temp2;
    int x;
    for(temp1=first;temp1->next!=NULL;temp1=temp1->next)
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
            if(temp1->data>temp2->data){
                x=temp1->data;
                temp1->data=temp2->data;
                temp2->data=x;
            }
}
node *reverse(node *first){
    node *present=first, *prev=NULL,*same=NULL;
    while (present!=NULL)
    {
        same=present->next;
        present->next=prev;
        prev=present;
        present=same;
    }
    first=prev;
    return first;
}
void main(){
    int opt,c,x,pos;
    node *head=NULL;
    while (1)
    {
        printf("\t\t\t\tChoose an option\n");
        printf("1.create\t2.display\t3.count\t4.search\t5.insert at first\t6.insert at last\t7.insert at position\t8. delete an element\t9.sort the eleemnts\t10. reverse the elements\t11.exit\n");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            c=count(head);
            printf("no.of elements = %d\n",c);
            break;
        case 4:
            printf("enter an element to search: ");
            scanf("%d",&x);
            search(head,x);
            break;
        case 5:
            printf("enter an element to insert at first: ");
            scanf("%d",&x);
            head=insert_first(head,x);
            break;
        case 6:
            printf("enter an element to insert at last: ");
            scanf("%d",&x);
            head=insert_last(head,x);
            break;        
        case 7:
            printf("enter the position and element to insert: ");
            scanf("%d %d",&pos,&x);
            head=insert_pos(head,pos,x);
            break;        
        case 8:
            printf("enter an element to delete: ");
            scanf("%d",&x);
            head=deletion(head,x);
            break;
        case 9:
            sorting(head);
            break;    
        case 10:
            head = reverse(head);
            break;    
        case 11:
            exit(0);    
        default:
        printf("wrong input");
            break;
        }
    }   
}
