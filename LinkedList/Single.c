#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void print(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node* insertbeg(struct node* head){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    new->next=head;
    return new;
}

struct node* insertend(struct node* head,struct node* ptr){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    new->next=NULL;
    ptr->next=new;
    return head;
}

struct node* insertk(struct node* head,int k){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    struct node* ptr=head;
    int c=1;
    while(c<k-1){
        ptr=ptr->next;
        c++;
    }
    new->next=ptr->next;
    ptr->next=new;
    return head;
}

struct node* delbeg(struct node* head){
    struct node*temp=head;
    struct node* ptr=head->next;
    temp->next=NULL;
    free(temp);
    return ptr;
}

struct node* delend(struct node* head){
    struct node* ptr=head;
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    struct node* temp=ptr->next;
    ptr->next=NULL;
    free(temp);
    return head;
}

struct node* delk(struct node*head,int k){
    struct node* ptr=head;
    int c=1;
    while(c<k-1){
        ptr=ptr->next;
        c++;
    }
    struct node* temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return head;
}

struct node* reverse(struct node* head){
    struct node* ptr=head;
    struct node* temp=head;
    struct node* t2=ptr->next;
    struct node* t1=temp->next;
    ptr=ptr->next;
    while(ptr!=NULL){
        t2=ptr->next;
        ptr->next=temp;
        temp=t1;
        ptr=t2;
        t1=t2;
    }
    head->next=NULL;
    return temp;
}

struct node* sort(struct node* head){
    struct node* p,* q;
    p=head;
    q=NULL;
    int t;
    for(p;p!=NULL;p=p->next){
        for(q=p->next;q!=NULL;q=q->next){
            if(q->data<p->data){
                t=p->data;
                p->data=q->data;
                q->data=t;
            }
        }
    }
    return head;
}

// Merging of two linked lists;

struct node* merge(struct node* headA,struct node* headB){
    struct node* ptr=headA;
    struct node*ptrr=headB;
    while(ptr->next!= NULL){
        ptr=ptr->next;
    }
    ptr->next=ptrr;
    return headA;
}

// Printing Alternate nodes

//(even)
void alte(struct node* head){
    struct node* ptr=head;
    ptr=ptr->next;

    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next->next;
    }
}

//(odd)
void alto(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next->next;
    }
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

    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=head;
    int n;
    scanf("%d",&n);
    scanf("%d",&ptr->data);
    n--;
    while(n--){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        ptr->next=new;
        ptr=new;
    }
    ptr->next=NULL;




    // Use only when merging two linked lists

    /*struct node* headA=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=headA;
    int n;
    scanf("%d",&n);
    scanf("%d",&ptr->data);
    n--;
    while(n--){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        ptr->next=new;
        ptr=new;
    }
    ptr->next=NULL;

    struct node* headB=(struct node*)malloc(sizeof(struct node));
    ptr=headB;
    scanf("%d",&n);
    scanf("%d",&ptr->data);
    n--;
    while(n--){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&new->data);
        ptr->next=new;
        ptr=new;
    }
    ptr->next=NULL;*

    print(merge(headA,headB));*/

    print(head);

    //print(insertbeg(head));

    //print(insertend(head,ptr));

    //print(delbeg(head));

    //print(delend(head));

    //print(reverse(head));

    //print(sort(head));

    //alte(head); // take even input only

    //alto(head); // take odd input only


    

    int k;
    scanf("%d",&k);

    print(insertk(head,k));

    //print(delk(head,k));

    //freememory(head);
    return 0;
}