#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> vec(n);

    for ( int i = 0; i<n; i++ )
        cin>>vec[i];

    int prefixSum = 0;
    map <int, int> m;

    for ( int i = 0; i<n; i++ ){

        prefixSum += vec[i];
        m[prefixSum]++;

    }

    int ans = 0;

    for ( auto it : m ){

        int c = it.second;
        ans += ( c*(c-1) ) /2;

        if ( it.first == 0)
            ans += it.second;

    }

    cout<<ans<<endl;

    return 0;

}