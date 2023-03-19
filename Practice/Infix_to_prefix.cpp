#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int precidence ( char op ){

    switch(op){

        case '+':
            return 1;

        case '-':
            return 1;

        case '*':
            return 2;

        case '/':
            return 2;


    }

}


string to_prefix ( string exp ){

    stack <char> st;
    string ans = "";

    reverse(exp.begin(), exp.end());

    for ( auto it : exp ){

        if ( it >= 'a' && it <= 'z' || it >= 'A'&& it <= 'Z' )
            ans+=it;

        else if ( it == ')' )
            st.push('(');

        else if ( it == '(' ){

            while ( st.top() != '(' ){

                ans+=st.top();
                st.pop();

            }

            st.pop();

        }

        else if ( it == '+' || it == '-' || it == '*' || it == '/' ){

            if ( st.empty() || st.top() == '(' )
                st.push(it);

            else {

                int op1 = precidence(st.top());
                int op2 = precidence(it);

                if ( op2 > op1 )
                    st.push(it);

                else {

                    while ( st.top() != '(' && !st.empty() ){

                        ans+=st.top();
                        st.pop();

                    }

                    st.push(it);

                }

            }


        }
 

    }

    while (!st.empty()){
        
        ans+=st.top();
        st.pop();

    }

    reverse (ans.begin(), ans.end());

    return ans;

}


int main(){

    string exp = "(A+B*C)";

    cout<<to_prefix(exp);
    
    return 0;

}

