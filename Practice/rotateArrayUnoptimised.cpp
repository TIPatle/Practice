#include <iostream>
#include <vector>

using namespace std;

vector <int> rotate( vector<int> &arr, int d ){

    int n = arr.size();

    vector <int> a(n, 0);
    for ( int i = d; i<n; i++ )
        a[i-d] = arr[i];

    for ( int i = 0; i<d; i++ )
        a[n - d + i ] = arr[i];

    return a;

}

int main(){

    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    auto ans = rotate(arr, 1);

    for ( auto it : ans )
        cout<<it<<" ";

    return 0;

}