// sliding window

#include <iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int s;
    cin>>s;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int start = 0; 
    int end = 0;

    int sum = 0;

    while( end<n && start<=end ){

        sum += arr[end];

        if ( sum == s ){

            cout<<start + 1 <<" "<<end + 1<<endl;
            break;

        }

        while ( sum > s ){

            sum -= arr[start];
            start ++;

            if ( sum == s ){

                cout<<start + 1 <<" "<<end + 1<<endl;
                return 0;

            }

        }

        end++;

    }

    return 0;

}