class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // nums[i]== nums[j]
        // i!=j
    
        priority_queue<pair<int,int>>pq;
        int i=0;
        for(auto e:nums){
            int t=0;
            int a=e;
            while(a){
                t+=a%10;
                a/=10;
            }
            pq.push({t,e});
            i++;
        }
        int ans=-1;
        while(pq.size()){
            pair<int,int> t = pq.top(); pq.pop();
            if(pq.size()>0 && t.first==pq.top().first){
                ans=max(t.second+pq.top().second,ans);
            }
            while(pq.size()>0 && pq.top().first==t.first)pq.pop();
        }
        return ans;
    }
};