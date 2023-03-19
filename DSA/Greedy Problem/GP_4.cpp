//Optimal Merge Problem

#include <iostream>
#include <queue>

using namespace std;

int main(){

    priority_queue <int, vector<int>, greater<int> > pq;

    int n;
    cin>>n;

    while (n--){

        int val;
        cin>>val;

        pq.push(val);

    }
    /*
    int ans = 0;

    int sum = pq.top();
    pq.pop();

    while (!pq.empty()){

        sum += pq.top();
        ans += sum;

        pq.pop();

    }

    cout<<ans<<endl;
    */  
    int ans = 0;

    while (pq.size() > 1 ){

        int e1 = pq.top();
        pq.pop();
        int e2 = pq.top();
        pq.pop();

        ans += e1 + e2;
        pq.push(e1 + e2);

    }

    cout<<ans<<endl;

    return 0;

}