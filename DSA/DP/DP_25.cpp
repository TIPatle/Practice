// O--n knapsack Problem

#include <iostream>
#include <vector>

using namespace std;

int weight[int(1e5)];
int values[int(1e5)];

int main(){

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++)
        cin>>weight[i];

    for(int i = 0; i<n; i++ )
        cin>>values[i];

    int w;
    cin>>w;

    vector <int> dp(w+1, 0);

    for (int j = 0; j<=w; j++ ){

        for ( int i = 0; i< n; i++ ){

            if ( j - weight[i] >= 0)
                dp[j] = max(dp[j], dp[j-weight[i]] + values[i] ) ;

        }

    }

    cout<<dp[w]<<endl;

    return 0;

}