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

int solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = INT_MAX;
    int ones = 0;
    int zero = 0;
    for(int i = 0; i<k; i++){
        if ( s[i] == '0')
            zero++;
        else
            ones++;
    }
    if(ones == k)
        return 0;
    else if ( zero == k )
        ans = 1;
    int j = 0;
    for(int i = k; i<n; i++){
        if(s[i]=='0')
            zero++;
        else
            ones++;
        if(s[j]=='0')
            zero--;
        else
            ones--;
        if(ones == k)
            return 0;
        else if ( zero == k )
            ans = 1;
        j++;
    }

    if ( ans == 1)
        return ans;

    zero = 0;
    if ( s[0] == '0' )
        zero++;
    for(int i = 1; i<k; i++){
        if ( s[i-1] != s[i] && s[i] == '0' )
            zero++;
    }
    ans = zero*2;
    if ( s[0] == '0' )
        ans -= 1;
    j = 0;
    for(int i = k; i<n; i++ ){
        if ( s[i-1] != s[i] && s[i] == '0' )
            zero++;
        if ( s[j] != s[j+1] && s[j] == '0' )
            zero--;
        int a = zero*2;
        if ( s[j+1] == '0' )
            a -= 1;
        ans = min(a, ans);
        j++;
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        cout<<solve()<<endl;
    }

    return 0;

}