#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MinDifference( vector <int> arr, int n ){

    int s1 = 0;
    int s2 = 0;

    for ( int i = 0; i<n/4; i++ ){

        s1 += arr[n - i - 1] - arr[i] ;
        s2 += arr[n - n/4 - i - 1] - arr[n/4 + i] ;

    }

    return s1 - s2;

}

int MaxDifference ( vector <int> arr , int n){

    int s1 = 0;
    int s2 = 0;

    for ( int i = 0; i< n/2; i++ ){

        s1 += arr[i];
        s2 += arr[n -i -1];

    }

    return (s2 - s1);

}

int main(){
 
    int n;
    cin>>n;

    vector <int> arr(n);
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    sort(arr.begin(), arr.end());

    cout<<MinDifference(arr, n)<<" "<<MaxDifference(arr, n);

    return 0;

}