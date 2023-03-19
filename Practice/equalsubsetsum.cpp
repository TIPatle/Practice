#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

int subsetsum( int arr[], int sum1, int sum2, int n ){

    if ( sum1 == sum2 && sum1 != 0 )
        return true;

    if ( n == 0 )
        return false;

    if ( sum1 < sum2 ){
        return subsetsum(arr, sum1 + arr[n-1], sum2, n-1) || subsetsum(arr, sum1, sum2,n-1);
    }
    else 
        return subsetsum(arr, sum1, sum2 + arr[n-1], n-1) || subsetsum(arr, sum1, sum2, n-1);

}

vii t;

int subsetmemo( int arr[], int sum1, int sum2, int n ){

    if ( sum1 == sum2 && sum1 != 0 )
        return true;

    if ( n == 0 )
        return false;
    
    if ( t[n][sum1] != -1 )
        return t[n][sum1];

    if ( sum1 < sum2 ){
        return t[n][sum1] = subsetsum(arr, sum1 + arr[n-1], sum2, n-1) || subsetsum(arr, sum1, sum2,n-1);
    }
    else 
        return t[n][sum1] = subsetsum(arr, sum1, sum2 + arr[n-1], n-1) || subsetsum(arr, sum1, sum2, n-1);

}

int main(){

    int arr[] = {1, 15, 11, 5};
    int sum = 0;

    for (auto it : arr)
        sum += it;

    t = vii(4+1, vi(sum+1, -1));        

    cout<<subsetmemo(arr, 0, 0, 4)<<endl;

    return 0;

}