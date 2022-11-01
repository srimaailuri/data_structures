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
struct node *del_list(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
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
    head=del_list(head);
    print_data(head);
    return 0;
}