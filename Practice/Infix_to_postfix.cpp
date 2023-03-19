#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int precidence ( char op ){

    switch (op){

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

void to_postfix ( string exp ){

    stack <char> st;

    for ( auto it : exp ){

        if ( it >= 'a' && it <= 'z' || it >= 'A'&& it <= 'Z' )
            cout<<it;

        else if ( it == '(' )
            st.push(it);

        else if ( it == ')' ){

            while ( st.top() != '(' ){

                cout<<st.top();
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

                        cout<<st.top();
                        st.pop();

                    }

                    st.push(it);

                }

            }


        }
 

    }

    while (!st.empty()){
        
        cout<<st.top();
        st.pop();

    }

}



int main(){

    string exp = "(A-B/C)*(A/K-L)";

    to_postfix(exp);

    return 0;

}