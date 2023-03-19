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

        int t1, t2, r1, r2;
        cin>>t1>>t2>>r1>>r2;

        double x = pow(t1, 2) / pow(r1, 3);
        double y = pow(t2, 2) / pow(r2, 3);

        if ( x == y )
            cout<<"Yes"<<endl;

        else    
            cout<<"No"<<endl;

    }


    return 0;

}