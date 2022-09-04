class Trie{
public:
    Trie* child[26];
    bool end ;
    
    Trie(){
        for(int i=0;i<26;i++)this->child[i]=NULL;
        this->end = false;
    }
};

class WordDictionary {
public:
    Trie* root;
    
    WordDictionary() {
        root = new Trie();    
    }
    
    void addWord(string word) {
        Trie* node = root;
        for(int i=0;i<word.size();i++){
            if(node->child[word[i]-'a']==NULL){
                node->child[word[i]-'a']=new Trie();
            }
            node= node->child[word[i]-'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Trie* node = root;
        return helper(word,node,0);
    }
    
    bool helper(string& word, Trie* node, int i){
        if(node==NULL) return false;
        if(i==word.size())return node->end;
        
        if(word[i]!='.'){
            return helper(word,node->child[word[i]-'a'],i+1);
        }else{
            for(int j=0;j<26;j++){
                if(helper(word,node->child[j],i+1)){
                    return true;
                }
            }
        }
        
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */