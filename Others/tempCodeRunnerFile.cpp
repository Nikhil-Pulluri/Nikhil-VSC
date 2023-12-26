#include<iostream>
#include<cstdlib>

using namespace std;

#define max 5

// struct node{
//     int data;
//     struct node* next;
// }

// struct node* 

int main()
{
    int M[5][5];

    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {
            cin >> M[i][j];
        }
        cout << endl;
    }

    // initial matrix printing
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    // Algo

    for(int k=0; k<max;k++)
    {
        for(int i=0;i<max;i++)
        {
            for(int j=0;j<max;j++)
            {
                if(M[i][j] > M[i][k]+M[k][j]) M[i][j]=M[i][k]+M[k][j];
            }
        }
    }

    // Shrtest result

    for(int i=0; i<max; i++)
    {
        for(int j=0; j<max; j++)
        {
            cout << M[i][j];
        }
    }
}