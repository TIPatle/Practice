#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int>);

void InsertatBottom( stack <int> &s , int element ){

    if ( s.empty() ){

        s.push(element);
        return ;

    }

    int ele = s.top();
    s.pop();

    InsertatBottom(s, element);
    s.push(ele);

}

void rev ( stack <int> &s ){

    if ( s.empty() )
        return ;

    int ele = s.top();
    s.pop();

    rev(s);

    InsertatBottom(s, ele);
    

}

stack<int> reverse ( stack <int> &s ){

    if ( s.empty() )
        return s;

    int element = s.top();
    s.pop();

    stack <int> rev = reverse(s);
    stack <int> helper;

    while (!rev.empty()){

        helper.push(rev.top());
        rev.pop();

    }

    rev.push(element);
    
    while ( !helper.empty() ){

        rev.push(helper.top());
        helper.pop();

    }

    return rev;

}

void printStack(stack <int> s){

    while ( !s.empty() ){

        cout<<s.top()<<" ";
        s.pop();

    }
 
}

int main(){

    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack(s);

    cout<<endl;

    //stack <int> p = reverse(s);
    rev(s);
    printStack(s);

    return 0;

}