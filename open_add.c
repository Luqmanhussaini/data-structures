#include<stdio.h>
#include<stdlib.h>
int hash(int x){
    return x%10;
}
void insert(int a[],int x){
    int i=hash(x),f=0,j;
    if(a[i]==-1){
        a[i]=x;
        f=1;
    }
    else{
        for(j=i+1;j<10;j++){
            if(a[j]==-1){
                a[j]=x;
                f=1;
                break;
            }
        }
        for(j=0;j<i &&f==0;j++){
            if(a[j]==-1){
                a[j]=x;
                f=1;
                break;
            }
        }
    }
    if(f==0)
    printf("array filled\n");
}
void display(int a[]){
    for(int i=0;i<10;i++)
    {
        if(a[i]!=-1)
            printf("%d - ",a[i]);
    }
    printf("\n");
}


void search(int a[],int x){
    int i=hash(x),f=0,j;
    if(a[i]==x)
        f=1;
    else{
        for(j=i+1;j<10;j++){
            if(a[j]==x){
                f=1;
                break;
            }
        }
        for(j=0;j<i &&f==0;j++){
            if(a[j]==x){
                f=1;
                break;
            }
        }
    }
    if(f==1)
    printf("%d found\n",x);
    else
    printf("%d not found\n",x);
}

void delete(int a[],int x){
    int i=hash(x),f=0,j;
    if(a[i]==x){
        a[i]=-1;
        f=1;
    }
    else{
        for(j=i+1;j<10;j++){
            if(a[j]==x){
                a[j]=-1;
                f=1;
                break;
            }
        }
        for(j=0;j<i &&f==0;j++){
            if(a[j]==x){
                a[j]=-1;
                f=1;
                break;
            }
        }
    }
    if(f==0)
    printf("%d not found\n",x);
}

void main(){
    int a[10],i,opt,x;
    for(i=0;i<10;i++)
    a[i]=-1;
    while(1){
        printf("1.insert\n2.display\n3.search\n4.delete\n5.exit\n");
        printf("select an option: ");
        scanf("%d",&opt);
        switch(opt){
            case 1:
                printf("enter number to insert:");
                scanf("%d",&x);
                insert(a,x);
                break;
            case 2:
                display(a);
                break;
            case 3:
                printf("enter number to search:");
                scanf("%d",&x);
                search(a,x);
                break;
            case 4:
                printf("enter number to delete:");
                scanf("%d",&x);
                delete(a,x);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Wrong input\n");
        }
    }
}
