#include <iostream>
#include<vector>
using namespace std;

class Node{
public:
    vector<Node*> next;
    bool end;

    Node(){
        next = vector<Node*>(26, NULL);
        end = false;
    }
};

class Trie{
private :
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* temp = root;
        for(auto &it : s){
            if(temp->next[it-'a'] == NULL){
                Node* node = new Node();
                temp->next[it-'a'] = node;
            }
            temp=temp->next[it-'a'];
        }
        temp->end = true;
    }
    bool search(string s){
        Node* temp = root;
        for(auto &it: s){
            if(temp->next[it-'a']==NULL){
                return false;
            }
            temp = temp->next[it-'a'];
        }
        return temp->end;
    }
    bool startsWith(string s){
        Node* temp = root;
        for(auto &it: s){
            if(temp->next[it-'a']==NULL){
                return false;
            }
            temp = temp->next[it-'a'];
        }
        return true;
    }
};

int main(){
    Trie t;

    return 0;
}