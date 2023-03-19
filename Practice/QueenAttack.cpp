#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;



int main(){
    int t;
    cin>>t;

    while(t--){

        int n, x, y;
        cin>>n>>x>>y;

        int i = x;
        int j = y;

        if ( n <= 1){

            cout<<0<<endl;
            continue;

        }

        if ( n == 2){

            cout<<n+1<<endl;
            continue;

        }

        int a = 3*(n-1);
        int p1 = min(i, j);
        int p2 = n - max(i, j) + 1;
        
        int b = 2 * (min( p1, p2 ) - 1);

        cout<<a+b<<endl;

    }


    return 0;

}