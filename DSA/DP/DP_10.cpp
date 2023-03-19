#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequence(vector<int> &arr, int start, int end, int previous){

    if ( start >= end )
        return 0;

    if ( previous > arr[start] )
        return longestIncreasingSubsequence(arr, start +1, end, previous);

    return max( longestIncreasingSubsequence(arr, start + 1, end, previous ), longestIncreasingSubsequence(arr, start+1, end, arr[start]) + 1);

}


int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<longestIncreasingSubsequence(arr, 0, n, 0)<<endl;

    return 0;

}