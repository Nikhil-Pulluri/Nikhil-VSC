#include<stdio.h>
int stack[5];
int top=-1;

void push(){
    if(top==4){
        printf("stack is full\n");
    }
    else{
    int k;
    scanf("%d",&k);
    top++;
    stack[top]=k;
    }
    
}

void pop(){
    if(top==-1){
        printf("stack is empty\n");
        return;
    }
    top--;
}

void peak(){
    if(top==-1){
        printf("stack is empty\n");
        return;
    }
    printf("%d\n",stack[top]);
}

void display(){
    for(int i=top;i>-1;i--){
    printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    int p;
    while(1){
        scanf("%d",&p);

        switch(p){
            case 1:
            push();
            break;

            case 2:
            pop();
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