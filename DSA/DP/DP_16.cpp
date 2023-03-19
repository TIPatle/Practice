// Matrix chain multiplicaion - minimum no of operation to compute the multiplication of matrix

#include <iostream>
#include <vector>

using namespace std;

vector <int> arr(1e5);

int minOperation ( int i ,int j ){

    if ( i == j )
        return 0;

    int ans = 1e5;
    for ( int k = i; k < j; k++ )
        ans = min(minOperation(i, k) + minOperation(k+1, j) + arr[i-1]*arr[k]*arr[j], ans);

    return ans;

}

int main(){

    int n;
    cin>>n;

    
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<minOperation( 1, n-1)<<endl;

    return 0;

}