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
    
    int n;
    cin>>n;

    int arr[n];
    rep(i, 0, n)
        cin>>arr[i];

    int curr = 0;
    int maxi = arr[0];

    rep(i, 0, n){

        curr += arr[i];

        maxi = max(curr, maxi);

        if ( curr < 0)
            curr = 0;

    }

    cout<<maxi<<endl;

    return 0;

}