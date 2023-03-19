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

        int a, b, a1, b1, a2, b2;
        cin>>a>>b>>a1>>b1>>a2>>b2;

        bool k1 = 0;
        bool k2 = 0;

        if ( a1 == a ){

            if ( b1 == b )
                k1 = 1;

        }

        else if ( a1 == b ){

            if ( b1 == a )
                k1 = 1;


        }

        else if ( a2 == a ){

            if ( b2 == b )
                k2 = 1;

        }

        else if ( a2 == b ){

            if ( b2 == a )
                k2 = 1;


        }

        if( k1 & k2  || !(k1 || k2))
            cout<<0<<endl;

        else if (k1)
            cout<<1<<endl;

        else if (k2)
            cout<<2<<endl;

    }


    return 0;

}