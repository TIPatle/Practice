#include <iostream>

using namespace std;

int profit( int arr[], int n ){

    if ( n < 3 )
        return 0;

    int lastPrice = arr[n-1];
    int firstPrice = arr[0];

    int result = 0; 

    for ( int i = 1; i<n-2; i++ ){

        int prof1 = arr[i] - firstPrice;
        int prof2 = lastPrice - arr[i+1];

        result = max(result, prof1+prof2);

    }

    return result;

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ ) 
        cin>>arr[i];

    cout<<profit(arr, n)<<endl;

    return 0;

}