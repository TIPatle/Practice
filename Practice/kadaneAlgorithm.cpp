#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

#define t  cin>> t while(t--)

using namespace std;



int main(){

    
    int n;
    cin>>n;

    vi arr(n);
    rep(i, 0, n)
        cin>>arr[i];

    vi prefixSum (n);
    int sum = 0;
    rep(i, 0, n){

        sum += arr[i];
        prefixSum[i] = sum;

    }

    int mini = INT_MAX;

    int ans = INT_MIN;

    rep(i, 0, n){

        ans = max(prefixSum[i] - mini, max(ans, prefixSum[i]));
        mini = min(prefixSum[i], mini);

    }

    cout<<ans<<endl;

    return 0;

}