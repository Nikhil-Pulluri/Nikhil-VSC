
#include<stdio.h>
#include<stdlib.h>

struct node{
    int co;
    int ex;
    struct node* next;
};

struct node* dup(struct node* result){
    struct node* ptr=result;
    // struct node*p =NULL;

    while(ptr->next!=NULL){
       // p=ptr->next;;
        /*while(p!=NULL){
            if(ptr->ex==p->ex){
                ptr->next=p->next;
                ptr->co+=p->co;
                //free(p);
            }
                p=ptr->next;
        }*/
        if(ptr->ex == ptr->next->ex){
            ptr->co+=ptr->next->co;
            struct node* temp=ptr->next;
            ptr->next=ptr->next-> next;
            free(temp);

        }
        else
        ptr=ptr->next;
    }
    return result;
}
struct node* insert(struct node* head, int coeff, int expo){
    struct node* newn=malloc(sizeof(struct node));
    newn->co=coeff;
    newn->ex=expo;
    newn->next=NULL;
    struct node* ptr;

    if(head==NULL || expo > head->ex){
        newn->next=head;
        head=newn;
    }
    else {
        ptr=head;
        while(ptr->next!=NULL && ptr->next->ex > expo){
            ptr=ptr->next;
        }
        newn->next=ptr->next;
        ptr->next = newn;
    }
    return head;

}

struct node* mply(struct node* head1, struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* result=NULL;

    while(ptr1!=NULL){
        ptr2=head2;
        while(ptr2!=NULL){
            result=insert(result, (ptr1->co*ptr2->co), (ptr1->ex+ptr2->ex) );
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }

    
    return dup(result);
}



struct node* create(struct node* head){
    int n,coeff,expo,i;
    printf("Enter the number of terms in the polynomial:\n");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter the coeffcient for the %d term:\n",(i+1));
        scanf("%d",&coeff);
        printf("Enter the exponent for the %d term:\n",(i+1));
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

            printf("(%dx^%d)",ptr->co,ptr->ex);
            ptr=ptr->next;
            if(ptr!=NULL){
                printf("+");
            }
            else{
                printf("\n");
            } 
        }
    }
}

int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;

    head1=create(head1);
    head2=create(head2);

    print(mply(head1,head2));
    return 0;

}