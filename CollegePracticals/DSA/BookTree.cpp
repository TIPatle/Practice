#include <iostream>

using namespace std;

class node{

    public:
        string data;
        node* subnode1;
        node* subnode2;
        node* subnode3;

        node(string name ){

            data = name;
            subnode1 = NULL;
            subnode2 = NULL;
            subnode3 = NULL;

        }


};

void printIndexPage ( node* head ){

    if ( head == NULL )
        return ;

    cout<<head->data<<endl;

    printIndexPage(head->subnode1);
    printIndexPage(head->subnode2);
    printIndexPage(head->subnode3);


}

int main(){

    // Book Name 
    node* book = new node("Harry Potter\n\t\t\t -----Tushar Patle");

    // Sections 
    book->subnode1 = new node("Sorcerer's Stone\n");
    book->subnode2 = new node("Chamber of Secrets\n");
    book->subnode3 = new node("Prisoner of Azkaban\n");

    // Chapters of each Sections
    book->subnode1->subnode1 = new node("Chapter 1");
    book->subnode1->subnode2 = new node("Chapter 2");
    book->subnode1->subnode3 = new node("Chapter 3");

    book->subnode2->subnode1 = new node("Chapter 1");
    book->subnode2->subnode2 = new node("Chapter 2");
    book->subnode2->subnode3 = new node("Chapter 3");

    book->subnode3->subnode1 = new node("Chapter 1");
    book->subnode3->subnode2 = new node("Chapter 2");
    book->subnode3->subnode3 = new node("Chapter 3");


    // Subchapters of every Chapter 
    book->subnode1->subnode1->subnode1 = new node("Subchapter 1.1");
    book->subnode1->subnode1->subnode2 = new node("Subchapter 1.2");
    book->subnode1->subnode1->subnode3 = new node("Subchapter 1.3\n");

    book->subnode1->subnode2->subnode1 = new node("Subchapter 2.1");
    book->subnode1->subnode2->subnode2 = new node("Subchapter 2.2");
    book->subnode1->subnode2->subnode3 = new node("Subchapter 2.3\n");

    book->subnode1->subnode3->subnode1 = new node("Subchapter 3.1");
    book->subnode1->subnode3->subnode2 = new node("Subchapter 3.2");
    book->subnode1->subnode3->subnode3 = new node("Subchapter 3.3\n");
//-----------------------------------------------------------------------------//
    book->subnode2->subnode1->subnode1 = new node("Subchapter 1.1");
    book->subnode2->subnode1->subnode2 = new node("Subchapter 1.2");
    book->subnode2->subnode1->subnode3 = new node("Subchapter 1.3\n");

    book->subnode2->subnode2->subnode1 = new node("Subchapter 2.1");
    book->subnode2->subnode2->subnode2 = new node("Subchapter 2.2");
    book->subnode2->subnode2->subnode3 = new node("Subchapter 2.3\n");

    book->subnode2->subnode3->subnode1 = new node("Subchapter 3.1");
    book->subnode2->subnode3->subnode2 = new node("Subchapter 3.2");
    book->subnode2->subnode3->subnode3 = new node("Subchapter 3.3\n");

//-----------------------------------------------------------------------------//

    book->subnode3->subnode1->subnode1 = new node("Subchapter 1.1");
    book->subnode3->subnode1->subnode2 = new node("Subchapter 1.2");
    book->subnode3->subnode1->subnode3 = new node("Subchapter 1.3\n");

    book->subnode3->subnode2->subnode1 = new node("Subchapter 2.1");
    book->subnode3->subnode2->subnode2 = new node("Subchapter 2.2");
    book->subnode3->subnode2->subnode3 = new node("Subchapter 2.3\n");

    book->subnode3->subnode3->subnode1 = new node("Subchapter 3.1");
    book->subnode3->subnode3->subnode2 = new node("Subchapter 3.2");
    book->subnode3->subnode3->subnode3 = new node("Subchapter 3.3\n");

    // Index Page of Book
    cout<<endl;
    printIndexPage(book);

    return 0;

}