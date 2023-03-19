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

        int n, x;
        cin>>n>>x;

        int enemy[n];
        for ( int i = 0; i<n; i++)
            cin>>enemy[i];

        int multimode = *max_element(enemy, enemy+n);
        int singmode = 0;

        for ( int i = 0; i<n; i++ )
            singmode += ceil((double(enemy[i]) / double(x)));

        cout<<min(singmode, multimode)<<endl;

    }


    return 0;

}