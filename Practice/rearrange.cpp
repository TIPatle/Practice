#include <iostream>

using namespace std;

void rotateRight( int *arr, int i, int j){   // O(n)

    int nxt = arr[j];
    for ( int k = i; k <= j;  k++ ){
        
        swap(arr[k], nxt);        

    }

}

int findPositive ( int* arr, int i, int n ){

    for ( int j = i; j<n; j++ ){

        if ( arr[j] >= 0)
            return j;

    }

    return i;

}

int findNegative ( int* arr, int i, int n ){

    for ( int j = i; j<n; j++ ){

        if ( arr[j] < 0)
            return j;

    }

    return i;

}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];
    
    for ( int i = 0; i<n; i++ ){  // O(n*n)

        if ( arr[i] < 0 && i % 2 != 0 ){

            int j = findPositive(arr, i, n);
            rotateRight(arr, i, j);

        }

        else if ( arr[i] > 0 && i %2 == 0){

            int j = findNegative(arr, i, n);
            rotateRight(arr, i, j);

        }

    }


    for ( int i = 0; i<n; i++)
        cout<<arr[i]<<" ";
    

    return 0;

}