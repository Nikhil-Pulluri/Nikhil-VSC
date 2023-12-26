#include<iostream>

using namespace std;

int main(){
    int x[100][100];

    int row=3;
    int coulumns=4;

    for(int i=1;i<=row;i++){
        for(int j=1; j<=coulumns;j++){
            if(j==1){
                x[i][j]=i;
            }
            if(j==2){
                x[i][j]='A';
            }
            if(j==3){
                x[i][j]='B';
            }
            if(j==4){
                x[i][j]='C';
            }
        }
    }

    for(int i=1;i<=row;i++){
        for(int j=1;j<=coulumns;j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter the number of Pasengers: ";
    int p;
    cin >> p;

    int sn;
    int sl;

    while(p--){
    cout << "\nEnter Seat Number: ";
    
    cin >> sn;

    cout << "/n Enter seat Label: ";
    
    cin >> sl;
    }
   

    x[sn][sl]='X';

    for(int i=1;i<=row;i++){
        for(int j=1;j<=coulumns;j++){
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

      

    return 0;





}