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
bool check(int x, int y, int z, int n){
    if(n%(x*y))
        return false;
    if(n%(y*z))
        return false;
    if(n%(x*z))
        return false;
    if((x*y*z)%n)
        return false;
    if(x==y)
        return false;
    if(x==z)    
        return false;
    if(y==z)
        return false;
    return true;
}

void solve(){
    // Time complexity O(sqrt(sqrt(N)))
    int n;
    cin>>n;
    int x, y, z;
    bool found = false;
    for(int i = 1; i*i<=n; i++){
        if((n%i)==0){
            x = i;
            for(int j = 1; j*j<=(n/i); j++){
                if(((n/i)%j)==0){
                    y = j;
                    z = (n/i)/j;
                    if(check(x,y,z,n)){
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    if(found){
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
    else{
        cout<<-1<<endl;
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