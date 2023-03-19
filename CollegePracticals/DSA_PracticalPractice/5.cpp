#include <iostream>

using namespace std;

class node {

    public:
        int data;
        node* left ;
        node* right;

        node( int val ){

            data = val;
            left = NULL;
            right = NULL;

        }

};

node* insertBst ( node* head , int val  ){

    if ( head == NULL )
        return new node(val);

    if ( head->data > val )
        head->left = insertBst(head->left, val);

    else if ( head->data < val )
        head->right = insertBst(head->right, val );

    return head;

}

bool search ( node* head , int key ){

    if ( head == NULL )
        return false;

    if ( head->data == key )
        return true;

    else if ( head->data > key )
        return search(head->left, key);

    return search(head->right, key );

}

int longest( node* head ){

    if ( head == NULL )
        return 0;

    int l = longest(head->left);
    int r = longest(head->right);

    return max(l, r) + 1;

}

int minimum ( node* head ){

    if ( head == NULL )
        return INT16_MAX ;

    if ( head ->left == NULL )      
        return head->data;

    return minimum(head->left);

}

int main(){

    node* root = NULL;

    int n;
    cin>>n;

    for ( int i = 0; i<n; i++ ){

        int val;
        cin>>val;

        root = insertBst(root, val);

    }

    cout<<longest(root)<<endl;

    cout<<minimum(root)<<endl;

    cout<<search(root, 6);


    return 0;

}