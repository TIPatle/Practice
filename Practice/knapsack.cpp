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

int knaprecc(int wt[], int val[], int w, int n ){

    if ( n == 0 || w == 0 )
        return 0;

    if ( wt[n-1] <= w ){

        return max(knaprecc(wt, val, w-wt[n-1], n-1) + wt[n-1], knaprecc(wt, val, w, n-1));

    }

    return knaprecc(wt, val, w, n-1);

}

vii t;
int knapmemozization(int wt[], int val[], int w, int n ){


    if ( n == 0 || w == 0 )
        return 0;

    if ( t[n][w] != -1 )
        return t[n][w];

    if ( wt[n-1] <= w ){

        return t[n][w] = max(knapmemozization(wt, val, w-wt[n-1], n-1) + wt[n-1], knapmemozization(wt, val, w, n-1));

    }

    return t[n][w] = knapmemozization(wt, val, w, n-1);

}

int knapTop( int wt[], int val[], int w, int n ){

    t = vii(n+1, vi(w+1, 0));

    for ( int i = 0; i<=n; i++)
        t[i][0] = 0;

    for ( int i = 0; i<=w; i++ )
        t[0][i] = 0;

    for ( int i = 1; i<=n; i++){

        for ( int j = 1; j<=w; j++){

            if ( wt[i-1] <= j )
                t[i][j] = max(t[i-1][(j-wt[i-1])] + wt[i-1], t[i-1][j] );

            else 
                t[i][j] = t[i-1][j];

        }

    }

    return t[n][w];

}

int main(){
    
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 7;

    t = vii(4+1, vi(w+1, -1));
    cout<< knapTop(wt, val, w, 4) <<endl;

    return 0;

}