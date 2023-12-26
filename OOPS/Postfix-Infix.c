#include<stdio.h>

char expr[]={'3','7','+'};

int infix[100];

int top=-1;

char pop(){
    if(top==-1){
        return 0;
    }
    char k= infix[top];
    top--;
    return k;
}

void push(int k){
    top++;
    infix[top]=k;
}

int is_operator(char x){
    if((x=='+')|| (x=='-') || (x=='*') || (x=='/')){
        return 1;
    }
    else{
        return 0;
    }
}

int evaluate(int opr2,int opr1,char p){
    switch(p){
        case '+':
        return opr2+opr1;
        break;

        case '-':
        return opr2-opr1;
        break;

        case '*':
        return opr2*opr1;
        break;

        case '/':
        return opr2/opr1;
        break;
    }
}

int main(){

    char* p = expr;

    int opr1,opr2;
    int res;

    while(p!='\0'){
        if(is_operator(&p)){
            opr1=pop();
            opr2=pop();
            res = evaluate(opr2,opr1,&p);
            push(res);
            p++;
        }
        if(!is_operator(&p)){
            push(p);
            p++;
        }
    }
    printf("%d",infix[top]);
    return 0;
}