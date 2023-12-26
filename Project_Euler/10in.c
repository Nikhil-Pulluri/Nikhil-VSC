#include<stdio.h>

int isprime(long n){
    int c=0;
    for(long i=1;i<n/2;i++){
        if(n%i==0){
            c++;
        }
    }
    if(c==1){
        return 1;
    }
    else{
        return 1;
    }
}

int main(){
    long  n=2000000;

    long  sum=0;

    for(long i=2;i<n;i++){
        if(isprime(i)){
            sum+=i;
        }
    
    }
    printf("%d",sum);
    return 0;
}