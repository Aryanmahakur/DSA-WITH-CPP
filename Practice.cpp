#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        stack<int> s1;
        int index = 0;

        while (curr != nullptr) {
            s1.push(curr->val);
            index++;
            curr = curr->next;
        }

        curr = head;
        int flag = 0;

        for (int i = 0; i < index; i++) {
            if (flag == 0) {
                cout << curr->val << " ";
                curr = curr->next;
                flag = 1;
            }
            else if (flag == 1) {
                cout << s1.top() << " ";
                s1.pop();
                flag = 0;
            }
        }
    }
};

int main() {
    // Create: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    obj.reorderList(head);

    return 0;
}