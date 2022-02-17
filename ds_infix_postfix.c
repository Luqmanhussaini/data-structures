


#include<stdio.h>
#include<ctype.h>
#define MAX 20
char postfix[MAX],a[MAX];
int j=0,top=-1;
void push(char ch){
        a[++top]=ch;
}
char pop(){
        return a[top--];
}
int pri(char ch){
        if(ch=='^')
                return 3;
        if(ch=='*'||ch=='/'||ch=='%')
                return 2;
        if(ch=='+'||ch=='-')
                return 1;
        else return 0;
}
void precedence(char ch){
        while(pri(ch)<=pri(a[top])){
                postfix[j++]=pop();
        }
}
void main(){
        char infix[MAX],ch,x;
        printf("Enter infix expression: ");
        scanf("%s",infix);
        int i=0;
        while(infix[i]!='\0'){
                ch=infix[i];
                if(isalpha(ch)||isdigit(ch))
                        postfix[j++]=ch;
                else{
                        switch(ch){
                                case '(':push(ch);
                                         break;
                                case '^':
                                case '*':
                                case '%':
                                case '/':
                                case '+':
                                case '-':precedence(ch);
                                         push(ch);
                                         break;
                                case ')':x=pop();
                                         while(x!='('){
                                                 postfix[j++]=x;
                                                 x=pop();
                                         }
                                         break;
                        }
                }
                i++;
        }
        while(top!=-1){
                postfix[j++]=pop();
        }
        postfix[j]='\0';
        printf("\n%s\n",postfix);
}
