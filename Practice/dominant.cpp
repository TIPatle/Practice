#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;



int main(){
    int t;
    cin>>t;

    while(t--){

        int a, b, c;
        cin>>a>>b>>c;

        if ( a > b+c || b > a + c ||  c > a + b )
            cout<<"Yes"<<endl;

        else 
            cout<<"No"<<endl;

    }


    return 0;

}