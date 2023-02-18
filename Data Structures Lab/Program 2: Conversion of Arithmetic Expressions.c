#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20
char stack[size];
int top=-1;
void push(char elem){
    stack[++top]=elem;
}
char pop(){
    return(stack[top--]);
}
int precedence(char elem){
    switch(elem){
        case '#':return 0;break;
        case '(':
        case ')':return 1;break;
        case '+':
        case '-':return 2;break;
        case '*':
        case '/':
        case '%':return 3;break;
        case '^':return 4;break;
        default:printf("Not a Valid Expression\n");exit(0);
    }
}
void main(){
    char infix[20],postfix[20],ch,elem;
    int i=0,k=0,pr;
    printf("Enter the Infix Expression:\n");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0'){
        if(ch=='(') push(ch);
        else if (isalnum(ch)) postfix[k++]=ch;
        else if(ch==')'){
            while(stack[top]!='('){
                postfix[k++]=pop();
                if(stack[top]=='#'){
                    printf("Not a valid Expression\n");exit(0);
                }
            }
            elem=pop();
        }
        else{
            pr=precedence(ch);
            if(ch=='^') pr++;
            while(precedence(stack[top])>=pr){
                postfix[k++]=pop();push(ch);
            }
        }
        while(stack[top]!='#'){
            postfix[k++]=pop();
        }
        postfix[k]='\0';
        printf("Given Infix Expression: %s\n",infix);
        printf("The Postfix Expression: %s\n",postfix);
    }
}
