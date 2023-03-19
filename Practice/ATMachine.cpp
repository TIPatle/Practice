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

        int n, k;
        cin>>n>>k;

        int a[n];
        for ( int i = 0; i<n; i++ )
            cin>>a[i];

        for ( int i = 0; i<n; i++){

            if ( k - a[i] >= 0 ){
                cout<<1;
                k -= a[i];
            }

            else 
                cout<<0;

        }

        cout<<endl;

    }


    return 0;

}