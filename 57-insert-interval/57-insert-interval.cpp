class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        stack<vector<int>>st;
        bool taken = false;
        if(intervals.size()==0) 
            return {newInterval};
        
        for(auto ele:intervals){
            if(ele[0]>=newInterval[0] && !taken){
                taken= true ; 
                
                // push interval into stack 
                if(st.size() && st.top()[1]>=newInterval[0])
                    st.top() = {st.top()[0],max(newInterval[1],st.top()[1])};
                else
                    st.push(newInterval); 
            
            }
            
            // push ele to stack  
            if(st.size() && st.top()[1]>=ele[0])
                st.top() = {st.top()[0],max(ele[1],st.top()[1])};
            else 
                st.push(ele);

        }
        
        if(!taken){ // the newInterval starts at end 
            if(st.size() && st.top()[1]>=newInterval[0])
                st.top() = {st.top()[0],max(newInterval[1],st.top()[1])};
            else 
                st.push(newInterval);
        }

        vector<vector<int>>ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};