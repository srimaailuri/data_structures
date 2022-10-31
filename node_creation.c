#include<stdio.h>
#include<stdlib.h>
/*creating node*/
struct node{
    int data;
    struct node *link;
};
/* counting the number of nodes*/
void count_of_nodes(struct node *head){
    int count=0;
    if(head==NULL){
        printf("Linked list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->link;
    }
    printf("Total number of nodes:%d\n",count);
}
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

int main(){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    /*this is not a good method
    struct node *current=malloc(sizeof(struct node));
    current->data=86;
    current->link=NULL;
    head->link=current;*/
    insert_at_end(head,9);
    insert_at_end(head,98);
    count_of_nodes(head);
    print_data(head);
    return 0;
}
