#include <iostream>
#include <string>
using namespace std;

// Include your full Trie implementation here (from previous message)

class Node {
private:
    Node* v[26];
    bool flag = false;

public:
    bool containskey(char c) {
        return v[c - 'a'] != NULL;
    }

    void putkey(char c, Node* node) {
        v[c - 'a'] = node;
    }

    Node* getkey(char c) {
        return v[c - 'a'];
    }

    void setend() {
        flag = true;
    }

    bool isend() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i])) {
                node->putkey(word[i], new Node());
            }
            node = node->getkey(word[i]);
        }
        node->setend();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containskey(word[i])) return false;
            node = node->getkey(word[i]);
        }
        return node->isend();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containskey(prefix[i])) return false;
            node = node->getkey(prefix[i]);
        }
        return true;
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    cout << boolalpha;
    cout << "Search 'apple': " << trie->search("apple") << endl;     // true
    cout << "Search 'app': " << trie->search("app") << endl;         // false
    cout << "StartsWith 'app': " << trie->startsWith("app") << endl; // true

    trie->insert("app");
    cout << "Search 'app' after insert: " << trie->search("app") << endl; // true

    delete trie;
    return 0;
}
