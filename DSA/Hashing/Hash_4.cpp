// Minimun sum of k consecutive array

#include <iostream>
#include<climits>
using namespace std;

int minSumKsubarrayElement(int arr[], int k, int n){  // O(n)

    int sum = 0; 
    int ans = 0;

    for ( int i = 0; i<k; i++ )
        sum += arr[i];

    ans = sum;

    for ( int i = k; i<n; i++){

        sum -= arr[ i - k ];
        sum += arr[i];

        ans = min(sum, ans);

    }

    return ans;

}

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];
    
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    cout<<minSumKsubarrayElement(arr, k, n)<<endl;

    return 0;
}