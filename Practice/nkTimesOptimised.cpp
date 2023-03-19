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

// optimised approached as unordered list takes O(n) time complexity and O(n) space 

int main(){
    
    int n, k;
    cin>>n>>k;

    unordered_map <int, int> m;

    int num;
    rep(i, 0, n){

        cin>>num;
        m[num]++;

    }

    int limit = n / k;

    for ( auto it : m ){

        if ( it.second > limit )
            cout<<it.first<<" ";

    }

    cout<<endl;

    return 0;

}