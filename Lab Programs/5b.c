//convert infix to postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isOperator(char ch){
    switch(ch){
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            return 1;
        default:
            return 0;
    }
}
int precedence(char operator){
    switch(operator){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
void infixToPostfix(char in[50]){
    char stack[50];
    char postifx[50];
    int top = -1, i, j;
    for(i=0, j=0; in[i]!='\0'; i++){
        if(isalnum(in[i])){
            postifx[j++] = in[i];
        }
        else if(in[i] == '('){
            stack[++top] = in[i];
        }
        else if(in[i] == ')'){
            while(top > -1 && stack[top] != '('){
                postifx[j++] = stack[top--];
            }
            top--; // pop '('
        }
        else if(isOperator(in[i])){
            while(top > -1 && (precedence(stack[top]) >= precedence(in[i]))){
                postifx[j++] = stack[top--];
            }
            stack[++top] = in[i];
        }
    }
    while(top > -1){
        if(stack[top] == '('){
            printf("Invalid Expression\n");
        }
        postifx[j++] = stack[top--];
    }
    postifx[j] = '\0';
    printf("Postfix Expression: %s\n", postifx);

}

int main(){
    char infix[50];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}