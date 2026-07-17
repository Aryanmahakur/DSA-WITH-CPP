#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<int, string> mp;

    // Insert
    mp.insert(pair<int, string>(101, "Aryan"));
    mp.insert(pair<int, string>(102, "Rahul"));
    mp.insert(pair<int, string>(103, "Aman"));

    // Search
    unordered_map<int, string>::iterator it;

    it = mp.find(102);

    if (it != mp.end())
        cout << "Found : " << it->second << endl;
    else
        cout << "Not Found" << endl;

    // Delete
    mp.erase(102);

    // Display
    for (unordered_map<int, string>::iterator it = mp.begin();
         it != mp.end();
         it++) {

        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}