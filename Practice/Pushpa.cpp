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

        int n;
        cin>>n;

        map <int, int> m;

        for ( int i = 0; i<n; i++ ){

            int val; 
            cin>>val;

            m[val]++;

        }

        int maxi = -1e7;
        for ( auto it : m )
            maxi = max(it.first + ( it.second - 1 ), maxi);

        cout<<maxi<<endl;

    }


    return 0;

}