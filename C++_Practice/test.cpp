#include<iostream>
using namespace std;

int streak(int n){
    int c=0;
    int k;

    for(k=0;k>=0;k++){
        if((n+k)%(k+1)==0){
            c++;
            k++;
        }
        else{
            return 0;
            break;
        }
    }
    return c;
}

int main(){
    int s,N;
    cin >> s >> N;
    int count=0,c;
    for(int i=2;i<=N;i++){
        c = streak(i);
        if(c==s){
            count ++;
        }
    }
    cout << count;
    return 0;
}