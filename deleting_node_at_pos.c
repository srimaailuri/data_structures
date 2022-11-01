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
/*deleting node at certain position*/
void del_position(struct node **head,int position){
    struct node *current = *head;
    struct node *previous = *head;
    if(*head==NULL){
        printf("List is empty");
    }
    else if(position==1){
        *head=current->link;
        free(current);
        current=NULL;
    }
    else{
        while(position!=1){
            previous=current;
            current=current->link;
            position--;}
            previous->link=current->link;
            free(current);
            current=NULL;
        }
}

int main(){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    insert_at_end(head,9);
    insert_at_end(head,98);
    print_data(head);
    printf("after deleting element at a particular position:");
    del_position(&head,2);
    print_data(head);
    return 0;
}