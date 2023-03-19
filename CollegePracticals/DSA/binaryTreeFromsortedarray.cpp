#include <iostream>

using namespace std;

class node{

    public :
        int data;
        node* left;
        node* right;

        node( int val ){

            data = val;
            left = NULL;
            right = NULL;

        }

};

node* buildtree( node* root , int arr[], int start, int end  ){

    if ( start > end )
        return NULL;

    int mid = (start + end) / 2;

    if ( root == NULL )
        root = new node(arr[mid]);

    else if ( root->data > arr[mid] )
        root->left = buildtree(root->left, arr, start, end);

    else if ( root->data < arr[mid])
        root->right = buildtree(root->right, arr, start, end);

    root->left = buildtree(root->left, arr, start, mid-1);
    root->right = buildtree(root->right, arr, mid+1, end);

    return root;

}

void inorder(node* root ){

    if ( root == NULL )
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder ( node* root ){

    if ( root == NULL )
        return;

    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
    
}

int height( node* root ){

    if ( root == NULL )
        return 0;

    return max(height(root->left), height(root->right)) + 1;

}


int main(){

    int n;
    cin>>n;

    int arr[n];
    for ( int i = 0; i<n; i++ )
        cin>>arr[i];

    node* root = NULL;
    root = buildtree(root, arr, 0, n-1);

    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;

    cout<<"The Height of this Optimal binary tree made out of sorted array is "<<height(root) - 1<<"."<<endl;

    return 0;

}