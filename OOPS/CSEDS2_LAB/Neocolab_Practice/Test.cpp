#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> test;
    int n;
    cout << "Enter the number of elements:" << endl;
    cin >> n;

    for(int i=0;i<n;i++){
        int x;
        cout << "Enter the element" << endl;
        cin >> x;
        test.push_back(x);
    }
    for(int i=0;i<test.size();i++){
        cout << test[i] << " ";
    }

    cout << endl <<"We removed one element here" ;

    test.pop_back();
    cout << endl;

    for(int i=0;i<test.size();i++){
        cout << test[i] << " ";
    }

    test.clear();

    cout << endl << "We have cleared the vector and trying to find the number of elements left in the vector";
    cout << endl << "size = " <<test.size() << endl;
    cout << "Whether the vector is empty?" << endl << test.empty() << endl;

    return 0;
}
