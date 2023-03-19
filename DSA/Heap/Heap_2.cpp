// Delete the node root node

#include <bits/stdc++.h>

using namespace std;

int n;



void deleteMaxHeap( int arr[] ){  // logn 

    arr[0] = arr[n-1];
    n -= 1;

    int i = 0;

    while ( i < n){

        if ( 2*i > n && 2*i + 1> n)
            break;

        int left = -1;
        int right = -1;

        if ( n > 2*i )
            left = arr[2*i];

        if ( n > 2*i+1 )
            right = arr[2*i + 1];
        
        int large ;

        if ( n > 2*i && n > 2*i+1 ) 
            large = left > right ? 2*i : 2*i + 1;

        else if ( n > 2*i )
            large = 2*i;

        else 
            large = 2*i + 1;

        if ( arr[i] < arr[large]){

            int temp = arr[i];
            arr[i] = arr[large];
            arr[large] = temp;

        }

        i = large;

    }

}

int main(){

    cin>>n;

    int arr[20]; 

    for ( int i = 0; i<n; i++)
        cin>>arr[i];

    deleteMaxHeap(arr);
    
    for( int i = 0; i<n; i++ )
        cout<<arr[i]<<" ";

    return 0;
}