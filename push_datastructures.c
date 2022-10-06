/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack_array[MAX];
int top=-1;
void push(int data){
    if(top==MAX-1){
        printf("stack overflown");
        return;
    }
    top=top+1;
    stack_array[top]=data;
}
int pop(){
    int value;
    if(top==-1){
        printf("stack underflow");
        exit(1);
    }
    value=stack_array[top];
    top=top-1;
    return value;
}
int top_element(){
    int value;
    if(top==-1){
        printf("stack is empty");
        exit(1);
    }
    value=stack_array[top];
    return value;
}
void print(){
    int i;
    if(top==-1){
        printf("stack is empty");
        return;
    }
    for(i=0;i<=top;i++){
        printf("%d",stack_array[i]);
    printf("\n");
    }
}
int main()
{
    int choice,data;
    while(1){
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top element of the stack\n");
        printf("4.print the all elements of the stack\n");
        printf("5.Quit\n");
        printf("please enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            
            case 1:
            printf("Enter the element to be pushed:");
            scanf("%d",&data);
            push(data);
            break;
            
            case 2:
            data=pop();
            printf("Element poped is : %d\n",data);
            break;
            
            case 3:
            data=top_element();
            printf("%d is the top element of the stack\n",data);
            break;
            
            case 4:
            print();
            break;
            
            case 5:
            exit(1);
            
            default:
            printf("wrong choice\n");
        }
    }
    
    return 0;
}

