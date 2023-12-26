#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node*prev;
struct node*next;
}*p,*q;
struct node* sort(struct node* head){
p=head;
q=NULL;
int temp;
for(p;p!=NULL;p=p->next){
for(q=p->next;q!=NULL;q=q->next){
if(q->data<p->data){
temp=p->data;
p->data=q->data;
q->data=temp;
}
}
}
return head;
}
void printrev(struct node*lastnode){
struct node* ptr=lastnode;

while(ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->prev;
}

}
struct node* delk(struct node* head,int pos){
struct node*ptr=head;
int c=1;
while(c<(pos-1)){
ptr=ptr->next;
c++;
}
struct node*temp=ptr->next;
ptr->next=ptr->next->next;
ptr->next->prev=ptr;
free(temp);
return head;
}
struct node* dell(struct node*lastnode,struct node* head){
struct node*ptr=lastnode;

ptr->prev->next=NULL;
free(ptr);
return head;
}
struct node* delb(struct node* head){
struct node*ptr=head;
head=head->next;
free(ptr);
head->prev=NULL;
return head;

}
struct node* insertk(struct node* head,int pos){
int c=1;
struct node*ptr=head;
struct node*new=(struct node*)malloc(sizeof(struct node));
scanf("%d",&new->data);
while(c<(pos-1)){
ptr=ptr->next;
c++;
}
new->prev=ptr;
new->next=ptr->next;
ptr->next->prev=new;
ptr->next=new;
return head;
}
struct node* insertlast(struct node* lastnode,struct node* head){
struct node*new=(struct node*)malloc(sizeof(struct node));
struct node*ptr=lastnode;
scanf("%d",&new->data);
new->next=NULL;
new->prev=ptr;
ptr->next=new;
return head;
}
struct node* insertbeg(struct node* head){
struct node*new=(struct node*)malloc(sizeof(struct node));
struct node* ptr=head;
scanf("%d",&new->data);
new->prev=NULL;
new->next=ptr;
ptr->prev=new;

return new;
}
void print(struct node* head){
struct node*ptr=head;
while(ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->next;
}
printf("\n");
}

// Merging of two linked lists

struct node* merge(struct node* headA,struct node* headB){
    struct node* ptr=headA;
    struct node* ptrr=headB;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ptrr;

    return headA;
}

void freememory(struct node* head){
    struct node* ptr=head;
    struct node*temp=NULL;
    while(ptr!=NULL){
        temp=ptr;
        ptr=temp->next;
        free(temp);
    }
}

int main(){

struct node*head=(struct node*)malloc(sizeof(struct node));
struct node*ptr;
ptr=head;
int n;
scanf("%d",&n);
scanf("%d",&head->data);
head->prev=NULL;
n--;
while(n--){
struct node*new=(struct node*)malloc(sizeof(struct node));
scanf("%d",&new->data);
new->prev=ptr;
ptr->next=new;
ptr=new;
}
ptr->next=NULL;


// Use only when merging two linked lists

/*struct node*headA=(struct node*)malloc(sizeof(struct node));
struct node*ptr;
ptr=headA;
int n;
scanf("%d",&n);
scanf("%d",&headA->data);
headA->prev=NULL;
n--;
while(n--){
struct node*new=(struct node*)malloc(sizeof(struct node));
scanf("%d",&new->data);
new->prev=ptr;
ptr->next=new;
ptr=new;
}
ptr->next=NULL;


struct node*headB=(struct node*)malloc(sizeof(struct node));
ptr;
ptr=headB;
scanf("%d",&n);
scanf("%d",&headB->data);
headB->prev=NULL;
n--;
while(n--){
struct node*new=(struct node*)malloc(sizeof(struct node));
scanf("%d",&new->data);
new->prev=ptr;
ptr->next=new;
ptr=new;
}
ptr->next=NULL;

print(merge(headA,headB));*/






//printf("\nEnter the position:\n");
//int pos;
//scanf("%d",&pos);
// Creating a DLL
//print(head);
// Insertion at the beginning
//print(insertbeg(head));
// Insertion at the last
//print(insertlast(ptr,head));
// Insertion at the kth position
//print(insertk(head,pos));
// Deletion at the beginning
//print(delb(head));

// Deletion at the end
//print(dell(ptr,head));
// Deletion at the kth position
//print(delk(head,pos));
// Reversing a DLL
//printrev(ptr);
// Soring a DLL
//print(sort(head));

freememory(head);

return 0;
}