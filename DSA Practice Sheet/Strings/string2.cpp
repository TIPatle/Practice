/*

Description : Roman Number to Integer

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

int romanToDecimal(string &str) {
    
    int n = str.length();
    char prev = ' ';
    
    unordered_map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    
    int ans = 0;
    decrep(i, n-1, 0){
        
        if ( prev == ' ' ){
            
            ans += roman[str[i]];
            
        }
        
        else if ( prev != ' ' && roman[str[i]] < roman[prev]){
            
            ans -= roman[str[i]];
            
        }
        
        else {
            
            ans += roman[str[i]];
            
        }
        
        prev = str[i];
        
    }
    
    return ans;
    
}

int main(){
    
    int t;
    cin>>t;

    while(t--){

        string s;
        cin>>s;
        
        cout<<romanToDecimal(s)<<endl;
        

    }


    return 0;

}