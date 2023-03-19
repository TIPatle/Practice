#include <iostream>
#include <queue>

using namespace std;

class node {

    public :
        int data;
        node* left ;
        node* right;

        node( int val ){

            data = val;
            left = NULL;
            right = NULL;

        }
    
};

void lvltravesalLevelwise(node* root ){

    if ( root == NULL )
        return ;

    queue <node*> q;
    q.push(root);
    q.push(NULL);

    while ( !q.empty() ){

        node* n = q.front();
        q.pop();

        if ( n != NULL ){

            cout<<n->data<<" ";

            if ( n->left != NULL )
                q.push(n->left);

            if ( n->right != NULL)
                q.push(n->right);

        }

        else if (!q.empty())
            q.push(NULL);

        if ( n == NULL )
            cout<<endl;

    }

}

void lvltravesal(node* root ){

    if ( root == NULL )
        return ;

    queue <node*> q;
    q.push(root);

    while ( !q.empty() ){

        node* n = q.front();
        q.pop();

        cout<<n->data<<" ";

        if ( n->left != NULL )
            q.push(n->left);

        if ( n->right != NULL)
            q.push(n->right);

    }

}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);    
    root->left->right = new node(5);    
    root->right->left = new node(6);    
    root->right->right = new node(7); 

    lvltravesal(root);
    cout<<endl<<endl;
    lvltravesalLevelwise(root);

}