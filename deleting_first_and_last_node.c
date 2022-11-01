#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};
void insert_at_end(struct node*head,int data){
    if(head==NULL){
        printf("Linked list is empty");
    }
    struct node *temp;
    temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=NULL;
    temp->link=ptr;
}
struct node *del_first(struct node *head){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else{
        struct node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
        return head;
    }
}
struct node *del_last(struct node *head){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        struct node *temp2=head;
        while(temp->link!=NULL){
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
        return head;
    }
}
void del_last_using_single_pointer(struct node *head){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else if(head->link==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct node *temp=head;
        if(temp->link->link!=NULL){
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
}
void print_data(struct node *head){
    struct node *ptr;
    ptr=head;
    if(head==NULL){
        printf("Linked list is empty");
    }
    else{
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
}

int main(){
    struct node *head=malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    insert_at_end(head,5);
    insert_at_end(head,50);
    insert_at_end(head,59);
    insert_at_end(head,9);
    insert_at_end(head,58);
    insert_at_end(head,88);
    print_data(head);
    head=del_first(head);
    printf("after calling del_first function:");
    print_data(head);
    head=del_last(head);
    printf("after calling del_last function:");
    print_data(head);

}