#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

class sinlylinkedlist {
public:
    node* head;
    node* head2;
    node* head3;
    sinlylinkedlist() {
        head = nullptr;
        head2=nullptr;
        head3=nullptr;
    }

    void insertAtEnd(int val) {
        node* newNode = new node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
    void insertAtEndhead2(int val) {
        node* newNode = new node(val);

        if (head2 == nullptr) {
            head2 = newNode;
            return;
        }

        node* temp = head2;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void createLoop(int pos) {
        if (head == nullptr) return;

        node* loopNode = nullptr;
        node* temp = head;
        int count = 1;

        while (temp->next != nullptr) {
            if (count == pos) {
                loopNode = temp;
            }
            temp = temp->next;
            count++;
        }

        temp->next = loopNode;
    }

    void detectloop() {
        node* slow = head;
        node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                cout << "Loop Detected\n";
                return;
            }
        }

        cout << "No Loop\n";
    }
    void delNthfromEnd(int pos){
     node* curr=head;
     int index=0;
     while(curr->next!=nullptr){
        index++;
        curr=curr->next;
     }
     node* curr2=head;
     
     node* del;
     if(index==pos-1){
        del=head;
        head=head->next;
         delete del;
        return;
     }
     while(index>pos){
        curr2=curr2->next;
          index--;
     };
     del=curr2->next;
     curr2->next=curr2->next->next;
     delete del;
   
    }
void merge() {
    node* curr1 = head;
    node* curr2 = head2;

    head3 = nullptr;
    node* tail = nullptr;   // ADDED

    while (curr1 != nullptr && curr2 != nullptr) {

        node* temp;         // ADDED

        if (curr1->data < curr2->data) {
            temp = curr1;   // ADDED
            curr1 = curr1->next;
        } else {
            temp = curr2;   // ADDED
            curr2 = curr2->next;
        }

        temp->next = nullptr;   // ADDED

        if (head3 == nullptr) {
            head3 = temp;
            tail = temp;        // ADDED
        } else {
            tail->next = temp;  // ADDED
            tail = temp;        // ADDED
        }
    }

    if (curr1 != nullptr) {
        tail->next = curr1;     // ADDED
    }

    if (curr2 != nullptr) {
        tail->next = curr2;     // ADDED
    }
}
    void display(){
        node* curr=head;
        while(curr!=nullptr){
            cout<<curr->data<<" ";
            curr=curr->next;
        }
        cout<<endl;
    }
};

int main() {
    sinlylinkedlist l;

    l.insertAtEnd(1);
    l.insertAtEnd(2);
    l.insertAtEnd(3);
    l.insertAtEnd(4);
    l.insertAtEnd(5);

    //l.createLoop(3);   // 5 points to node containing 3

   // l.detectloop();
   l.display();
   l.delNthfromEnd(3);
   l.display();
    return 0;
}