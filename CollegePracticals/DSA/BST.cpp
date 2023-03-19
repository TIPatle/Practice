#include <iostream>
#include <climits>

using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;

        node ( int val ){

            data = val;
            left = NULL;
            right = NULL;

        }


};

node* insert ( node* root, int val ){

    if ( root == NULL )
        root = new node(val);

    else if ( root->data > val  )
        root->left = insert(root->left, val);

    else if ( root->data < val )
        root->right = insert(root->right, val);

    return root;

}

int LongestPathSumNode( node* root ){

    if ( root == NULL )
        return 0;

    int l = LongestPathSumNode(root->left);
    int r = LongestPathSumNode(root->right);

    return max(l, r) + 1;

}

int minValue( node* root ){

    if ( root == NULL ) 
        return INT_MAX;

    return min(min(minValue(root->left), minValue(root->right)), root->data);
    
}

node* search( node* root , int key ){

    if ( root == NULL )
        return NULL;

    if ( root->data == key )
        return root;

    else if ( root->data > key )
        return search(root->left, key);

    else if ( root->data < key )
        return search(root->right, key);

    return NULL;

}

int main(){

    node* root = NULL;

    cout<<"1. Insert"<<endl;
    cout<<"2. Longest Path Node Sum"<<endl;
    cout<<"3. Minimum Node value in BST"<<endl;
    cout<<"4. Search in BST"<<endl;
    cout<<"5. Exit"<<endl;


    while(1){

        cout<<endl<<"Enter Your Choice :- ";
        int n;
        cin>>n;

        switch (n){

            case 1:

                cout<<"Enter a value to insert in a tree :- ";
                int val;
                cin>>val;

                root = insert(root, val);

                break;

            case 2:
                cout<<"Number of nodes in longest path  :- "<<LongestPathSumNode(root)<<endl;
                break;
                
            case 3:
                cout<<"Minimum data value found in the tree :-"<<minValue(root)<<endl;
                break;

            case 4:
                int key;
                cout<<"Search a Value :- ";
                cin>>key;

                if ( search(root, key) != NULL )
                    cout<<"Key Found Successfully "<<endl;

                if ( !search(root, key)) 
                    cout<<"Key Not Found in a BST "<<endl;
                
                break;

            case 5:
                cout<<"Program Terminated Sucessfully";
                exit(0);

        }   

    }

    return 0;

}