#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)
#define repit(it, s) for ( auto it : s)

using namespace std;

void solve(){
    int n, m;
    cin>>n>>m;
    int arr[n*m];
    for(int i = 0; i<n*m; i++ ){
        cin>>arr[i];
    }
    sort(arr, arr+(m*n));
    int k = n+m-1;
    int mini = INT_MAX;
    int i1 = 0;
    int i2 = 0;
    for(int i = 0; i<n*m-k; i++){
        if ( arr[i+k-1]-arr[i] < mini ){
            mini = arr[i+k-1]-arr[i];
            i1 = i;
            i2 = i+k-1;
        }
    }
    int l = i1;
    k = 0;
    for(int i = 0; i<n; i++ ){
        if ( k == i1 ){
            k = i2+1;
        }
        for(int j = 0; j<m; j++ ){
            if ( i == 0 || j == (m-1) ){
                cout<<arr[l]<<" ";
                l++;
            }
            else{
                cout<<arr[k]<<" ";
                k++;
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}