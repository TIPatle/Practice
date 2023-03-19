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

    rep( i, 0, n)
        cin>>arr[i];

    int mini = INT_MAX, maxi = INT_MIN;

    rep(i, 0, n){

        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);

    }

    cout<<mini<<" "<<maxi<<endl;

    return 0;

}