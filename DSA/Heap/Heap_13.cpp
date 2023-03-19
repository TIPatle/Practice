// Merge k sorted arrays using heaps

#include <bits/stdc++.h>

using namespace std;

int main(){

    int k;
    cin>>k;

    vector <vector<int>> vec(k);

    for ( int i = 0; i<k; i++ ){
        
        int n;
        cin>>n;

        for ( int j = 0; j<n; j++ ){

            int val;
            cin>>val;

            vec[i].push_back(val);

        }


    }

    vector <int> idx(k, 0);

    priority_queue < pair<int,int> , vector <pair<int, int>>, greater<pair<int, int>> > pq;

    for ( int i = 0; i<k; i++)
        pq.push( { vec[i][0], i });
 
    vector <int> ans;

    while ( !pq.empty() ){

        pair<int, int> x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if ( idx[x.second] + 1 < vec[x.second].size() )
            pq.push({vec[x.second][idx[x.second] + 1], x.second});

        idx[x.second] += 1;

    }

    for ( auto it : ans )
        cout << it <<" ";

}