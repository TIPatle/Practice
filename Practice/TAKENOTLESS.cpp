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
    int n;
    cin>>n;
    unordered_map<int, int> m;
    int maxi=1;
    int num;
    rep(i, 0, n){
        cin>>num;
        maxi=max(maxi, num);
        m[num]++;
    }
    if(m[maxi]%2){
        cout<<"Marichka"<<endl;
    }else{
        cout<<"Zenyk"<<endl;
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