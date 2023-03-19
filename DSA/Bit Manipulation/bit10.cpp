#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int minsum = arr[0];
    int sum = arr[0];
    for ( int i = 1; i<n; i++ ){

        if ( minsum - arr[i] < 0 )
            minsum += arr[i];
        
        else 
            minsum -= arr[i];

        sum += arr[i];

    }

    if ( n == 1)
        cout<<"no"<<endl;

    else {

        if ( minsum == 0 )
            cout<<"yes"<<endl;

        else {

            if ( sum % 360 == 0)
                cout<<"yes"<<endl;

            else 
                cout<<"no"<<endl;

        }

    }
    
    return 0;

}