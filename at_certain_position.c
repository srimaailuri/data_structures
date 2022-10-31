#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void insert_at_end(struct node *head,int data){
    struct node *temp;
    temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    temp->link=ptr;
}
void add_at_pos(struct node *head,int data,int pos){
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;}
    temp->link=ptr->link;
    ptr->link=temp;
}
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
    head->data=45;
    head->link=NULL;
    insert_at_end(head,98);
    insert_at_end(head,9);
    int data=67;
    int position=3;
    add_at_pos(head,data,position);
    print_data(head);
    return 0;
}