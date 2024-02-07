// Bucket Sorting

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void Bucket_Sort(vector<int> in, int n)
{
    vector<int> bucket[n];
    int index;

    for(int i=0;i<n;i++)  // Loading of Buckets
    {
        index = in[i]*n/100;   // **Important step
        bucket[index].push_back(in[i]);
    }

    for(int i=0;i<n;i++)  // Partial Sortingin buckets
    {
        sort(bucket[i].begin(),bucket[i].end());
    }

    // printing of sorted array

    int size;

    cout << endl << "The sorted array:" << endl;
    for(int i=0; i<n;i++)
    {
        size = bucket[i].size();
        for(int j=0;j<size;j++)
        {
            cout << bucket[i][j] << " ";
        }
        
    }

    
}

int main()
{
    vector<int> in;
    int n;
    cout << "Number of elements: " << endl;
    cin >> n;
    int e;

    cout << "Enter the elements: " << endl;

    for(int i=0;i<n;i++)
    {
        cin >> e;
        in.push_back(e);
    }

    Bucket_Sort(in,n);

    return 0;
}