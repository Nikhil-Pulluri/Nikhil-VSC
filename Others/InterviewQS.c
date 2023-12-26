// Interview Questions

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

// Q) How to compare two linked lists?
// function to compare two linked lists

int compare(struct node* headA,struct node* headB){

    if(headA == NULL && headB == NULL)
    return 1;

    if(headA == NULL || headB == NULL)
    return 0;

    if(headA->data == headB->data){
        return comapre(headA->next,headB->next);
    }
    else{
        return 0;
    }
    while(headA && headB){
        if(headA->data == headB->data){
            headA=headA->next;
            headB=headB->next;
        }
        else{
            return 0;
        }
    }
    if(headA==NULL && headB==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// How to delete a duplicate element in a LL?
// Deleting duplicate elements in LL

struct node* deleteDuplicate(struct node* head){
    struct node* curr=head;
    while(curr->next){
        if(curr->data == curr->next->data){
            struct node* t = curr->data;
            t->next=NULL;
            free(t);
            curr->next = curr->next->next;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

// How can you detect a cycle (loop) in a Linked list?
// Asked in Amazon Interview frequently
// Fast pointer(traverse alternate nodes) and slow pointer technique(traverse next node)

// Q) Length of cycle (TRY)
// Q) Starting point of cycle (TRY)

// Function to detect a loop

int detectLoop(struct node* head){
    struct node* fptr = head;
    struct node* sptr = head;

    if(head==NULL){
        return 0;
    }

    do {
        if(fptr->next == NULL || fptr->next->next == NULL)
            return 0;
        fptr=fptr->next->next;
        sptr=sptr->next;
    }while(fptr!=sptr);
    return 1;
}


// How to find the merging point of a two joined Linked Lists?

// Q) Reverse any pair in Linked List
// Q) Reverse any k nodes in Linked List

int FindMergeNode(struct node* headA, struct node* headB){
    int L1=0,L2=0;

    for(struct node* A=headA; A; A=A->next) 
    L1++;

    for(struct node* A=headB; A; A=A->next)
    L2++;

    while(L1>L2){
        headA = headA->next; 
        L1--;
    }

    while(L1<L2){
        headB = headB->next; 
        L2--;
    }

    while(headA!=headB){
        headA=headA->next;
        headB=headB->next;
    }
    return headA->data;
}

// Q) OS LRU of a linked list (Home work for next year)

// 





