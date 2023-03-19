#include <iostream>
#include <queue>

#define rep(i, a, b) for ( int i = a; i<b; i++)

using namespace std;

int main(){

    int n, k;
    cin>>n>>k;

    priority_queue <int, vector<int>> pq;

    rep(i, 0, n){

        int val;
        cin>>val;

        pq.push(val);

    }

    int sum = 0;
    int count = 0;

    rep(i, 0, n){

        sum += pq.top();
        pq.pop();

        count ++;

        if( sum >= k )
            break;

    }

    if ( sum >= k)
        cout<<count<<endl;

    else 
        cout<<-1<<endl;

    return 0;

}