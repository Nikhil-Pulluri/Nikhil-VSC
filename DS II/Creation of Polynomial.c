#include<stdio.h>
#include<stdlib.h>

struct node{
    float co;
    int ex;
    struct node* next;
};

// Creating a linked list 
// Arrangning the nodes in an order of exponents


struct node* insert(struct node* head, float coeff, int expo){
    struct node* temp;

    struct node* new=malloc(sizeof(struct node));
    new->co = coeff;
    new->ex = expo;
    new->next = NULL;

    if(head==NULL || expo > head->ex){
        new->next = head;
        head = new;
    }
    else {
        temp = head;
        while(temp->next!= NULL && temp->next->ex > expo){
            temp = temp->next;
        }
        new->next = temp->next; 
        temp->next = new;
    }

    return head;
}

struct node* create(struct node* head){
    int n;
    int i;
    float coeff;
    int expo;

    printf("Enter the number of terms in the polynominal:\n");
    scanf("%d",&n);


    for(i=0;i<n;i++){
        printf("Enter the term %d Coeffcient: \n",i+1);
        scanf("%f",&coeff);

        printf("Enter the term %d Exponent: \n",i+1);
        scanf("%d",&expo);

        head=insert(head,coeff,expo);

    }
    return head;

}



void print(struct node* head){
    struct node* ptr;
    ptr = head;

    if(ptr==NULL){
        printf("It is an empty polinomial\n");
    }
    else{
        while(ptr!=NULL){

            printf("(%.1fx^%d)",ptr->co,ptr->ex);
            ptr=ptr->next;
            if(ptr!=NULL){
                printf("+");
            }
            else{
                printf("\n");
            } 
           /* if(ptr->ex!=0){
                printf("%.1fx^%d",ptr->co,ptr->ex);
                printf("+");
                }

            else{
                printf("%.1f",ptr->co);
            }
            ptr=ptr->next; */
        }
    }
}



int main(){
    struct node* head=NULL;

    //head=(struct node*)malloc(sizeof(struct node));

    head=create(head);
    print(head);

    return 0;
}


