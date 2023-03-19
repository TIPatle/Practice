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
    int row;
    cin>>row;

    for(int i = 1; i<=row; i++){
        for(int j = 1; j<=row; j++){
            if( i == 1 || j == 1 || j == row || i == row || i == 2 || j == 2 || j == row-1 || i == row-1 )
                cout<<"* ";
            else
                cout<<"  ";
        }
        cout<<endl;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--) solve();


    return 0;

}