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

bool solve(){
    int n;
    cin>>n;
    int type[101];
    memset(type, 0, sizeof(type));
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        type[a]++;
    }
    for(int i = 0; i<=100; i++){
        if ( type[i]%2)
            return false;
    }
    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){ 
        if(solve())
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }


    return 0;

}