#include<iostream>
using namespace std;
#include<string>
class treenode{
    public:
    treenode* children[26];
    bool isend;
    treenode(){
         isend=false;
         for(int i=0;i<26;i++){
            children[i]=NULL;
         }
    }
 
};
class trie{
    public:
       treenode* root;
    trie(){
        root=new treenode();
    }
    void insert(string word){
        treenode* node=root;
        for(char c : word){
            int index=c-'a';
           if(node->children[index]==NULL){
            node->children[index]=new treenode();
            node=node->children[index];
           }
        }
        node->isend=true;
    }
};
bool search(string wor)