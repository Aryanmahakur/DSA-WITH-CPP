#include <iostream>
#include <string>
using namespace std;
class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == NULL)
                node->children[index] = new TrieNode();

            node = node->children[index];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (node->children[index] == NULL)
                return false;

            node = node->children[index];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (node->children[index] == NULL)
                return false;

            node = node->children[index];
        }

        return true;
    }
};
int main() {
    Trie trie;

    // Insert words
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    // Search complete words
    cout << "search(cat): " << trie.search("cat") << endl;   // 1
    cout << "search(car): " << trie.search("car") << endl;   // 1
    cout << "search(ca): " << trie.search("ca") << endl;     // 0
    cout << "search(cap): " << trie.search("cap") << endl;   // 0
    cout << "search(dog): " << trie.search("dog") << endl;   // 1
    cout << "search(do): " << trie.search("do") << endl;     // 0

    cout << endl;

    // Check prefixes
    cout << "startsWith(ca): " << trie.startsWith("ca") << endl;   // 1
    cout << "startsWith(car): " << trie.startsWith("car") << endl; // 1
    cout << "startsWith(do): " << trie.startsWith("do") << endl;   // 1
    cout << "startsWith(da): " << trie.startsWith("da") << endl;   // 0
    cout << "startsWith(z): " << trie.startsWith("z") << endl;     // 0

    return 0;
}