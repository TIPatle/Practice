#include <bits/stdc++.h>

#define N 1e7
#define M 1e5

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

bool isMatch(string s, string p) {
        
    int n = s.length();
    int m = p.length();
    
    int j = 0;
    int i ;
    bool ans = true;
    
    for ( i = 0; i<n && j<m; i++ ){
        
        if ( p[j] == '.' ){
            
            j++;
            continue;
            
        }
        
        else if ( p[j] == '*' ){
            
            if ( j == m-1){
                i = n;
                break;
            }
            
            j = j+1;
            
            if ( p[j] == '*' )
                continue;
            
            while ( s[i] != p[j]){
                
                i++;
                
                if ( i >= n ){
                    
                    ans = false;
                    break;
                    
                }
                
            }
            
            j++;
            
        }
        
        else {
            
            if ( s[i] != p[j] )
                ans = false;
            
            j++;
            
        }
        
    }
    
    
    if ( i < n)
        return false;
    
    return ans;
    
    
}

int main(){
    
    string s;
    string p;

    cin>>s>>p;

    if ( isMatch(s, p))
        cout<<s<<endl;

    else
        cout<<"Invalid Pattern"<<endl;

    return 0;

}