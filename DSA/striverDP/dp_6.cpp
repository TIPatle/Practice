// Geek is going for n days training program, he can perform any one of these three activities 
// Running, Fighting, and Learning Practice. each activity has the same point on each day. 
// as Geek wants to improve all his skills, he can't do the same activity on two consecutive days, 
// help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding 
// to each day and activity.

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

int maximumPoints(vii&points, int n, int choice, vii&t){    // TC: O(n*k)    SC : O(n*k+n)
    if(n == 0) return 0;
    if(t[n][choice]!=-1) return t[n][choice];
    int ans = INT_MIN;
    rep(i,0,3){ 
        if(choice != i) ans = max(ans, maximumPoints(points, n-1, i, t)+points[n-1][i]);
    }
    return t[n][choice] = ans;      
}
int maximumPoints(vii&points, int n){       // TC: O(n*k)    SC : O(n*k)
    vii t(n+1, vi(4, -1));
    t[0][0] = 0; t[0][1] = 0; t[0][2] = 0; t[0][3] = 0;
    rep(i, 1, n+1){
        rep(choice, 0, 4){
            int ans = INT_MIN;
            rep(j, 0, 3){
                if(choice != j )
                    ans = max(ans, t[i-1][j]+points[i-1][j]);
            }
            t[i][choice] = ans;   
        }
    }
    return t[n][3];
}
int maximumPointS(vii& points, int n){      // TC: O(n*k) k = 4 SC: O(2*n)
    vii t(2, vi(4, 0));
    rep(i, 1, n+1){
        rep(choice, 0, 4){
            int ans = INT_MIN;
            rep(j, 0, 3){
                if(choice != j )
                    ans = max(ans, t[(i-1)%2][j]+points[i-1][j]);
            }
            t[i%2][choice] = ans;   
        }
    }
    return t[n%2][3];
}
void solve(){
    int n;
    cin>>n;
    vii points(n, vi(3));
    rep(i,0,n) 
        cin>>points[i][0]>>points[i][1]>>points[i][2];
    int ans = INT_MIN;
    vii t(n+1, vi(3, -1));
    cout<<maximumPointS(points, n)<<endl;
}   
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) 
        solve();
    return 0;

} 