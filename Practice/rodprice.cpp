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

int rodce( int price[], int lengthh,  int n ){

    if ( lengthh == 0 || n == 0 )
        return 0;

    if ( lengthh >= n )
        return max(rodce( price, lengthh - n, n ) + price[n-1], rodce( price , lengthh, n-1));

    return rodce( price , lengthh, n-1);

}

vii t;

int rodmemo( int price[], int lengthh,  int n ){

    if ( lengthh == 0 || n == 0 )
        return 0;

    if ( t[lengthh][n] != -1 )
        return t[lengthh][n];

    if ( lengthh >= n )
        return t[lengthh][n] = max(rodce( price, lengthh - n, n ) + price[n-1], rodce( price , lengthh, n-1));

    return t[lengthh][n] = rodce( price , lengthh, n-1);

}

int rodtop( int price[], int length, int n ){

    for ( int i = 0; i<=n; i++ )
        t[0][i] =  0;

    for ( int i = 0; i<=length; i++)
        t[i][0] = 0;

    for ( int i = 1; i<=n; i++ ){

        for ( int j = 1; j<=length; j++ ){

            if ( j >= i )
                t[j][i] = max(t[j-i][i] + price[i-1], t[j][i-1]);

            else 
                t[j][i] = t[j][i-1];

        }

    }

    return t[length][n];

}

int main(){
    
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int lengthh = 8;
    int n = 8;

    t = vii(lengthh+1, vi(n+1, -1));
    cout<<rodtop(price, lengthh, n );

    return 0;

}