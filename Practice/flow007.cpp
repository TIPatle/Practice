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

int rev ( int n ){

    int newnum = 0;

    while ( n ){

        newnum *= 10;
        newnum += n%10;

        n /= 10;

    }

    return newnum;

}

int main(){
    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        cout<<rev(n)<<endl;

    }


    return 0;

}