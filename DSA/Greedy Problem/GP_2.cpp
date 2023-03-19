// activity selection Problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxActivitySelection(vector <pair<int, int>> v){

    int s = 0;
    auto it = v.begin();
    int activityCount = 0;

    for ( auto it = v.begin(); it != v.end(); it++){

        if ( it->first >= s ){

            s = it->second;
            activityCount++;

        }


    }

    return activityCount;
    
}

bool comparator (pair<int, int> first, pair<int, int> second){

    if ( first.second < second.second)
        return 1;

    return 0;

}

int main(){

    int n;
    cin>>n;

    vector <pair<int, int>> v(n);

    for ( int i = 0 ; i<n; i++ )
        cin>>v[i].first>>v[i].second;

    sort(v.begin(), v.end(), comparator);

    cout<<maxActivitySelection(v);

    return 0;

}