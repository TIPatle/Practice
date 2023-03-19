#include <iostream>
#include <vector>

using namespace std;

bool subsetSumK(vector <int> arr, int n, int  k){

    if ( k == 0 )
        return 1;

    if ( n == 0 )
        return 0;

    if ( arr[n-1] <= k )
        return subsetSumK(arr, n-1, k ) | subsetSumK(arr, n-1, k-arr[n-1]);

    else if (arr[n-1] > k)
        return subsetSumK(arr, n-1, k);
}

int main(){

    int n;
    cin>>n;

    vector <int> arr(n);

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int k;
    cin>>k;

    cout<<subsetSumK(arr, n, k);

    return 0;

}