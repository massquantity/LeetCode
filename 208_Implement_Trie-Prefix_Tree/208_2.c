typedef struct TrieNode {
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
  for (int i = 0; i < strlen(word); i++) {
    int j = word[i] - 'a';
    if (!node->next[j]) {
      node->next[j] = trieCreate();
    }
    node = node->next[j];
  }
  node->isEnd = true;
}

struct TrieNode *searchPrefix(Trie *obj, char *word) {
  Trie *node = obj;
  for (int i = 0; i < strlen(word); i++) {
    int j = word[i] - 'a';
    if (!node->next[j]) return NULL;
    node = node->next[j];
  }
  return node;
}

bool trieSearch(Trie* obj, char * word) {
  struct TrieNode *node = searchPrefix(obj, word);
  return node != NULL && node->isEnd;
}

bool trieStartsWith(Trie* obj, char * prefix) {
  struct TrieNode *node = searchPrefix(obj, prefix);
  return node != NULL;
}

void trieFree(Trie* obj) {
  if (!obj) return;
  for (int i = 0; i < 26; i++) {
    if (obj->next[i] != NULL) {
      trieFree(obj->next[i]);
    }
  }
}
