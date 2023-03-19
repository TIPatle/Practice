#include <bits/stdc++.h>

using namespace std;

void heapify (int arr[], int n, int i ){    //O(logn)

    int largest = i;
    int l = 2*i;
    int r = 2*i + 1;

    if ( l <= n && arr[largest] < arr[l] )
        largest = l;

    if ( r <= n && arr[largest] < arr[r])
        largest = r;

    if ( largest != i ){

        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);

    }


}

void makeHeap( int arr[], int n){  // O(n)

    for ( int i = n/2; i > 0; i-- )  // O( x * logn ) = O(n)
        heapify(arr, n, i); //(O(logn))

}

int main(){

    int arr[]= {0, 10, 30, 50, 20, 35, 15};

    makeHeap(arr, 6);

    for ( int i = 1; i<= 6; i++)
        cout<<arr[i]<<" ";

    return 0;

}