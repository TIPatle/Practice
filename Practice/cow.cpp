#include <iostream>

using namespace std;

int maxCow( int c[], int x , int n, int count = 0){

    if ( x == 0 )
        return 0;

    if ( n == 0 )
        return 0;

    if ( x >= count + 1 )
        return max(1 + maxCow(c, x-count-1, n-1, count + 1), maxCow(c, x - count, n-1, count));

    return maxCow(c, x - count, n-1, count);

}

int main(){

    int n, x;
    cin>>n>>x;

    int c[n];
    for ( int i = 0; i<n; i++ )
        cin>>c[i];

    cout<<maxCow( c, x , n)<<endl;

    return 0;

}