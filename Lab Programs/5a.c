//write a c program to implement menu driven program for operations on stack

#include <stdio.h>
#include <stdlib.h>
int MAX, stack[100], top = -1;
int push(int, int);
int pop(int);
void display(int);

int main(){
    int choice, num;
    printf("Enter the size of stack: ");
    scanf("%d", &MAX);
    while(1){
        printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter a number to push: ");
                scanf("%d", &num);
                top = push(top, num);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
int push(int top, int num){
    if(top == MAX - 1){
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = num;
    }
    return top;
}
int pop(int top){
    if(top == -1){
        printf("Stack Underflow!\n");
    } else {
        printf("Popped element: %d\n", stack[top--]);
    }
    return top;
}
void display(int top){
    if(top == -1){
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements:\n");
        for(int i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}