#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define m 2
int top=-1;
int arr[m];

void push(int n){
    arr[++top]=n;
}

int pop(){
    int x=arr[top--];
    return x;
}

int type(char c){
    int t= c-48;
    if(t>=0 && t<=9){
        return 1;
    }
    return 0;
}

int evaluate(char inp[]){
    int len=strlen(inp);
    int op1,op2;
    for(int i=0;i<len;i++){
        char q = inp[i];
        if(type(q)){
            push(q-'0');
        }
        else{
            switch(q){
                case '+':
                    op2=pop();
                    op1=pop();
                    push(op1+op2);
                    break;
                case '-':
                    op2=pop();
                    op1=pop();
                    push(op1-op2);
                    break;
                case '*':
                    op2=pop();
                    op1=pop();
                    push(op1*op2);
                    break;
                case '/':
                    op2=pop();
                    op1=pop();
                    push(op1/op2);
                    //break;
            }
        }
    }
    return pop();
}

int main(){
    char inp[100];
    scanf("%s",inp);
    printf("%d",evaluate(inp));
    return 0;
}

