#include <iostream>
#include <unordered_set>
using namespace std;

int main() {

    unordered_set<int> st;

    // Insert
    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(40);

    // Search
    unordered_set<int>::iterator it;

    it = st.find(20);

    if (it != st.end())
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // Delete
    st.erase(20);

    // Display
    for (unordered_set<int>::iterator it = st.begin(); it != st.end(); it++) {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}