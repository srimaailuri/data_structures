#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
/*add the data at the beginning by value*/
struct node *add_beg(struct node*head,int data){
    if(head==NULL){
        printf("linked list is empty");
    }
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=head;
    head=temp;
    return head;
}
/*add the data at the beginning by reference
void add_beg(struct node **head,int data){
    if(*head==NULL){
        printf("linked list is empty");
    }
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=*head;
    *head=temp;
}*/
/*printing the data*/
void print_data(struct node *head){
    if(head==NULL){
        printf("Linked list is empty");
    }
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;
    /*here we have to return the head as in function call we are passing head by value */
    head=add_beg(head,25);
    print_data(head);
    /*here we have to return the head as in function call we are passing head by address 
    add_beg(&head,25);*/
    
    return 0;
    
}