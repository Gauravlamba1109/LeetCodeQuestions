class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>tans;
        he(ans,tans,s,0);
        return ans;
    }
    
    void he(vector<vector<string>>&ans,vector<string>tans,string s, int start){
        if(start>s.size())return ;
        if(start==s.size())
            ans.push_back(tans);
        else 
        {
            for(int i=start ; i<s.size() ;i++){
                string f= s.substr(start,i-start+1); //substr(start index, lenght )
                if(ispal(f)){
                    tans.push_back(f);
                    he(ans,tans,s,i+1);
                    tans.pop_back();
                }
            }
        }
    }
    
    bool ispal(string &st){
        int s=0;int e=st.size()-1;
        while(s<e){
            if(st[s++]!=st[e--]) return false;
        }
        return true;
    }
};