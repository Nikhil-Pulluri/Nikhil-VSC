#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node*next;
 };

 void print(struct node* head){
    struct node*ptr=head;
    printf("%d ",ptr->data);
    ptr=ptr->next;
    while(ptr!=head){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
 }

 struct node* insertbeg(struct node *ptr){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    new->next=ptr->next;
    ptr->next=new;
    return new;
 }

 struct node* insertend(struct node* ptr){
  struct node*new=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&new->data);
  new->next=ptr->next;
  ptr->next=new;
  return new->next;
 }
 
 struct node* insertk(struct node* head,int k){
     struct node*new=(struct node*)malloc(sizeof(struct node));
     scanf("%d",&new->data);
     struct node*ptr=head;
     //struct node*p=head;
     int c=1;
     while(c<k-1){
         //p=ptr;
         ptr=ptr->next;
         c++;
     }
     new->next=ptr->next;
     ptr->next=new;
     //new->next=p->next;
     //p->next=new;
     return head;
 }
 
 struct node* delbeg(struct node*p){
     struct node*ptr=p->next;
     p->next=ptr->next;
     free(ptr);
     return p->next;
     
 }
 struct node* delend(struct node*head,struct node*p){
    struct node* ptr=head;
    while(ptr->next!=p){
        ptr=ptr->next;
    }
    struct node*temp=ptr->next;
    ptr->next=head;
    free(temp);
    return head;
 }

 struct node*delk(struct node*head,int k){
    struct node*ptr=head;
    int c=1;
    while(c<k-1){
        ptr=ptr->next;
        c++;
    }
    struct node*temp=ptr->next;
    ptr->next=ptr->next->next;
    free(temp);
    return head;
 }

 struct node*reverse(struct node*head,struct node*p){
    struct node*ptr=head;
    struct node*temp=head;
    struct node*k=ptr->next;
    ptr->next=p;
    ptr=k;
    struct node*l=k;

    while(ptr!=head){
        k=ptr->next;
        ptr->next=temp;
        ptr=k;
        temp=l;
        l=k;
    }
    return temp;
 }

struct node *sort(struct node *head){
    struct node *p;
    struct node *q;
    p = head;
    q = NULL;
    int t;
    for (p; p->next != head; p = p->next){
        for (q = p->next; q->next != head->next; q = q->next){
            if (q->data < p->data){
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return head;
}

// Merging of two linked lists

struct node* merge(struct node* headA,struct node* headB){
    struct node* ptr=headA;
    struct node* ptrr=headB;

    ptr=ptr->next;

    while(ptr->next!=headA){
        ptr=ptr->next;
    }
    ptr->next=ptrr;

    ptrr=ptrr->next;
    while(ptrr->next!=headB){
        ptrr=ptrr->next;
    }

    ptrr->next=headA;

    return headA;

}

void freememory(struct node* head){
    struct node* ptr=head;
    struct node*temp=head;
    ptr->next;
    free(temp);
    while(ptr!=head){
        temp=ptr;
        ptr=temp->next;
        free(temp);
    }
}

 int main(){

    int n;
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node*ptr=head;
    scanf("%d",&n);
    scanf("%d",&ptr->data);
    n--;
    while(n--){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        ptr->next=new;
        ptr=ptr->next;
    }
    ptr->next=head;
    

   // Use only when merging of two linked lists
    /*int n;
    struct node* headA=(struct node*)malloc(sizeof(struct node));
    struct node*ptr=headA;
    scanf("%d",&n);
    scanf("%d",&ptr->data);
    n--;
    while(n--){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        ptr->next=new;
        ptr=ptr->next;
    }
    ptr->next=headA;


    struct node* headB=(struct node*)malloc(sizeof(struct node));
    ptr=headB;
    scanf("%d",&n);
    scanf("%d",&ptr->data);
    n--;
    while(n--){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        ptr->next=new;
        ptr=ptr->next;
    }
    ptr->next=headB;

    print(merge(headA,headB));*/




    //print(head);
   print(insertbeg(ptr));
   // print(insertend(ptr));
   //print(delbeg(ptr));
   //print(delend(head,ptr));
   //print(reverse(head,ptr));
   //print(sort(head));
   
   //int k;
   //scanf("%d",&k);
   //print(insertk(head,k));
   //print(delk(head,k));


   freememory(head);
   
    return 0;
 }