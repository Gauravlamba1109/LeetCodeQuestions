for (int i = 0; i < word_len; i++)
{
k = word[i] - 'a';
cur = cur->children[k];
if (cur == NULL)
return false;
}
return cur->is_word;
}
​
// Returns if there is any word in the trie
// that starts with the given prefix.
bool startsWith(string prefix) {
int word_len = prefix.length();
int k = 0;
TrieNode *cur = root;
for (int i = 0; i < word_len; i++)
{
k = prefix[i] - 'a';
cur = cur->children[k];
if (cur == NULL)
return false;
}
return true;
}
​
private:
TrieNode* root;
};
​
// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");