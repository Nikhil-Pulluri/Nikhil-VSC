#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}Node;
Node*temp=NULL;
Node*push(Node*head,int val){
    Node*n=(Node*)malloc(sizeof(Node));
    n->data=val;
    n->next=NULL;
    if(head==NULL)
        head=temp=n;
    else{
        temp->next=n;
        temp=n;
    }
    return head;
}
Node*reveres_kNodes(Node*head,int k){
    int i=1;Node*curr,*prev=NULL,*next;
    while(i<=k){
        next=curr->next;
        curr->next=prev;
        curr=prev;
        curr=next;
        i++;
    }
    if(head->next!=NULL)
        head->next=reveres_kNodes(next,k);
    return prev;
}
void print(Node* head){
    Node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    Node*head=NULL;
    int k;
    // scanf("%d",&k);1
    while(1){
        scanf("%d",&k);
        if(k<=0)
            break;
        head=push(head,k);
    }
    print(head);
    scanf("%d",&k);
    head=reveres_kNodes(head,k);
    print(head);

}