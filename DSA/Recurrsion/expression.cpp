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

long long calculate(string &a ){
    stack<char> operatorr;
    stack<long long> number;
    int n = a.length();
    for( int i = 0; i<n; i++ ){
        if(a[i] != '+' && a[i] != '-' && a[i] != '*'){
            int j = i;
            long long num = 0;
            while(j<n && a[j] != '+' && a[j] != '-' && a[j] != '*'){
                num *= 10;
                num += a[j]-'0';
                j++;
            }
            number.push(num);
            i = j-1;
        }

        else{
            if ( operatorr.empty() ){
                operatorr.push(a[i]);
            }
            else{
                if ( operatorr.top() == '*' && a[i] != '*'){
                    while(!operatorr.empty() && operatorr.top() == '*'){
                        int num1 = number.top();
                        number.pop();
                        int num2 = number.top();
                        number.pop();
                        number.push(num1*num2);
                        operatorr.pop();
                    }
                }
                operatorr.push(a[i]);
            }
        }

    }

    while(!operatorr.empty()){
        if ( operatorr.top() == '*'){
            int num1 = number.top();
            number.pop();
            int num2 = number.top();
            number.pop();
            number.push(num1*num2);
            operatorr.pop();
        }
        else if ( operatorr.top() == '+'){
            int num1 = number.top();
            number.pop();
            int num2 = number.top();
            number.pop();
            number.push(num1+num2);
            operatorr.pop();
        }
        else{
            int num1 = number.top();
            number.pop();
            int num2 = number.top();
            number.pop();
            number.push(num2-num1);
            operatorr.pop();
        }
    }
    return number.top();
}   

void solve(vector<string>& ans, string& a, string& num, int i, int target){
    if ( i == num.length()){
        long long mask = calculate(a);
        if ( mask == target)
            ans.push_back(a);
        return;
    }
    
    a.push_back('+');
    a.push_back(num[i]);
    solve(ans, a, num, i+1, target);
    a.pop_back();
    a.pop_back();

    a.push_back('-');
    a.push_back(num[i]);
    solve(ans, a, num, i+1,target);
    a.pop_back();
    a.pop_back();

    a.push_back('*');
    a.push_back(num[i]);
    solve(ans, a, num, i+1, target);
    a.pop_back();
    a.pop_back();

    a.push_back(num[i]);
    solve(ans, a, num, i+1, target);
    a.pop_back();

}

vector<string> sole(){
    string num;
    cin>>num;
    int target;
    cin>>target;
    vector<string> ans;
    string a;
    a.push_back(num[0]);
    solve(ans, a, num, 1, target);
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        vector<string> ans = sole();
        for(auto it : ans){
            for(auto i : it ){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        if(ans.empty())
            cout<<"No Solution"<<endl;
        cout<<endl;
    }


    return 0;

}