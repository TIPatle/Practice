/*

Description :- 

Find out the maximum sub-array of non negative numbers from an array.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
a = [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

Input:
n = 3
a[] = {1, 2, 3}
Output: 1 2 3
Explanation: In the given array every
element is non-negative.

Input:
n = 2
a[] = {-1, 2}
Output: 2
Explanation: The only subarray [2] is
the answer.

Intiution :- Variation of Kadane's Algorithm.
             Can also be solved through prefix sum.
             Can also be solved through seeing negative number as breaking point.

*/

#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)
#define repit(it, s) for ( auto it : s)

using namespace std;

vector<int> findSubarray(int a[], int n) {
	    
	int maxisum = a[0];
    int l = 0;
    int r = 0;

    int sum = 0;
    int li = 0;

    rep(i, 0, n){

        sum += a[i];

        if ( sum < 0 || a[i] < 0 ){

            sum = 0;
            li = i+1;

        }

        if ( sum > maxisum ){

            maxisum = sum;
            l = li;
            r = i;

        }

        else if ( sum == maxisum && r-l < i-li ){

            l = li;
            r = i;

        }

    }

    if ( r < l )
        return{-1};
        
    vi ans;
    rep(i, l, r+1)
        ans.push_back(a[i]);
    
    return ans;
	    
}

int main(){


    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int a[n];
        rep(i, 0, n){

            cin>>a[i];

        } 

        vi ans = findSubarray(a, n);   
        
        repit(it, ans)
            cout<<it<<" ";

        cout<<endl;   

    }


    return 0;

}