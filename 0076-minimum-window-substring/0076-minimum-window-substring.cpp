class Solution {
public:
    string minWindow(string s, string t) {
        // count of all of t's in s's part 
        unordered_map<char,int>t_s_in_ss;
        
        // map containing t's
        unordered_map<char,int>t_s_in_ts;
        
        for(auto c: t)t_s_in_ts[c]++;
        
        int p1= 0;
        int p2= 0;
        
        int req=t_s_in_ts.size();
        
        int formed = 0;
        
        vector<int>ans={-1,0,0}; // window len , left , right
        
        
        while(p2<s.size()){
            char c = s[p2];
            int cnt = t_s_in_ss[c];
            t_s_in_ss[c]++;
            
           
            if(t_s_in_ts[c] && t_s_in_ss[c]==t_s_in_ts[c]) formed++;
            
            // desirable window found
            while( formed == req && p1<=p2 ){
                c = s[p1];
                
                // save latest
                if(ans[0]==-1 || (p2-p1+1)<ans[0]){
                    ans[0] = (p2-p1+1);
                    ans[1] = p1;
                    ans[2] = p2;
                }
                t_s_in_ss[s[p1]]--;
                
                // shrink 
                if(t_s_in_ts[c] && t_s_in_ss[c]<t_s_in_ts[c]) formed--;
                p1++;
            }
            
            // enlarge window
            p2++;
        }
        
        return ans[0]==-1?"": s.substr(ans[1],ans[2]-ans[1]+1);
        
    }
};