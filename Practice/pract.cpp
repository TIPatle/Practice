// Description :: This file find out the maximum profit we can make by 
//                selling and buying stock at most 2 times

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

int maxProfit( vi arr, int n, int k ){

    priority_queue<int, vector<int>, greater<int>> pq;

    int i = 1;
    
    while ( i < n && arr[i-1] >= arr[i] )
        i++;

    if ( i == n )
        return 0;

    int j = i;
    while( i < n ){

        if ( arr[i-1] <= arr[i] ){}
        
        else {

            pq.push(arr[i-1] - arr[j-1]);
            j = i+1;

            if ( pq.size() > k )
                pq.pop();

        }

        i++;

    }

    pq.push(arr[i-1] - arr[j-1]);
    if ( pq.size() > k )
        pq.pop();

    int profit = 0;
    while( !pq.empty()){

        profit += pq.top();
        pq.pop();

    }

    return profit;


}

int main(){

    int n;
    cin>>n;

    vi arr(n,0);

    rep(i, 0, n) cin>>arr[i];

    cout<<maxProfit(arr, n, 2)<<endl;

    return 0;

}