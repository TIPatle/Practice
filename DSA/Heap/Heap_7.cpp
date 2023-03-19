#include <bits/stdc++.h>

using namespace std;

int n;

void DeleteMinHeapNode( int arr[] ){   //logn

    arr[1] = arr[n];
    n -= 1;

    int i = 1;

    while ( i < n){

        int left = 2*i;
        int right = 2*i + 1;
        int smallest = i;

        if ( left <= n && arr[left] < arr[smallest] )
            smallest = left;

        if ( right <= n && arr[right] < arr[smallest] )
            smallest = right;

        if ( smallest != i )
            swap(arr[smallest], arr[i]);

        else 
            break;

        i = smallest;

    }


}

int main(){

    cin>>n;

    int arr[20];

    for ( int i = 1; i<=n; i++ )
        cin>>arr[i];

    DeleteMinHeapNode(arr);

    for ( int i = 1 ; i<=n; i++ )
        cout<<arr[i]<<" ";

    return 0;

}