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

int copySetBit( int a, int b, int l, int r){

    if ( r < l )
        return -1;

    int mask = 0;
    int i = l;

    while( i <= r ){

        if ( b & 1<<(i-1)){

            mask = mask | 1<<(i-1);

        }

        i++;

    }

    return a | mask;

}

int copyBit( int a, int b, int l, int r ){

    if ( l < 0 || r >= 32 )
        return -1;

    int mask = ((1<<r)-1) & b;
    mask = mask>>(l-1)<<(l-1);

    return a | mask;
    
}

int main(){

    int t;
    cin>>t;

    while(t--){

        int a, b, l, r;
        cin>>a>>b>>l>>r;

        cout<<copyBit(a, b, l, r)<<endl;

    }


    return 0;

}