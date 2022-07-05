class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        priority_queue<int>s;
        for(auto ele : nums){
            if(m.find(ele)!=m.end())continue;
            s.push(ele);
            m[ele]++;
        }
        int ans=0;
        while(!s.empty()){
            int start = s.top(); s.pop();
            int cnt=1;
            while(!s.empty() && s.top()==start-1){
                cnt++;
                start=start-1;
                s.pop();
            }
            ans=max(ans,cnt);
        }
        
        return ans;
    }
};