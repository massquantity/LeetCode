class Trie:
    def __init__(self):
        self.next_ = [None for _ in range(26)]
        self.is_end = False

    def insert(self, word: str) -> None:
        node = self
        for w in word:
            i = ord(w) - ord('a')
            if not node.next_[i]:
                node.next_[i] = Trie()
            node = node.next_[i]
        node.is_end = True

    def search(self, word: str) -> bool:
        node = self
        for w in word:
            i = ord(w) - ord('a')
            if not node.next_[i]:
                return False
            node = node.next_[i]
        return node.is_end

    def startsWith(self, prefix: str) -> bool:
        node = self
        for w in prefix:
            i = ord(w) - ord('a')
            if not node.next_[i]:
                return False
            node = node.next_[i]
        return True
