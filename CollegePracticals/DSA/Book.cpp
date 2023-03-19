#include <iostream>
#include <queue>

using namespace std;

class node{

    public:

        string data;
        node* nodi[100];

        node( string val , int n){

            data = val;
            
    
        }


};

node* search ( node* root , string val ){

    if ( root == NULL )
        return NULL;

    if ( root->data == val )
        return root;

    for ( auto it : root->nodi)
    search(root->nodi)

}

void preorder( node* root ){

    if ( root == NULL )
        return ;

    cout<<root->data<<endl;
    

}

int main(){ 

    cout<<"Enter the Book Name :- ";

    string book_name;
    cin>> book_name;

    node* root = new node(book_name);

    cout<<"Enter the total of chapter in a book :- ";

    int n;
    cin>>n;

    string chapter[n];
    for ( int i = 0; i<n+1; i++ ){

        cin>>chapter[i];

    }

    root = insertt(root, chapter, n);



    preorder(root);

    return 0;

}