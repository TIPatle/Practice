#include <iostream>
#include <vector>

using namespace std;

void rotate( vector <int> &arr, int n, int d){

    for ( int i = 0; i<d; i++ ){

        int temp = arr[i];
        int j;

        for ( j = i; j<n - d; j += d)
            swap(arr[j], arr[j + d]);
        
        arr[j] = temp;
        
    }

}

int main(){

    int n, d;
    cin>>n>>d;

    vector <int> arr(n);
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    rotate( arr, n, d);

    for ( auto it : arr )
        cout<<it<<" ";

    return 0;

}