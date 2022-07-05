class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>m;
        for(auto ele : nums){
            m[ele]++;
        }
        int ans=0;
        
        for(auto it = m.begin() ; it!=m.end() ; it++){
            auto start = it->first;
            int cnt=1;
            
            it++;
            while( it!=m.end() & it->first==(start+1)){
                cnt++;
                start=start+1;
                it++;
            }
            it--;
            ans=max(ans,cnt);
        }
        
        return ans;
    }
};