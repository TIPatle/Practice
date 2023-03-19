#include <iostream>

using namespace std;

bool possible( int arr[], int n ){

    int k = 1 << n;

    for ( int i = 1; i<k; i++ ){

        int sum = 0;
        int bit = i;
        int count = 0;
        int it = n;

        while ( it-- ){

            if ( bit & 1 )
                sum += arr[count];

            else 
                sum -= arr[count];

            count++;
            bit = bit >> 1;

        }

        if ( sum % 360 == 0 )
            return true;

    }

    return false;

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    if ( possible(arr, n))
        cout<<"YES"<<endl;

    else 
        cout<<"NO"<<endl;

    return 0;

}