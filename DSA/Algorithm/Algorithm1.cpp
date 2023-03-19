// Description :- Grade school algorithm to calculate the multiplication of two number

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> multiply(long long int x, long long int y ){

    if ( x == 0 || y == 0 )
        return {0};
    
    long long int i = x;

    vector<int> ans;
    int len = 0;
    int zeros = 0;

    while( i ){
        int k = zeros;

        long long int j = y;
        int carry = 0;

        while( j ){

            int num = ((i%10) * (j %10)) + carry;
            // cout<<num<<"            num"<<endl;

            if ( k < len ){
                
                ans[k] += num%10;
                carry = (ans[k]/10 + num/10);
                ans[k] %= 10;

            }

            else{ 
                
                ans.push_back(num%10);
                carry = num/10;

            }

            k++;
            j = j/10;

        } 

        // cout<<carry<< "        "<<"carry"<<endl;

        while(carry){

            if ( k < len ){

                ans[k] += carry%10;
                carry = (ans[k]/10 + carry/10);
                ans[k] %= 10;

            }

            else{ 

                ans.push_back(carry%10);
                carry /= 10;

            }

            k++;

        }

        int l = ans.size();
        len = max(len, l);
        i = i/10;
        zeros++;

    }

    reverse(ans.begin(), ans.end());
    return ans;

}

vector<int> multiply(string x, string y ){

    int n = x.length();
    int m = y.length();

    if ( (n == 1 && x[0] == '0') || (m == 1 && y[0] == '0' ))
        return {0};
    
    long long int i;

    vector<int> ans;
    int len = 0;
    int zeros = 0;

    while( (n-1-zeros) >= 0 ){

        int k = zeros;
        i = x[n-1-zeros] - '0';

        long long int j;
        int carry = 0;
        int p = 0;

        while( (m-1-p) >= 0 ){
            
            j = y[m-1-p]-'0';

            int num = ( i * j ) + carry;
            // cout<<num<<"            num"<<endl;

            if ( k < len ){
                
                ans[k] += num%10;
                carry = (ans[k]/10 + num/10);
                ans[k] %= 10;

            }

            else{ 
                
                ans.push_back(num%10);
                carry = num/10;

            }

            k++;
            p++;

        } 

        // cout<<carry<< "        "<<"carry"<<endl;

        while(carry){

            if ( k < len ){

                ans[k] += carry%10;
                carry = (ans[k]/10 + carry/10);
                ans[k] %= 10;

            }

            else{ 

                ans.push_back(carry%10);
                carry /= 10;

            }

            k++;

        }

        int l = ans.size();
        len = max(len, l);
        zeros++;

    }

    reverse(ans.begin(), ans.end());
    return ans;

}

int main(){

    string x, y;
    cout<<"Enter two number which you want to multipy : ";
    cin>>x>>y;

    cout<<"First Inputed Number : "<<x<<endl;
    cout<<"Second Inputed Number : "<<y<<endl;

    vector<int> ans = multiply(x, y);

    for ( auto &it : ans )
        cout<<it;

    cout<<endl;

}