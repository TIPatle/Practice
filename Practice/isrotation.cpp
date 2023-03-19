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

bool isrota(string a, string b){

    int n = a.length();
    bool ans = 0;

    for ( int i = 0; i<n; i++ ){

        if ( a[i] == b[0] ){

            bool ans1 = 1;
            for ( int j = 0; j<n; j++ ){

                if ( a[(i+j)%n] != b[j] )
                    ans1 = 0;

            }

            ans |= ans1;

        }

    }
    
    return ans;

}

int main(){
    
    string a;
    string b;

    cin>>a>>b;

    cout<<isrota(a, b)<<endl;


    return 0;

}