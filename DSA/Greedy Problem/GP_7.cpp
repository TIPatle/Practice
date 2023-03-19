#include <iostream>
#include <queue>

// work best if array is not sorted in descending order 
// some changes needed like add a new variable such as change variable  
// knapsack approach                                                  

using namespace std;

int main(){

    int n;
    cin>>n;

    vector <int> arr(n);
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    int step = 0;
    int count = 0;
    int index = 0;
    priority_queue <pair<int, int>> q;
    q.push({arr[0], 0});

    while (!q.empty() && step < n ){

        int k = q.top().first;
        int index = q.top().second;
        q.pop();

        cout<<k<<"-->";

        for ( int i = index+1; i<= index + k; i++)
            q.push({arr[i], i});

        step = index + k;
        count++;

    }

    cout<<arr[n-1]<<endl<<count<<endl;

    return 0;

}
