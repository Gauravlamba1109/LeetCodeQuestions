class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](vector<int>&a,vector<int>&b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        
        stack<vector<int>>st;
        // for(auto v : intervals)cout<<v[0]<<","<<v[1]<<" "; cout<<endl;
        
        for(auto ele: intervals){
            if(st.size()==0) st.push(ele);
            else{
                // if overlap
                if(st.size() && ele[0]>=st.top()[0] && st.top()[1]>=ele[1]){
                    continue;
                }
                // if not overlap
                st.push(ele);
            }
        }
        int ans = st.size();
        // cout<<endl;
        // while(st.size()){cout<<st.top()[0]<<","<<st.top()[1]<<" ";st.pop();}
        // cout<<" next "<<endl;
        return ans;
    }
};