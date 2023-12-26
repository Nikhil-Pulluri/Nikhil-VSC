#include<stdio.h>

struct node{
    int coeff,expo;
    struct node* next;
}*head1,*newnode1,*temp1,*head2,*newnode2,*temp2;

void create_node1(){
    int n;
    printf("Enter the first polynomial:\n");
    printf("Enter the no. of terms:\n");
    scnaf("%d",&n);
    temp1=head1;
    for(int i=0;i<n;i++){
        if(i==0){
            newnode1=(struct node*)malloc(sizeof(struct node));
            scanf("%d%d",&newnode1->coeff,&newnode1->expo);
            head1=temp1=newnode1;
            newnode1->next=NULL;
        }
        else{
            newnode1=(struct node*)malloc(sizeof(struct node));
            scanf("%d%d",&newnode1->coeff,&newnode1->expo);
            temp->next = newnode1;
            temp->next =temp;
        }
    }
}
void create_node2(){
        int n;
        printf("Enter second polynomial:\n");
        printf("Enter the size of the polynomial:\n");
        scanf("%d",&n);
        for(i=0;i<n;i++){
        if(i==0){
            newnode2=(struct node*)malloc(sizeof(struct node));
            scanf("%d%d",&newnode1->coeff,&newnode1->expo);
            head2=temp2=newnode2;
            newnode2->next=NULL;
        }
        else{
             newnode2=(struct node*)malloc(sizeof(struct node));
            scanf("%d%d",&newnode2->coeff,&newnode2->expo);
            temp->next = newnode2;
            temp->next =temp;
        }
        }
}

void display2(){
    temp1=head1;
    while()
}





