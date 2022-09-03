class Trie{
public:
    Trie* child[2];
    bool end;
    
    Trie(){
        for(int i=0;i<2;i++)child[i]=NULL;
        end = false;
    }
};

class Solution {
public:
    Trie* root;
    
    void insertAll(vector<int>&nums){
        root = new Trie();
        for(auto ele : nums){
            // insert ele 
            Trie* node = root;
            for(int i=31;i>=0;i--){
                int bit = (ele>>i)&1;
                if(node->child[bit]==NULL){
                    node->child[bit]=new Trie();
                }
                node = node->child[bit];
            }
        }
    }
    int findinTrie(int ele){
        Trie* node = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int bit = (ele>>i)&1;
            
            if(node->child[!bit]!=NULL){ 
                node = node->child[!bit];
                ans = (ans|(1<<i));
            }
            else{ 
                node = node->child[bit];
            }
        }
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        insertAll(nums);
        int ans = 0;
        for(auto ele:nums){
            int t = findinTrie(ele);
            ans = max(ans,t);
        }
        
        return ans;
    }
};