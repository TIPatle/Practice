// value  Insertion Max heap & Min Heap

#include <bits/stdc++.h>

using namespace std;

int n;

void InsertionMaxHeap(int arr[], int data){  // logn

    arr[n] = data;

    int i = n;

    while ( i > 0 ){

        if ( arr[i/2] < arr[i] ){

            int temp = arr[i/2];
            arr[i/2] = arr[i];
            arr[i] = temp;

        }

        i = i/2;

    }

    n += 1;

}

int main(){

    cin>>n;

    int arr[20]; 
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int data;
    cin>>data;

    InsertionMaxHeap(arr, data);

    for ( int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    

    return 0;
}