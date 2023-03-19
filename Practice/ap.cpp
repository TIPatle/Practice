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
    
    int n;
    cin>>n;

    if ( n <= 0 )
        cout<<0<<endl;

    else {

        int answer = 2 + (n-1)*3 + (n-1)*(n-2);
        cout<<answer<<endl;

    }


    return 0;

}