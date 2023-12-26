#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
};

struct node*f = NULL;
struct node*r = NULL;
struct node* head=NULL;

bool isempty(){
    if(f==NULL && r== NULL){
        return 1;
    }
    return 0;
}

struct node* insert_end(struct node*ptr,int n){
        struct node* new=malloc(sizeof(struct node));
        new->data=n;
        new->next=NULL;
    if(head==NULL){
        head = new;
    }
    else{
        while(ptr->next!=NULL){
        ptr=ptr->next;
        }
        ptr->next = new;
    }
        r=ptr;
    return head;
}

struct node* delete_beg(struct node* ptr){
        head=head->next;
        free(ptr);
        return head;
}

void enq(int n){
        head=insert_end(head,n);
        //r=r->next;
        f=head;
}

void deq(){
    if(isempty()){
        printf("Underflow\n");
    }
    else if(f==r){
        free(head);
    }
    else{
        head=delete_beg(head);
        f=head;
    }
}

void peek(struct node* ptr){
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

void display(struct node* ptr){
    if(!isempty()){
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main(){
    enq(1);
    enq(2);
    enq(3);
    peek(head);
    deq();
    display(head);
    return 0;
}