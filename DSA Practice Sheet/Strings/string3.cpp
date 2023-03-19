/*

Description : Longest Common Prefix

Input: strs = ["flower","flow","flight"]
Output: "fl"

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

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

string longestCommonPrefix(vector<string>& strs) {
    
    string ans = strs[0];
    int n = strs.size();

    rep(i, 1, n){

        int l = ans.length();
        int m = strs[i].length();

        int j = 0;

        string a = "";
        while(  j < l && j < m  ){

            if ( strs[i][j] != ans[j] )
                break;

            a += ans[j];

            j++;

        }

        ans = a;

    }

    return ans;

}

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<string> v;
        rep(i, 0, n){

            string s;
            cin>>s;

            v.push_back(s);

        }

        cout<<longestCommonPrefix(v)<<endl;


    }


    return 0;

}