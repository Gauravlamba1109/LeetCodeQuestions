class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        vector<int>dp(nums.size()+1,0);
        // max from curr pos is dp[currpos]
        
        priority_queue<pair<int,int>>q;
        q.push({nums.back(),nums.size()-1});
        
        dp[nums.size()-1]=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            while(q.size() && q.top().second>(i+k)) q.pop();
            dp[i]=nums[i] + q.top().first;
            q.push({dp[i],i});
        }
        
        return dp[0];
        
        
        
        
        
        
        
        
        
        
        
        // recursive + memo  ::: tle 
        // map<string,int>m;
        // return helper(nums,k,0,0,nums.size(),m);
    }
    
//     int helper(vector<int>&nums, int k,int score ,int pos,int n,map<string,int>&m){
//         if(pos>=n) return INT_MIN;
//         if(pos==n-1) return (score+nums[n-1]);
        
//         string t = to_string(score)+"."+to_string(pos);
//         if(m.find(t)!=m.end()) return m[t];
//         // can move to pos+1 to min(pos+k,n-1)
//         int ans = 0;
//         for(int i=pos+1;i<=min(pos+k,n-1);i++){
//             ans = max(ans,helper(nums,k,score+nums[pos],i,n,m));
//         }
//         m[t]=ans;
//         return m[t];
//     }
};