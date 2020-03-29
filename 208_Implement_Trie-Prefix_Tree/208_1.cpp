#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;

class Trie {
private:
    bool isEnd;
    Trie *next[26];
public:
    Trie() {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie *node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == nullptr)
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie *node = this;
        for (char c : word) {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c : prefix) {
            node = node->next[c - 'a'];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};


int main() {
    Trie *trie = new Trie();
    trie->insert("apple");
    cout << boolalpha;
    cout << trie->search("apple") << endl;
    cout << trie->startsWith("app") << endl;
}
