#include <iostream>

using namespace std;

class node{ 

    public:
        int data;
        node* next;

        node( int val ){

            data = val;
            next = NULL;

        }

};

node* InsertNode(node* &head, int n ){

    if ( head == NULL )
        return new node(n);

    node* newnode = new node(n);

    node* temp = head;

    while( temp->next != NULL ){

        temp = temp->next;

    }

    temp->next = newnode;

    return head;

}

node* reverseL(node* &head){

    if ( head == NULL )
        return NULL;

    node* prev = NULL;
    node* curr = head;
    node* next;

    while( curr != NULL ){

        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

    }

    return prev;

}

node* recurrsiveReverse( node* head ){

    if ( head == NULL )
        return NULL ;

    node* n = recurrsiveReverse(head->next);

    return InsertNode(n, head->data);

}

void Print(node* &head ){

    if ( head == NULL )
        return ;

    node* temp = head;

    while ( temp != NULL ){
        
        cout<<temp->data<<" ";
        temp = temp->next;

    }

}

int main(){

    int n;
    cin>>n;

    int val;
    node* head = NULL;
    for ( int  i = 0; i<n; i++ ){
        
        cin>>val;
        head = InsertNode(head, val);

    }

    Print(head);
    cout<<endl;

    node* x = recurrsiveReverse(head);
    Print(x);

    return 0;

}