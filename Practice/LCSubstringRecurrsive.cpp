#include <iostream>

using namespace std;

int lcs( string a, string b, int n, int m ){

    if ( n == 0 || m == 0 )
        return 0;

    if ( a[n-1] == b[m-1] )
        return 1 + lcs(a, b, n-1, m-1);

    else 
        return 0;

}

int main(){

    string a, b;
    cin>>a>>b;

    cout<<lcs(a, b, a.length(), b.length() )<<endl;

    return 0;

}