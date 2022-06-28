class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size()==1) return 0;
        //longest unsorted subarray 
        priority_queue<int>q;
        int mi=0;
        for(int i=0;i<nums.size();i++){
            if(q.size()>0 && q.top()>nums[i]){
                mi = max(mi,i);
            }
            q.push(nums[i]);
        }
        
        int ma = nums.size()-1;
        priority_queue<int, vector<int>, greater<int> > p;
        for(int i=nums.size()-1;i>=0 ; i--){
            if(p.size()>0 && p.top()<nums[i]){
                ma = min(ma,i);
            }
            p.push(nums[i]);
        }
        // cout<<mi<<" "<<ma<<endl;
        if(ma>mi) return 0;
        int ans = mi-ma + 1;
        
        return ans;
    }
};

// 2,6,4,8,10,9,15
// . . | .  . |  . 
// . | . .  | .  .
    
    