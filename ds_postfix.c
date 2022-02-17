






























































#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define MAX 20
int a[MAX],top=-1;
void push(int x){
        a[++top]=x;
}
int pop(){
        return a[top--];
}
int operation(int a,int b,char c){
        switch(c){
                //case '^': return pow(a,b);
                case '*': return a*b;
                case '+': return a+b;
                case '-': return a-b;
                case '/': return a/b;
                case '%': return a%b;
        }
}
void main(){
        int op1,op2,result,i=0;
        char postfix[MAX],c;
        printf("Enter expression: ");
        scanf("%s",postfix);
        while(postfix[i]!='\0'){
                c=postfix[i];
                if(isdigit(c))
                        push(c-'0');
                else{
                        op2=pop();
                        op1=pop();
                        result=operation(op1,op2,c);
                        push(result);
                }
                i++;
        }
        printf("%d\n",a[top]);
}
