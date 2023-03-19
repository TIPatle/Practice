#include <iostream>

using namespace std;

class node {

    public:

        int data;
        node* left ;
        node* right;

        node ( int val ){

            left = NULL;
            right = NULL;
            data = val;

        }

};

node* InsertInBinaryTree ( node* root , int data){

    if ( root == NULL )
        return new node(data);

    if ( root->data > data )
        root->left = InsertInBinaryTree(root->left, data);

    else if ( root->data < data )
        root->right = InsertInBinaryTree(root->right, data);

    return root;

}

int heightBinary( node* root ){

    if ( root == NULL )
        return 0;

    int l = heightBinary(root->left);
    int r = heightBinary(root->right);

    return ( max(l, r) + 1 );

}

void inorder ( node* root ){

    if ( root == NULL )
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

int main(){

    int n;
    cin>>n;

    int val;
    node* root = NULL;
    for ( int i = 0; i<n; i++){

        cin>>val;
        root = InsertInBinaryTree(root, val);

    }

    inorder(root);

    cout<<"\n"<<heightBinary(root) - 1;

    return 0;

}
