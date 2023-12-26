#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

void print(struct node *head)
{
    struct node *ptr = head;
    printf("%d ", ptr->data);
    ptr = ptr->next;
    while (ptr != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *insertbeg(struct node *p)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new->data);
    struct node *ptr = p->next;
    new->prev = p;
    new->next = p->next;
    p->next = new;
    ptr->prev = new;
    return new;
}

struct node *insertend(struct node *p)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new->data);
    struct node *ptr = p->next;
    p->next = new;
    new->prev = p;
    new->next = ptr;
    ptr->prev = new;
    return ptr;
}

struct node *insertk(struct node *head, int k)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &new->data);
    struct node *ptr = head;
    int c = 0;
    while (c != k - 1)
    {
        ptr = ptr->next;
        c++;
    }
    new->next = ptr->next;
    new->prev = ptr;
    new->next = ptr->next;
    ptr->next = new;
    return head;
}

struct node *delbeg(struct node *p)
{
    struct node *temp = p->next;
    p->next = temp->next;
    temp->next->prev = p;
    free(temp);
    return p->next;
}

struct node *delend(struct node *p)
{
    struct node *ptr = p->prev;
    struct node *temp = p;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return ptr->next;
}

struct node *delk(struct node *head, int k)
{
    struct node *ptr = head;
    int c = 1;
    while (c < k - 1)
    {
        ptr = ptr->next;
        c++;
    }
    struct node *temp = ptr->next;
    ptr->next = ptr->next->next;
    temp->next->prev = ptr;
    free(temp);
    return head;
}

void reverse(struct node* head,struct node* p){
    struct node* ptr=p;
    printf("%d ",ptr->data);
    ptr=ptr->prev;
    while(ptr!=p){
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
}



struct node *sort(struct node *head)
{
    struct node *p;
    struct node *q;
    p = head;
    q = NULL;
    int t;
    for (p; p->next != head; p = p->next)
    {
        for (q = p->next; q->next != head; q = q->next)
        {
            if (q->data < p->data)
            {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
    return head;
}

struct node* merge(struct node* headA,struct node* headB){
    struct node* ptr=headA;
    struct node* ptrr=headB;

    ptr=ptr->next;
    ptrr=ptrr->next;
    while(ptr->next!=headA || ptrr->next!=headB){
        ptr=ptr->next;
        ptrr=ptrr->next;
    }

    ptr->next=headB;
    ptrr->next=headA;

    return headA;
}

void freememory(struct node *head)
{
    struct node *temp = head;
    struct node *ptr = head;
    ptr = ptr->next;
    free(temp);
    while (ptr != head)
    {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    scanf("%d", &ptr->data)
     ;
    n--;
    while (n--)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new->data);
        new->prev = ptr;
        ptr->next = new;
        ptr = ptr->next;
    }
    ptr->next = head;
    head->prev=ptr;

    // Use only when merging two linked lists

    /*int n;
    scanf("%d", &n);
    struct node *headA = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = headA;
    scanf("%d", &ptr->data);
    n--;
    while (n--)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new->data);
        new->prev = ptr;
        ptr->next = new;
        ptr = ptr->next;
    }
    ptr->next = headA;


    scanf("%d", &n);
    struct node *headB = (struct node *)malloc(sizeof(struct node));
    ptr = headB;
    scanf("%d", &ptr->data);
    n--;
    while (n--)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &new->data);
        new->prev = ptr;
        ptr->next = new;
        ptr = ptr->next;
    }
    ptr->next = headB;

    print(merge(headA,headB));*/

    print(head);
    //print(insertnbeg(ptr));
    //pint(insertend(ptr));
    // int k;
    // scanf("%d",&k);
    //print(insertk(head,k));
    // print(delbeg(ptr));
    // print(delend(ptr));
    // print(delk(head,k));
    reverse(head,ptr);
    //print(sort(head));


    // testing section
    //print(ptr->prev);
    
    freememory(head);
}