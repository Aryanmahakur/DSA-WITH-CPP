#include<iostream>
using namespace std;
#include<string>
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

    void erase(string word) {
        eraseHelper(root, word, 0);
    }

private:

    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL)
                return true;
        }
        return false;
    }

    bool eraseHelper(TrieNode* node, string &word, int depth) {

        if (node == NULL)
            return false;

        // Reached end of word
        if (depth == word.size()) {

            if (!node->isEnd)
                return false;

            node->isEnd = false;

            return !hasChildren(node);
        }

        int index = word[depth] - 'a';

        if (eraseHelper(node->children[index], word, depth + 1)) {

            delete node->children[index];
            node->children[index] = NULL;

            return !node->isEnd && !hasChildren(node);
        }

        return false;
    }
};