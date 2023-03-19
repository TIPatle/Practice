#include <iostream>
#include <vector>

using namespace std;

int maxWeight(vector <pair<int, int>> v, int k, int i, int n ){

    if ( i >= n || k == 0 )
        return 0;

    if ( k-v[i].first < 0 )
        return maxWeight(v, k, i+1, n);
    
    int choice1 = maxWeight(v, k-v[i].first, i+1, n ) + v[i].second;
    int choice2 = maxWeight(v, k, i+1, n);

    return max(choice1, choice2);

}

int main(){

    int n;
    cin>>n;

    vector <pair<int, int>> v(n+1);
    for (int i = 0; i<n; i++ )
        cin>>v[i].first>>v[i].second;

    int k;
    cin>>k;

    cout<<maxWeight(v, k, 0, n)<<endl;

    return 0;

}