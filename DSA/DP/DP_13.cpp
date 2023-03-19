#include <iostream>
#include <vector>

using namespace std;

int LCS( string s1, string s2, int n, int m ){   // Regular recurrsion O(2^N)

    if ( s1.empty() || s2.empty() )
        return 0;

    if ( n <= 0 ||  m <= 0)
        return 0;

    if ( s1[n-1] != s2[m-1] )
        return max ( LCS(s1, s2, n, m-1), LCS(s1, s2, n-1, m));
    
    return LCS(s1, s2, n-1, m-1) + 1;

}

int main(){

    string s1, s2;
    cin>>s1>>s2;

    cout<<LCS(s1, s2, s1.size(), s2.size());

    return 0;

}