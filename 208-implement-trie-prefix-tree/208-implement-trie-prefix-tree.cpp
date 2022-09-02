class TrieNode{
public:
    TrieNode *arr[26];
    bool end;
    
    TrieNode(){
        this->end = false;
        for(int i=0;i<26;i++){
            arr[i]=NULL;
        }
        
    }
};

class Trie {
public:
    
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* t = root;
        for(int i=0;i<word.size();i++){
            if(t->arr[word[i]-'a']==NULL){
                t->arr[word[i]-'a']=new TrieNode();
            }
            t = t->arr[word[i]-'a'];
        }
        t->end = true;
    }
    
    bool search(string word) {
        TrieNode* t = root;
        for(int i=0;i<word.size();i++){
            if(t->arr[word[i]-'a']==NULL)return false;
            t = t->arr[word[i]-'a'];
        }
        return t->end==true ;
    }
    
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for(int i=0;i<prefix.size();i++){
            if(t->arr[prefix[i]-'a']==NULL)return false;
            t = t->arr[prefix[i]-'a'];
        }
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */