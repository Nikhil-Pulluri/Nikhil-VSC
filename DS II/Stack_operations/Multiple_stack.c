#include<stdio.h>
#include<stdbool.h>

# define max 4

int arr[max];
int top1=-1;
int top2=max;

bool isfull(){
    if(top1+1==top2){
        return 1;
    }
    return 0;
}

int isempty(){
    if(top1==-1 && top2==-1){
        return 1;
    }
    return 0;
}


void push1(int n){
    if(!isfull()){
        arr[++top1]=n;
    }
    else{
        printf("\nOverflow\n");
    }
}

void push2(int n){
    if(!isfull()){
        arr[--top2]=n;
    }
    else{
        printf("\nOverflow\n");
    }
}

void pop1(){
    if(!isempty()){
        int x=arr[top1--];
    }
    else{
        printf("\nUnderflow\n");
    }
}

void pop2(){
    if(!isempty()){
        int x=arr[top2++];
    }
    else{
        printf("\nUnderflow\n");
    }
}

void display(){
    for(int i=0;i<=top1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    for(int i=max-1;i>=top2;i--){
        printf("%d ",arr[i]);
    }
}

int main(){
    push1(1);
    //push1(2);
    //pop1();
    push2(3);
    push2(4);
    push2(5);
    display();
    return 0;
}