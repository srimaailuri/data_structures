#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
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
/*inserting a data at end*/
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
struct node *reverse(struct node *head){
    struct node *prev=NULL;
    struct node *next=NULL;
    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}
int main(){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    insert_at_end(head,9);
    insert_at_end(head,98);
    print_data(head);
    head=reverse(head);
    return 0;
}