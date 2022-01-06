#include<stdio.h>
#include<stdlib.h>
typedef struct hashing{
        int data;
        struct hashing *next;
}node;
int hash(int x){
        return x%10;
}
void inserting(node *t[], int x){
        int i=hash(x);
        node *new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(t[i]->next==NULL)
                t[i]->next=new;
        else{
                new->next=t[i]->next;
                t[i]->next=new;
        }
}
void display(node *t[]){
        node *temp;
        for(int i=0;i<10;i++){
                temp=t[i]->next;
                printf("%d contains-->  ",i);
                while(temp!=NULL){
                        printf("%d->",temp->data);
                        temp=temp->next;
                }
                printf("NULL\n");
        }
}
void searching(node *t[],int x){
        int i=hash(x);
        int f=0;
        node *temp=t[i]->next;
        while(temp!=NULL){
                if(temp->data==x){
                        f=1;
                        break;
                }
               else
                        temp=temp->next;
        }
        if(f==1)
                printf("%d is found\n",x);
        else
                printf("%d is not found\n",x);
}
void delete(node *t[],int x){
        int i=hash(x);
        int f=0;
        node *temp=t[i]->next,*temp1=t[i];
        while(temp!=NULL){
                if(temp->data==x){
                        f=1;
                        break;
                }
                else{
                        temp1=temp;
                        temp=temp->next;
	}
       }
       if(f==1){
               temp1->next=temp->next;
               free(temp);
       }
       else{
               printf("%d not found\n",x);
       }

oid main()

       int opt,x;
       node *arr[10];
       for(int i=0;i<10;i++){
               arr[i]=(node *)malloc(sizeof(node));
               arr[i]->next=NULL;
       }
       while(1){
               printf("1.insert\n2.display\n3.search\n4.delete\n5.exit\n");
	 printf("choose an option: ");
                scanf("%d",&opt);
                switch(opt){
                        case 1:
                                printf("Enter an element to insert: ");
                                scanf("%d",&x);
                                inserting(arr,x);
                                break;
                        case 2:
                                display(arr);
                                break;
                        case 3:
                                printf("Enter element to search: ");
                                scanf("%d",&x);
                                searching(arr,x);
                                break;
                        case 4:
                                printf("Enter element to delete: ");
                                scanf("%d",&x);
                                delete(arr,x);
                                break;
	      case 5:exit(0);
                                    break;
                        default:
                                printf("wrong input\n");
                }
        }
}
