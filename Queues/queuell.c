#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL;

void enq(){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    if(front==NULL){
        front=rear=new;
        new->next=NULL;
    }
    else{
        rear->next=new;
        new->next=NULL;
        rear=new;
    }
    
}

void dq(){
    if(front>rear){
        printf("Underflow\n");
        return;
    }
    struct node*temp=front;
    front=front->next;
    free(temp);
}

void peak(){
    if(front>rear){
        printf("Underflow\n");
        return;
    }
    printf("%d\n",front->data);
}

void display(){
    struct node*ptr=front;
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
            enq();
            break;

            case 2:
            dq();
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