#include <iostream>

using namespace std;

string buildLowestNumber(string num, int k)
{
    
    string ans = "";
    int n = num.length();
    
    int p = 1;
    int prev;

    int to_choose = n - k;
    
    while( k > 0 && to_choose > 0 ){
        
        prev = p-1;
        for ( int i = p; i<p+k; i++ ){
            
            if ( num[i] < num[prev] ) 
                prev = i;
            
        }
        
        ans.push_back(num[prev]);
        k-= (prev-p+1);
        p = prev+2;
        to_choose--;
    
    }
    
    for ( int i = prev+1; i<n; i++ )
        ans.push_back(num[i]);
        
        
    return ans;
    
}

int main(){

    string s;
    cin>>s;

    int k;
    cin>>k;

    cout<<buildLowestNumber(s, k)<<endl;

    return 0;

}