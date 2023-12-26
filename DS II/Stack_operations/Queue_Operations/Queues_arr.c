#include<stdio.h>
#include<stdbool.h>
#define max 4

int f=-1;
int r=-1;
int arr[max];

bool isempty(){
    if(f==-1 && r==-1){
        return 1;
    }
    return 0;
}

bool isfull(){
    if(f==max-1 && r==max-1){
        return 1;
    }
    return 0;
}

void enq(int n){
    if(f==-1 && r==-1){
        f=0;
    }
    if(!isfull()){
        arr[++r]=n;
    }
    
    else{
        printf("Overflow\n");
    }
}

void deq(){
    if(isempty()){
        printf("Underflow\n");
    }
    else if(f==r)
    {
        f=r=-1;
    }
    else{
        f++;
    }
}

void peek(){
    if(!isempty()){
        printf("%d",arr[r]);  // front value to be prinetd
        
    }
    else{
        printf("\nNo value\n");
    }
}

void display(){
    if(!isempty()){
        for(int i=f;i<=r;i++){
            printf("%d ",arr[i]);
        }
    }
}

int main(){
    enq(1);
    enq(2);
    deq();
    display();
    return 0;
}