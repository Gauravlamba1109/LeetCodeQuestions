bool search(const char* word, TrieNode* node) {
for (int i = 0; word[i] && node; i++) {
if (word[i] != '.') {
node = node -> children[word[i] - 'a'];
} else {
TrieNode* tmp = node;
for (int j = 0; j < 26; j++) {
node = tmp -> children[j];
if (search(word + i + 1, node)) {
return true;
}
}
}
}
return node && node -> word;
}
};
​
​
​