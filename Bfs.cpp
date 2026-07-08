#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void BFS(Node* root)
{
    if(root == nullptr)
        return;

    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left != nullptr)
            q.push(current->left);

        if(current->right != nullptr)
            q.push(current->right);
    }
}
int main()s
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "BFS Traversal: ";
    BFS(root);

    return 0;
}