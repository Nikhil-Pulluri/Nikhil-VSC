// Addition of polynomials using linked lists 
#include<stdio.h>
#include<stdlib.h>

struct node{
    int co;
    int ex;
    struct node* next;
};

// Creating a linked list 
// Arrangning the nodes in an order of exponents (decreasing)


struct node* insert(struct node* head, int coeff, int expo){
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
    int coeff;
    int expo;

    printf("Enter the number of terms in the polynominal:\n");
    scanf("%d",&n);


    for(i=0;i<n;i++){
        printf("Enter the term %d Coeffcient: \n",i+1);
        scanf("%d",&coeff);

        printf("Enter the term %d Exponent: \n",i+1);
        scanf("%d",&expo);

        head=insert(head,coeff,expo);

    }
    return head;
}

// struct node* Add_Polynomial(struct node* head1, struct node* head2){
//     struct node* ptr1=head1;
//     struct node* ptr2=head2;

//     struct node* result=NULL;

//     while(ptr1!=NULL){
//         ptr2=head2;
//         while(ptr2!=NULL){
//             if(ptr1->ex == ptr2->ex){
//                 result=insert(result , (ptr1->co+ptr2->co) , ptr2->ex);
//             }
//             ptr2=ptr2->next;
//         }
//         ptr1=ptr1->next;
//     }
//     return result;
// }

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



struct node*polyadd(struct node*head1,struct node*head2)
{
	struct node*ptr1=head1;
	struct node*ptr2=head2;
	struct node*head3=NULL;
	while(ptr1!=NULL && ptr2!=NULL)
	{
	   if(ptr1->ex==ptr2->ex){
	     head3=insert(head3,ptr1->co+ptr2->co,ptr1->ex);
	    ptr1=ptr1->next;
	    ptr2=ptr2->next; 
	    }
	
        else if(ptr1->ex>ptr2->ex){
            head3=insert(head3,ptr1->co,ptr1->ex);
            ptr1=ptr1->next;
        }
        
        else if(ptr2->ex>ptr1->ex){
            head3=insert(head3,ptr2->co,ptr2->ex);
            ptr2=ptr2->next;
        }
    }


	while(ptr1!=NULL){
	    head3=insert(head3,ptr1->co,ptr1->ex);
	    ptr1=ptr1->next;
    }


	while(ptr2!=NULL){
	    head3=insert(head3,ptr2->co,ptr2->ex);
	    ptr2=ptr2->next;
    }
	return head3;
	
}






int main(){
    struct node* head1=NULL;
    struct node* head2=NULL;

    //head=(struct node*)malloc(sizeof(struct node));

    head1=create(head1);
    head2=create(head2);
    print(polyadd(head1,head2));

    return 0;
}




/*
Testin 1



#include<stdio.h>
struct node{
    int co;
    int ex;
    struct node* next;
};

struct node* insert(struct node* head, int coe, int exp){
    struct node* new = malloc(sizeof(struct node));
    new->co = coe;
    new->ex = exp;
    new->next = NULL;


    if(head == NULL || exp > head->ex){
        new->next = head;
        head = new;
        return head;
    }

    else{
        struct node* temp = head;
        while(temp!= NULL && exp < temp->next->ex){
            temp = temp->next;
        }
        new->next = temp->next;
        temp->next = new;

        return head;
    }
}

struct node* create(struct node* head){
    int coe,exp,n;

    // input (n);

    while(n--){
        // input (c,e);

        head = insert(head,coef, exp);
    }

    return head;
}

struct node* add(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head = NULL;

    while(ptr1 != NULL && ptr2!= NULL){
            if(ptr1->ex == ptr2->ex){
            head = insert(head, ptr1->co + ptr2->co, ptr1->ex);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            }

            if(ptr1->ex > ptr2->ex){
                head = insert(head, ptr1->co, ptr1->ex);
                ptr1 = ptr1->next;
            }

            if(ptr2->ex > ptr1->ex){
                head = insert(head, ptr2->co, ptr2->ex);
                ptr2 = ptr2->next;
            }

            if(ptr1!= NULL){
                head = insert(head, ptr1->co, ptr1->ex);
                ptr1 = ptr1->next;
            }

            if(ptr2!=NULL){
                head = insert(head, ptr2->co, ptr2->ex);
                ptr2 = ptr2->next;
            }

            return head;

    }

    
}*/

