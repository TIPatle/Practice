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



int main(){

    int n, k;
    cin>>n>>k;

    int arr[n];
    rep(i, 0, n) cin>>arr[i];

    // O(N) Time complexity O(N) space complexity

    // unordered_map<int, int> hash;

    // rep(i, 0, n) hash[arr[i]]++;

    // unordered_map <int, int> :: iterator it = hash.begin();
    // int probableOccurence = n / k;

    // for ( it; it != hash.end(); it++ ){

    //     if ( it->second >= probableOccurence ){

    //         cout<<it->first<<" ";

    //     }

    // }

    // cout<<endl;

    // Time O(N) Space O(1)

    

    return 0;

}