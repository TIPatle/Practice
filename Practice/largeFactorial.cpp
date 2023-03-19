#include <bits/stdc++.h>

#define vi vector<int>
#define vii vector<vector<int>>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>

#define rep(i, a, b) for(int i = a; i<b; i++)
#define decrep(i, a, b) for ( int i = a; i>=b; i--)

using namespace std;

vector<int> multiply( vector<int> &num, int n ){
        
    long long int carry = 0;
    for ( int i = 0; i<num.size(); i++ ){
        
        int mul = num[i]*n;
        num[i] = (mul + carry) % 10;
        carry = (carry + mul) / 10;
        
    }
    
    while ( carry > 0 ){
        
        num.push_back((carry % 10));
        carry = (carry/10);
        
    }
        
    return num;
    
}

vector<int> factorial(int N){
    
    vector<int> num;

    num.push_back(1);
    
    for ( int i = 2; i<=N; i++ ){
        
        multiply(num, i);
        
    }
    
    reverse(num.begin(), num.end());
    return num;
    
}

int main(){
   
    int n;
    cin>>n;

    vi fact = factorial(n);

    for ( auto it : fact )
        cout<<it;

    cout<<endl;

    return 0;

}