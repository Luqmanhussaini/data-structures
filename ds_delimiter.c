








































#include<stdio.h>
#include<ctype.h>
#define MAX 20
char a[MAX];
int top=-1;
void push(char c){
        a[++top]=c;
}
char pop(){
        return a[top--];
}
void main(){
        char exp[MAX],c,x;
        int f=1,i=0;
        printf("expression: ");
        scanf("%s",exp);
        while(exp[i]!='\0'){
                c=exp[i];
                if(c=='{'||c=='['||c=='(')
                        push(c);
                else if(c=='}'||c==']'||c==')'){
                        if(top==-1){
                                f=0;
                                break;
                        }
                        else
                        {
                                x=pop();
                                if(x=='('&&c==')'||x=='{'&&c=='}'|| x=='['&&c==']')
                                        f=1;
                                else
                                {
                                        f=0;
                                        break;
                                }
                        }
                }
                i++;
        }
        if(top!=-1)
                f=0;
        if(f==1)
                printf("\ncorrect\n");
        else
                printf("\nwrong\n");
}
