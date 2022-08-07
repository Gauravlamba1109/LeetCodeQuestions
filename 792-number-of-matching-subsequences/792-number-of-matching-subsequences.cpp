class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // method 1
        // put every word in the map according to starting char 
        // iterate over each and del starting and put them again at corr pos 
        int ans=0;
        unordered_map<char,vector<string>>mp;
        
        for(auto c:s)mp[c]={};
    
        for(auto w:words){
            if(mp.find(w[0])!=mp.end())
                mp[w[0]].push_back(w);
        }
        
        for(int i=0;i<s.size();i++){
            char c = s[i];
            //trim all strings 
            int s = mp[c].size();
            vector<string>temp= mp[c];
            mp[c]={};
            for(int j=0;j<s;j++){
                if(temp[j]=="" )continue;                
                temp[j]=temp[j].substr(1);                    
                if(temp[j].size()==0){
                    ans++;
                }
                else {
                    if(mp.find(temp[j][0])!=mp.end()){
                        mp[temp[j][0]].push_back(temp[j]);
                    }
                }
            }
        }

        return ans;

        
        // method 2 -> 80% 57% 235ms; 
        // optimeised 
        // make note of indexes of all chars 
        // do a binary search to find each word 
        // what upper_bound do is it will look for 
        // the next char whose index is greater than or equal to x
        
//         vector<vector<int>>v(26);
//         int ans=0;
//         // fill v
//         for(int i=0;i<s.size();i++)
//             v[s[i]-'a'].push_back(i);
        
//         for(auto w:words){
//             int x=-1;
//             bool found = true;
            
//             for(auto c:w){
//                 // look for char c's index in v; 
//                 // the char's index we know has to be greater than prev char's index x 
//                 auto it = upper_bound(v[c-'a'].begin(),v[c-'a'].end(),x);
//                 if(it==v[c-'a'].end())found=false;
//                 else x=*it;
//             }
//             if(found)ans++;
//         }
        
//         return ans;
        
        
        
    /*
        // brute force
        int ans = 0;
        for(auto w:words){
            // see if w is pr in s 
            int i=0;
            int j=0;
            while(i<w.size() && j<s.size()){
                if(w[i]==s[j]){
                    i++; j++;
                }else j++;
            }
            if(i==w.size())ans++;
        }
        return ans;
    
    */
    }
};