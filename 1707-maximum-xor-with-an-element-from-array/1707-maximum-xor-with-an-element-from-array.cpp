class Solution {
public:
    
    struct Trie{
        bool end;
        Trie* child[2];
        
        // each node can have 2 child node for 0 and 1
        
        Trie(){
            for(int i=0;i<2;i++)child[i]=NULL;
            end = false;
        }
        
    };
    
    Trie* root;
    
    void insert(int ele){
        Trie* node = root;
        for(int i=31;i>=0;i--){// string from left to right 
            int bit = (ele>>i)&1; // set or not 
            if(node->child[bit]==NULL){
                node->child[bit]=new Trie();
            }
            node = node->child[bit];
        }
    }
    
    int getMaxXOR(int ele){
        if(root->child[0]==NULL && root->child[1]==NULL) return -1;
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
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>q;
        root = new Trie();
        for(int i=0;i<queries.size();i++){
            auto v = queries[i];
            q.push_back({v[1],v[0],i});
        }
        sort(q.begin(),q.end());
        sort(nums.begin(),nums.end());
        
        int j = 0;
        vector<int>res(queries.size());
        
        for(auto & p: q){
            int x = p[1];
            int thres = p[0];
            while(j<nums.size() && nums[j]<=thres){
                insert(nums[j++]);
            }
            res[p[2]]= getMaxXOR(x);
        }
        
        return res;
    }
};