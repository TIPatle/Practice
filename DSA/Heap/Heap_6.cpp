#include <bits/stdc++.h>

using namespace std;

int n;

void insertMinHeap(int arr[], int data){   //logn

    n += 1;
    arr[n] = data;

    int i = n;

    while ( i > 0 && i/2 > 0){

        if ( arr[i] < arr[i/2] )
            swap(arr[i], arr[i/2]);
        
        i = i/2;

    }

}

int main(){

    cin>>n;

    int arr[20];

    for ( int i = 1; i<=n && n < 20 ; i++  )
        cin>>arr[i];

    int data;
    cin>>data;

    insertMinHeap(arr, data);

    for ( int i = 1; i<=n; i++)
        cout<<arr[i]<<" ";

    return 0;

}