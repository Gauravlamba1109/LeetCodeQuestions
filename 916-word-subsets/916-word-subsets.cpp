class Solution {
public:
    vector<int> cnt(string w){
        vector<int>v(27);
        for(auto c:w){
            v[c-'a']++;
        }
        return v;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        
        vector<int>words2Superset(27,0);
        for(auto w : words2){ // we have to combine freq of words2 
            vector<int>v = cnt(w);
            for(int i=0;i<27;i++){
                words2Superset[i]=max(words2Superset[i],v[i]);
            }
        }
        
        for(auto w : words1){
            vector<int>v = cnt(w);
            bool flag = true;
            for(int i=0;i<27;i++){
                if(words2Superset[i]>v[i]){
                    flag=0; 
                    break;
                }
            }
            if(flag)
                ans.push_back(w);
        }
        return ans;
    }
};