#include <bits/stdc++.h>

using namespace std;

void heapify( int arr[], int n, int i){  // logn

    int smallest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if ( left <= n && arr[smallest] > arr[left] )
        smallest = left;

    if ( right <= n && arr[smallest] > arr[right] )
        smallest = right;

    if ( smallest != i ){

        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);

    }

}

void MakeMinHeap( int arr[], int n){  // O(n)

    for ( int i = n/2; i>0; i-- )
        heapify(arr, n, i); 

}

int main(){

    int n;
    cin>>n;

    int arr[20];
    
    for ( int i = 1; i<=n; i++ )
        cin>>arr[i];

    MakeMinHeap(arr, n);

    for ( int i = 1; i<=n; i++ )
        cout<<arr[i]<<" ";


    return 0;

}