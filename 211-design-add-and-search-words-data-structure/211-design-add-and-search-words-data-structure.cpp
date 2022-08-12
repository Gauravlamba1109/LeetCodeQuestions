struct trie{
    trie *child[26];
    bool end;
};

class WordDictionary {
private :
    trie *root;
public:
    WordDictionary() {
        root = new trie();  
    }
    
    void addWord(string word) {
        trie *t= root;
        for(int i=0;i<word.size();i++){
            if(t->child[word[i]-'a']==NULL){
                t->child[word[i]-'a']= new trie();
            }
            t=t->child[word[i]-'a'];
        }
        t->end=true;
    }
    bool search(string word){
        return search(word,0,root);
    }
    bool search(string& word,int l, trie*t){
        for(int i=l;word[i]&&t;i++){
            if(word[i]!='.'){
                t=t->child[word[i]-'a'];
            }else{
                trie* temp = t;
                for(int j=0;j<26;j++){
                    t = temp->child[j];
                    if(search(word,i+1,t)) return true;
                }
            }
        }
        return t&& t->end;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */