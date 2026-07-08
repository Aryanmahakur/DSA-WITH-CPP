#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        left=right=nullptr;
        data=val;
    }
};
void preorder(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(Node* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    preorder(root);
    inorder(root);
    postorder(root);
}