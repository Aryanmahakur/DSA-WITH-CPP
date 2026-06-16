#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int value){
        data=value;
        next=nullptr;
    }
};
class singlylinkedlist{
    public:
    node* head;
    singlylinkedlist(){
        head=nullptr;
    }
    void insertatend(int value){
        node* newnode=new node(value);
        if(head==nullptr){
            head=newnode;
            return;
        }
        node* tempnode=head;
        while(tempnode->next!=nullptr){
            tempnode=tempnode->next;
        }
        tempnode->next=newnode;
        return;
    }
    void deleteanode(int value){
        node* newnode=new node(value);

        if(head==newnode){
            head=head->next;
            return;
        }
        node* tempnode=head;
        while(tempnode->next!=nullptr && tempnode->next->data!=value){
            tempnode=tempnode->next;
        }
        if(tempnode->next==nullptr){
            return;
        }
        node* del=tempnode->next;

        tempnode->next=tempnode->next->next;
        delete del;
        return;

    }
    void display(){
        node* temp=head;
        while(temp->next!=nullptr){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
    }
};
int main(){
    singlylinkedlist sl;
    sl.insertatend(10);
    sl.insertatend(20);
    sl.insertatend(30);
    sl.insertatend(40);
    sl.insertatend(50);
    sl.deleteanode(30);
    sl.display();
}