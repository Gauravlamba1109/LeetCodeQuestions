class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>st;
        
        for(auto ele : intervals){
            if(st.size()==0)st.push(intervals[0]);
            else{
                if(ele[0]<=st.top()[1]){
                    int t = st.top()[0];
                    int t2 = st.top()[1];
                    st.pop();
                    st.push({t,max(t2,ele[1])});
                }else st.push(ele);
            }
        }
        vector<vector<int>>ans;
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
//         sort(intervals.begin(),intervals.end());
        
//         vector<vector<int>>st;
//         st.push_back(intervals[0]);
//         for(int i=1;i<intervals.size();i++){
//             if(st[st.size()-1][1]>=intervals[i][0]){
//                 st[st.size()-1][1]=max(st[st.size()-1][1],intervals[i][1]);
//             }else{
//                 st.push_back(intervals[i]);
//             }
//         }
//         return st;
    }
};