#include<Math.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct AVL{
    int data,ht;
    struct AVL *right, *left;
}node;
int height(node *p){
    if(p==NULL)
        return -1;
    return height(p->left)+1;
}
node *single_ll(node *k2){
    node *k1=k2->left;
    k2->left=k1->right;
    k1->right=k2;
    k2->ht=max(height(k2->left),height(k2->right))+1;
    k1->ht=max(height(k1->left),height(k1->right))+1;
    return k1;
}
node *single_rr(node *k1){
    node *k2=k1->left;
    k1->right=k2->left;
    k2->left=k1;
    k2->ht=max(height(k2->left),height(k2->right))+1;
    k1->ht=max(height(k1->left),height(k1->right))+1;
    return k2;
}
node *double_lr(node *k3){
    k3->left=single_rr(k3->left);
    return single_ll(k3);
}
node *double_rl(node *k1){
    k1->right=single_ll(k1->right);
    return single_rr(k1);
}

node *insert(node *p,int x){
    if(p==NULL){
        p=(node *)malloc(sizeof(node));
        p->data=x;
        p->ht=0;
        p->right=p->left=NULL;
    }
    else if(x<p->data){
        p->left=insert(p->left,x);
        if(abs(height(p->left)-height(p->right))==2){
            if(x<p->left->data)
            p=single_ll(p);
            else
            p=double_lr(p);
        }
    }
    else if(x>p->data){
        p->right=insert(p->right,x);
        if(abs(height(p->left)-height(p->right))==2){
            if(x<p->right->data)
            p=single_rr(p);
            else
            p=double_rl(p);
        }
    }
    p->ht=max(height(p->left),height(p->right))+1;
    return p;
}
