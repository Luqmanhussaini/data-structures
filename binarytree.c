











#include<stdio.h>
#include<stdlib.h>
typedef struct binarytree{
        int data;
        struct binarytree *left,*right;
}node;
node *insert(node *p,int x){
        node *new=(node *)malloc(sizeof(node));
        new->data=x;
        new->left=new->right=NULL;
        if(p==NULL)
                p=new;
        else if(x<=p->data)
                p->left=insert(p->left,x);
        else
                p->right=insert(p->right,x);
        return p;
}
//L N  R
void inorder(node *p){
        if(p!=NULL){
                inorder(p->left);
                printf("%d\t",p->data);
                inorder(p->right);
        }
}
//L R N
void preorder(node *p){
        if(p!=NULL){
                preorder(p->left);
                preorder(p->right);
                printf("%d\t",p->data);
        }
}
//N L R
void postorder(node *p){
        if(p!=NULL){
                printf("%d\t",p->data);
                postorder(p->left);
                postorder(p->right);
        }
}
node *mini(node *p){
        while(p->left!=NULL){
                p=p->left;
        }
        return p;
}
node *maxi(node *p){
        while(p->right!=NULL){
                p=p->right;
        }
        return p;
}
int search(node *p,int x){
        if(p!=NULL){
                if(x<p->data)
                        return search(p->left,x);
                else if(x>p->data)
                        return search(p->right,x);
                else if(x==p->data) return 1;
                else return -1;
        }
        return -1;
        node *temp;
        if(p==NULL)
                return p;
        else if(x>p->data)
                p->right=delete(p->right,x);
        else{
                if(p->right!=NULL &&p->left!=NULL){
                        x=p->data=mini(p->right)->data;
                        p->right=delete(p->right,x);
                }
                else{
                        if(p->right==NULL){
                                temp=p;
                                p=p->left;
                        }
                        else {temp=p; p=p->right;}
                        free(temp);
                        return p;
                }
        }

}
void main(){
        int opt,x;
        node *head=NULL;
        while(1){
                printf("\nselect an option: ");
                scanf("%d",&opt);
                switch(opt){
-- INSERT --            case 1: printf("enter number to insert: ");                                   76,16-37      62%
                                scanf("%d",&x);
                                head=insert(head,x);
                                break;
                        case 2: printf("Elements in inorder:\n");
                                inorder(head);
                                break;
                        case 3:
                                exit(0);
                                break;
                        case 4:
                                printf("Elements in preorder:\n ");
                                preorder(head);
                                break;
                        case 5:
                                printf("Elements in postorder:\n");
                                postorder(head);
                                break;
                        case 6:
                                printf("minimum number in binary tree: %d\n",mini(head)->data);
                                break;
                        case 7:
                                printf("maximum number in binary tree: %d\n",maxi(head)->data);
                                break;
                        case 8:
                                printf("Enter element to search: ");
                                scanf("%d",&x);
                                if(search(head,x)==1)
                                        printf("%d is found\n",x);
                                else
                                        printf("%d is not found\n",x);
                                break;
                        case 9: printf("enter element to delete: ");
                                scanf("%d",&x);
                                head=delete(head,x);
                                break;


                }
        }

}
