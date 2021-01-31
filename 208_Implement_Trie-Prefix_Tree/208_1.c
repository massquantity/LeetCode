typedef struct  TreiNode {
    struct TrieNode *next[26];
    bool isEnd;
} Trie;

Trie* trieCreate() {
    Trie *root = (Trie*)malloc(sizeof(Trie));
    memset(root, 0, sizeof(*root));
    root->isEnd = false;
    return root;
}

void trieInsert(Trie* obj, char * word) {
    Trie *node = obj;
    for (size_t i = 0; i < strlen(word); ++i) {
        int j = word[i] - 'a';
        if (!node->next[j]) {
            node->next[j] = trieCreate();
        }
        node = node->next[j];
    }
    node->isEnd = true;
}

bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    for (size_t i = 0; i < strlen(word); ++i) {
        int j = word[i] - 'a';
        if (!node->next[j]) return false;
        node = node->next[j];
    }
    return node->isEnd;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    for (size_t i = 0; i < strlen(prefix); ++i) {
        int j = prefix[i] - 'a';
        if (!node->next[j]) return false;
        node = node->next[j];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (!obj) return;
    for (size_t i = 0; i < 26; ++i) {
        if (obj->next[i] != NULL) {
            trieFree(obj->next[i]);
        }
    }
}
