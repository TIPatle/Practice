#include <iostream>

using namespace std;

class node{

    public:
        int data;
        int height;
        node* left;
        node* right;

        node( int val , int h){

            data = val;
            height = h;
            left = NULL;
            right = NULL;


        }

};

node* leftrotate( node* root ){

    if ( root == NULL )
        return root;

    node* temp = root;
    node* n = temp->right;
    temp->right = n->left;
    n->left = temp;

    return n;

}

node* insert( node* root , int key ){

    if ( root == NULL )
        return root = new node(key, 0);

    if ( root->data > key )
        root->left = insert(root->left, key);

    else if ( root->data < key )
        root->right = insert(root->right, key);

    
    
    return root;

}

void inorder( node* root ){

    if ( root == NULL )
        return;

    inorder(root->left);
    cout<<root->data<<" "<<root->height<<"-->";
    inorder(root->right);

}

void preorder(node* root ){

    if ( root == NULL )
        return;

    cout<<root->data<<" "<<root->height<<"-->";
    preorder(root->left);
    preorder(root->right);

}

int main(){

    int n;
    cin>>n;

    node* root = NULL;

    for ( int i = 0; i<n; i++ ){

        int val;
        cin>>val;

        root = insert(root, val);

    }

    inorder(root);
    cout<<"NULL"<<endl;
    preorder(root);
    cout<<"NULL"<<endl;


    return 0;

}