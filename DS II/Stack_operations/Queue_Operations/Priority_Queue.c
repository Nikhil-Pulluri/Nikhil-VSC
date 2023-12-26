// High Prioity Queue
#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    int priority;
    struct node*next;
};
struct node*insert(int d,int p)
{
    struct node*temp=malloc(sizeof(struct node));
    temp->priority=p;
    temp->data=d;
    temp->next=NULL;
    return temp;
}
struct node*push(struct node*head,int d,int p)
{
    struct node*ptr=head,*temp;
     temp=insert(d,p);
    if(head==NULL || head->priority > p )
    {
       temp->next=head;
       head=temp;
    }
    else{
        while(ptr->next!=NULL && ptr->next->priority <= p)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }
    return head;
}
struct node*pop(struct node*head)
{
    struct node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
int peek(struct node*head)
{
    return head->data;
}
int isEmpty(struct node*head)
{
   return head==NULL;
}
int main()
{
    struct node*head=NULL;
   int n;
   scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        head=push(head,a,b);
    }
    struct node*Head=head;
    while(Head!=NULL){
    printf("Data: %d Priority: %d\n",Head->data,Head->priority);
    Head=Head->next;
    }
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    int priority;
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