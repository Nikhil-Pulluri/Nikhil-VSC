#include<stdio.h>
#include<stdbool.h>
int top=-1;
int arr[100];

bool isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

bool isfull(){
    if(top==99){
        return 1;
    }
    return 0;
}

void push(){
    if(isfull()==0){
        int n;
        scanf("%d",&n);
        top++;
        arr[top]=n;
    }
    else{
        printf("Stack is already full\n");
    }
}

int pop(){
    if(isempty()==0){
        int t=arr[top];
        top--;
        return t;
    }
    else{
        printf("Stack is already empty\n");
    }
}

void peek(){
    if(isempty()==0){
        printf("%d\n",arr[top]);
    }
    else{
        printf("Stack is already empty\n");
    }
}

void display(){

    if(isempty()==0){
        for(int i=0;i<=top;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    else{
        printf("Stack is already empty\n");
    } 
}

int main(){
    push();
    push();
    push();
    display();
    printf("\n%d\n",pop());
    display();
    peek();
    return 0;
    
}