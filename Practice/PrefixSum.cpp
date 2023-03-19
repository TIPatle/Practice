#include <iostream>
#include <stack>

using namespace std;

int Prefixcalculate( string s ){

    stack <int> st;
    
    for ( int i = s.length() -1 ; i >= 0; i-- ){


        if ( s[i] >= '0' && s[i] <= '9' )
            st.push(s[i] - '0');

        else if ( s[i] == '+' ){

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            st.push(op1 + op2);

        }

        else if ( s[i] == '-' ){

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            st.push(op1 - op2);

        }

        else if ( s[i] == '*' ){

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            st.push(op1 * op2);

        }

        else if ( s[i] == '/' ){

            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            st.push(op1 / op2);

        }

    }

    return st.top();

}

int main(){

    string expression = "-+7*45+20";

    cout<<Prefixcalculate(expression);

    return 0;

}