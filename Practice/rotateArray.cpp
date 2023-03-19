#include <iostream>
#include <vector>

using namespace std;

void rotate( vector<int> &arr, int d ){

    int n = arr.size();

    if ( d % n == 0 )
        return;

    else
        d = d % n;

    int a[d];
    for ( int i = 0; i<d; i++ )
        a[i] = arr[i];

    for ( int i = d; i<n; i++ )
        arr[i-d] = arr[i];

    for ( int i = n - d; i<n; i++ )
        arr[i] = a[i + d - n ];

}

int main(){

    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    rotate(arr, 1);

    for ( auto it : arr )
        cout<<it<<" ";

    return 0;

}