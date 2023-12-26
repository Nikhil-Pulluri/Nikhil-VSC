#include<stdio.h>
int q[10];
int front=0;
int rear=0;

void enq(){
    int n;
    if(rear==9){
        printf("Overflow\n");
    }
    scanf("%d",&n);
    q[rear]=n;
    rear++;
}

void dq(){
    if(rear==front){
        printf("Underflow\n");
    }
    front++;
}

void peak(){
    if(rear==front){
        printf("Underflow\n");
    }
    printf("%d\n",q[rear-1]);
}

void display(){
    for(int i=front;i<rear;i++){
        printf("%d ",q[i]);
    }
    printf("\n");
}


int main(){
    int k;
    while(1){
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
           
        }
    }
return 0;
}