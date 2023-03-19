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

        int x, y;
        cin>>x>>y;

        if ( x && y && x == y )
            cout<<"Yes"<<endl;

        else 
            cout<<"NO"<<endl;

    }


    return 0;

}