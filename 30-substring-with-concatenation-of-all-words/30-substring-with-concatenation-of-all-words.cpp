class Solution {
public:
    int len;
    bool match(string t, unordered_map<string,int>w){
        // for(int j=0;j<t.size(); j+=len){
        //     string temp = t.substr(j,len);
        //     if(w.find(temp)!=w.end()){
        //         if(--w[temp]==-1) return false;
        //     }
        //     else return false;
        // }
        // return true;
        
        // or less optimal one below 
        
        vector<bool>dp(t.size()+1,0);
        dp[t.size()]=1;
        
        for(int i=t.size()-len;i>=0;i-=len){
            string temp=t.substr(i,len);
            if(w.find(temp)!=w.end() && w[temp]>0 &&(i+len)<=t.size() && dp[i+len]==1){
                dp[i]=1;
                w[temp]--;
            }else return false;
        }
        return dp[0];
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int window = words.size()*words[0].size();
        len = words[0].size();
        int i=0;
        vector<int>ans;
        unordered_map<string,int>mp;
        
        for(auto w:words){
            mp[w]+=1;
        }
        
        while(i<(s.size()-window+1)){
            if(match(s.substr(i,window),mp)){
                ans.push_back(i);
            }
            i++;
        }
        
        return ans;
    }
};