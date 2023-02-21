#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int stack[50],top=-1;

void push(int ele){
    stack[++top]=ele;
}

void main(){
    char postfix[50],ch;
    int i=0,op1,op2;
    printf("Enter a suffix operation with single digit operands and operators:\n");
    scanf("%s",postfix);
    while((ch=postfix[i++])!='\0'){
        if(isalpha(ch)){
            printf("Invalid Expression");
            return;
        }
        else if(isdigit(ch)){
            push(ch-48);
        }
        else{
            op2=stack[top--];
            if(top<=-1){
                printf("Invalid Expression\n");
                return;
            }
            op1=stack[top--];
            switch(ch){
                case '+':push(op1+op2);break;
                case '-':push(op1-op2);break;
                case '*':push(op1*op2);break;
                case '/':push(op1/op2);break;
                case '%':push(op1%op2);break;
                case '^':push(pow(op1,op2));break;
                default:printf("Invalid Operator\n");
                return;
            }
        }
    }
    if(top!=0) printf("Invalid Expression\n");
    else printf("Result= %d\n",stack[top]);
}
