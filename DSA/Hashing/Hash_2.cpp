// Print Vertical order of a binary tree

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class node {

    public:

        int data;
        node* left;
        node* right;

        node( int val ){

            data = val;
            left = NULL;
            right = NULL;

        }
    
};

void getverticalOrder(node* root, int hdis, map<int, vector<int>> &m){  //O(n logn)

    if ( root == NULL )
        return ;

    m[hdis].push_back(root->data); // (log n )

    getverticalOrder(root->left, hdis -1, m);  // ---- together ( N )
    getverticalOrder(root->right, hdis+1, m);  // ----

}

int main(){

    node* root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(6);

    map<int, vector<int>> m;
    int hdis = 0;

    getverticalOrder(root, hdis, m);
    
    for ( auto it : m ){

        for ( auto i : it.second)   
            cout<<i<<" ";

        cout<<endl;

    }

    return 0;

}