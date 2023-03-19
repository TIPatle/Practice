/*

Description :- Split the binary string into substrings with equal number of 0s and 1s

Input: str = “0100110101” 
Output: 4 
The required substrings are “01”, “0011”, “01” and “01”.

Input: str = “0111100010” 
Output: 3 

Input: str = “0000000000” 
Output: -1

*/

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

int splitBinary( string s ){

    int split = 0;

    int zero = 0;
    int one = 0;

    repit(it, s){

        if ( it == '0' )
            zero++;

        if ( it == '1' )
            one++;

        if ( one > zero )
            return -1;

        if ( one == zero ){

            one = 0;
            zero = 0;
            split++;

        }

    }

    if ( split == 0 || one != 0 || zero != 0 )
        return -1;

    return split;

}

int main(){
    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;

        cout<<splitBinary(s)<<endl;        

    }


    return 0;

}