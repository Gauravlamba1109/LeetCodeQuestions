class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        // just greater 
        
        stack<int>st;
        vector<int>ans;
        for(int i=t.size()-1; i>=0 ;i--){
            
            while(st.size()!=0 && t[st.top()]<=t[i]) 
                st.pop();

            if(st.size()==0)
                ans.push_back(0);
            else 
                ans.push_back(st.top()-i);
            
            st.push(i);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
   