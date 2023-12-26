#include<iostream>

using namespace std;

int main(){
    int a[100];
    int n;

    cin >> n;
    double sum=0;

    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    int max=a[0];

    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }

    cout << sum/n << "\n";
    cout << max << "\n";

    for(int i=0;i<n;i++){
        cout << a[i]<< " ";
    }

    return 0;


}