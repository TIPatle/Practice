//TOP K MOST FREQUENT ELEMENTS
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    map <int, int> m;

    for ( int i = 0; i<n; i++ ){

        if ( m[arr[i]] == 0 && m.size() == k )
            break;
        
        m[arr[i]]++;

    }

    vector <pair<int, int>> ans;

    for ( auto it  : m )
        ans.push_back({it.second, it.first});

    sort(ans.begin(), ans.end(), greater< pair<int,int> >() );

    for ( auto It : m )
        cout<<It.second<<" "<<It.first<<endl;

    return 0;
}