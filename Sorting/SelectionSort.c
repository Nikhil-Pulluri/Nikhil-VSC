#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    // Sorting starts
    int min=a[0];

    for(int i=0;i<n;i++){
        int c=0;
        min =a[i];
        for(int j=i+1;j<n;j++){
            if(a[j]<min){
            min=a[j];
            c=j;
            }
        }
        if(c!=0){
        a[c]=a[i];
        a[i]=min;

        }
    }

    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}