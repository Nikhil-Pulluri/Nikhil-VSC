#include<iostream>

using namespace std;

void TOH(int n, char from, char to, char aux)
{
    if(n==0) return;

    else{
        TOH(n-1, from, aux, to);
        cout << "disk moved from " << from << " rod to " << to << " rod" << endl;

        TOH(n-1, aux, to, from);

    }
}

int main()
{
    int n;

    cin >> n;

    TOH(n, 'A', 'C', 'B');

    return 0;
}