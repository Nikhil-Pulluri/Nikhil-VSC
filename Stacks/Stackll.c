#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*top=NULL; 

void push(){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    new->next=top;
    top=new;
}

void pop(){
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    struct node*temp=top;
    top=top->next;
    free(temp);
}

void peak(){
    if(top==NULL){
        printf("Underflow\n");
        return;
    }
    printf("%d\n",top->data);
}

void display(){
    struct node* ptr=top;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    int k;
    while(1){
        printf("Enter the operator:\n 1-Push  2-Pop  3-Peak  4-Display\n");
        scanf("%d",&k);
        switch(k){
            case 1:
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peak();
            break;

            case 4:
            display();
            break;

            default:
            printf("The given input is invalid!\n");
        }
    }
    return 0;
}