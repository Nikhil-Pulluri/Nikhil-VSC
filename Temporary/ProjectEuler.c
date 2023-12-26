#include<stdio.h>

int satisfy(long n){
    int rem;
    int sum=0;
    long k=n;

    while(n>0){
        rem=n%10;
        sum+=rem*10;
        n=n/10;
    }

    if(sum==k){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    long i,j;

    long n;
    int k;

    for(i=999;i>100;i--){
        for(j=999;j>100;j--){
            n=i*j;
            k=satisfy(n);
            if(k==1){
                break;
            }
        }
    }
    printf("%d",n);
    printf("\n%d %d",i,j);

    return 0;
} 