#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    int t;
    cin>>t;

    while( t-- ){

        int n;
        cin>>n;

        vector <pair<int, int>> v(n);
        for ( int i = 0; i<n; i++ )
            cin>>v[i].first>>v[i].second;

        int l, p;
        cin>>l>>p;

        for ( int i = 0; i<n; i++ )
            v[i].first = l - v[i].first;

        sort(v.begin(), v.end());

        priority_queue <int> maxHeap;

        int stopCount = 0;
        int distance = l;
        int fuel = p;
        bool flag = 0;
        
        auto it = v.begin();

        for ( int i = 0; i<n; i++ ){

            if ( fuel >= distance )
                break;
            
            while ( fuel < v[i].first ){

                if ( maxHeap.empty() ){

                    flag = 1;
                    break;

                }

                stopCount ++;
                fuel += maxHeap.top();
                maxHeap.pop();

            }

            if ( flag )
                break;

            maxHeap.push(v[i].second);

        }

        if ( flag ){

            cout<<"-1"<<endl;
            continue;

        }

        while (maxHeap.empty() && fuel < l ){

            fuel += maxHeap.top();
            maxHeap.pop();
            stopCount++;

        }

        if ( fuel < distance )
            cout<<-1<<endl;

        else 
            cout<<stopCount<<endl;

    }    

    return 0;

}