#include <iostream>

using namespace std;

class Tries{

    public:
        class node{

            public:
                bool end;
                node* next[26];

                node(){

                    end = false;
                    for ( int i = 0; i<26; i++ )
                        next[i] = NULL;

                }


        };

        node *t;
        Tries(){

            t = new node();

        }

        void insert( string word ){

            node* it = t;

            for ( auto s : word ){

                if ( it->next[s-'a'] == NULL )
                    it->next[s-'a'] = new node();

                it = it->next[s-'a'];

            }

            it->end = true;

        }

        bool search ( string word ){

            node* it = t;

            for ( auto s : word ){

                if ( it->next[s-'a'] == NULL )
                    return false;

                it = it->next[s-'a'];

            }

            return it->end;

        }


};


int main(){

    Tries* mytrie = new Tries();
    mytrie->insert("nayan"); 
    mytrie->insert("tushar");

    if (mytrie->search("madan"))
        cout<<"madan is found in trie"<<endl;

    else 
        cout<<"madan is not present in trie "<<endl; 


    if (mytrie->search("tushar"))

        cout<<"tushar is found in trie"<<endl;

    else 
        cout<<"tusharis not present in trie "<<endl; 


    return 0;

}