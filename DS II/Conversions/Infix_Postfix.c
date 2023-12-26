// Fuck you
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

int top=-1;
int ptr=-1;
char arr[100]; // infix
char post[100]; // postfix

bool isempty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char n){
    top++;
    arr[top]=n;
}

char pop(){
    char x = arr[top];
    top--;
    return x;
}

int priority(char n){
    if(n=='+' || n=='-'){
        return 1;
    }
    else if(n=='*' || n=='/'){
        return 2;
    }
    else if(n=='^'){
        return 3;
    }
}

int type(char n){
    if(n>=48 && n<=57){
        return 0;
    }
    else if(n=='('){
        return 1;
    }
    else if(n==')'){
        return 2;
    }
    else{
        return 3;
    }
}

void inf_post(char inp[]){
    int len=strlen(inp);
    for(int i=0;i<len;i++){
        int test=type(inp[i]);
        char q=inp[i];
        char n;

        switch(test){
            case 0:
                ptr++;
                post[ptr]=q;
                break;
            case 1:
                push(q);
                break;
            case 2:
                while((n=pop())!='(')
                    post[ptr++]=n;
                break;
            case 3:
                    while(!isempty() && priority(q)<=priority(arr[top])){
                        ptr++;
                       post[ptr] = pop();
                    }
                    push(q);
                break;
        }
        
    }
    while(!isempty()){
        ptr++;
        post[ptr]=pop();
    }
    printf("%s",post);
}

int main(){
    char inp[100];
    scanf("%s",inp);
    //printf("%c",inp[1]);

    inf_post(inp);
    return 0;
}